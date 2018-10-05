function frame_out = process_frame_v0(frame_in, reset, Structure, SOSMatrix, ScaleValues) %#codegen
   
   persistent h_filter

   if isempty(h_filter)
       h_filter = dsp.BiquadFilter(...
           'Structure',Structure,...
           'SOSMatrix',SOSMatrix,...
           'ScaleValues',ScaleValues);
   end
   

   
   if reset
       h_filter.reset;
       frame_out = fi(frame_in, 1, 32, 28, 'OverflowAction', 'Wrap');
   else
       % convert to floating
       frame_in_float = double(frame_in);
  

       % step filter, output quantized
       frame_out = fi(step(h_filter,frame_in_float), 1, 32, 28, 'OverflowAction', 'Wrap');
   end
end
