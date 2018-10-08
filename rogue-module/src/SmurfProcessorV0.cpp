/**
 *-----------------------------------------------------------------------------
 * Title         : SmurfProcessorV0
 * ----------------------------------------------------------------------------
 * File          : SmurfProcessorV0.cpp
 * Author        : Mitch D'Ewart <mdewart@slac.stanford.edu>
 * Created       : 10/01/2018
 *-----------------------------------------------------------------------------
 * Description :
 *    SMuRF stream processor - performs filtering and downsampling
 *-----------------------------------------------------------------------------
 * This file is part of the rogue software platform. It is subject to 
 * the license terms in the LICENSE.txt file found in the top-level directory 
 * of this distribution and at: 
    * https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
 * No part of the rogue software platform, including this file, may be 
 * copied, modified, propagated, or distributed except according to the terms 
 * contained in the LICENSE.txt file.
 *-----------------------------------------------------------------------------
**/
#include <stdint.h>
#include <boost/thread.hpp>
#include <boost/make_shared.hpp>
#include <rogue/interfaces/stream/Master.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Frame.h>
#include <rogue/interfaces/stream/FrameLock.h>
#include <rogue/interfaces/stream/FrameIterator.h>
#include <rogue/interfaces/stream/Buffer.h>
#include <rogue/Logging.h>
#include <rogue/GilRelease.h>

#include "SmurfProcessorV0.h"
#include "process_frame_v0.h"

//! Setup class in python
void SmurfProcessorV0::setup_python() {
   bp::class_<SmurfProcessorV0, SmurfProcessorV0Ptr, bp::bases<ris::Master,ris::Slave>, boost::noncopyable >("SmurfProcessorV0",bp::init<>());
}

//! Creator with version constant
SmurfProcessorV0::SmurfProcessorV0( ) : ris::Master(), ris::Slave() { 
   count = 1;
   memset(input, 0, frameSize);
   memset(output, 0, frameSize);

   /* Initialize reentrant memory structures */
   process_frame_v0StackDataGlobal.pd = &c_process_frame_v0PersistentDat;

   process_frame_v0_initialize(&process_frame_v0StackDataGlobal);

   queue_.setThold(queueDepth);

   log_ = rogue::Logging::create("SmurfProcessorV0");

   // Start read thread
   thread_ = new boost::thread(boost::bind(&SmurfProcessorV0::runThread, this));
}

//! Deconstructor
SmurfProcessorV0::~SmurfProcessorV0() {
   process_frame_v0_terminate();
}

//! Accept a frame from master
void SmurfProcessorV0::acceptFrame ( ris::FramePtr frame ) {

   rogue::GilRelease noGil;

   // FIFO is full, drop frame
   if ( queue_.busy()  ) {
      return;
   }

   // Append to buffer
   queue_.push(frame);
}

void SmurfProcessorV0::frameToBuffer( ris::FramePtr frame, uint8_t * const buffer) {
   ris::Frame::BufferIterator src;
   uint8_t *dst = buffer;

   for (src=frame->beginBuffer(); src != frame->endBuffer(); ++src) {
      dst = std::copy((*src)->begin(), (*src)->endPayload(), dst);
   }

}

void SmurfProcessorV0::bufferToFrame( uint8_t * const buffer, ris::FramePtr frame ) {
   uint8_t *src = buffer;
   rogue::interfaces::stream::Frame::iterator iter = frame->beginRead();
   rogue::interfaces::stream::Frame::iterator  end = frame->endRead();
   while ( iter != end ) {
      //  Get contigous size
      auto size = iter.remBuffer();
   
      // Get the data pointer from current position
      auto *dest = iter.ptr();
   
      // Copy some data
      memcpy(dest, src, size);
   
      // Update destination pointer and source iterator
      src  += size;
      iter += size;
   }

}

void SmurfProcessorV0::processFrame( ris::FramePtr frame ) {
   uint32_t size;

   ris::FrameLockPtr lock = frame->lock();

   size = frame->getPayload();

   if ( (size != frameSize) || (frame->getError()) || (frame->getFlags() & 0x100) ) {
      //process old frame
   } else {
      frameToBuffer(frame, &input[0]); 
   }

   std::copy(&input[0], &input[headerSize], output);

// process frame:
//   int32 -> double
//   filter (6 order butterworth)
//   quantize back to int32, wrap
   process_frame_v0(&process_frame_v0StackDataGlobal, (const int32_t *) &input[blockOffset0], 0, (int32_t *) &output[blockOffset0]);

   bufferToFrame(&output[0], frame);

}

//! Thread background
void SmurfProcessorV0::runThread() {
   ris::FramePtr frame;

   log_->logThreadId();

   try {
      while(1) {
         frame = queue_.pop();
         processFrame( frame );
         if ( count == downsample ) {
            count = 1;
            sendFrame( frame );
         } else {
            count++;
         }
         boost::this_thread::interruption_point();
      }
   } catch (boost::thread_interrupted&) { }
}

BOOST_PYTHON_MODULE(SmurfProcessorV0) {
   PyEval_InitThreads();
   try {
      SmurfProcessorV0::setup_python();
   } catch (...) {
      printf("Failed to load module. import rogue first\n");
   }
   printf("Loaded SMuRF Processor\n");
};
