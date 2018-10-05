% Filter coefficients
Fs = 4000;  % Sampling Frequency (Hz)
Fc = 90;    % Cutoff frequency (Hz)
FilterOrder = 6;
h = fdesign.lowpass('n,f3db', FilterOrder, Fc, Fs);
DesignMethod = 'butter';
Hd = design(h, DesignMethod);

fvtool(Hd, [ones(1,20)/20], 1, 'Fs',4000)
%%
channels    = 1024;
frame_in    = fi(randn(1,channels), 1, 32, 28, 'OverflowAction', 'Wrap');
reset       = false;
Structure   = coder.Constant('Direct form II transposed');
SOSMatrix   = coder.Constant(Hd.sosMatrix);
ScaleValues = coder.Constant(Hd.ScaleValues);


warning('off','CoderFoundation:builder:TMFIncompatibilityWarningMATLABCoder')
config_obj = coder.config('lib');
config_obj.GenCodeOnly = true;
config_obj.GenerateMakefile = true;
config_obj.GenerateReport = true;
config_obj.LaunchReport = true;
config_obj.SaturateOnIntegerOverflow = false;
config_obj.SupportNonFinite = false;
config_obj.EnableVariableSizing = false;
config_obj.FilePartitionMethod ='SingleFile';
config_obj.TargetLang = 'C++';
config_obj.PassStructByReference = true;

% Generate embeddable C code
codegen -config config_obj  process_frame_v0 -args {frame_in,reset,Structure,SOSMatrix,ScaleValues};
