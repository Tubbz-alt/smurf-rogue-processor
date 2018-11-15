/**
 *-----------------------------------------------------------------------------
 * Title         : SLAC Register Protocol (SRP) SmurfFrameCounter
 * ----------------------------------------------------------------------------
 * File          : SmurfFrameCounter.cpp
 * Author        : Ryan Herbst <rherbst@slac.stanford.edu>
 * Created       : 02/02/2018
 *-----------------------------------------------------------------------------
 * Description :
 *   SMURF frame counter 
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

#include <ctime>

#include "SmurfFrameCounter.h"

//! Setup class in python
void SmurfFrameCounter::setup_python() {
   bp::class_<SmurfFrameCounter, SmurfFrameCounterPtr, bp::bases<ris::Master,ris::Slave>, boost::noncopyable >("SmurfFrameCounter",bp::init<>());
}

//! Creator with version constant
SmurfFrameCounter::SmurfFrameCounter( ) : ris::Master(), ris::Slave() { 
   count = 1;
   memset(input, 0, frameSize);
   memset(output, 0, frameSize);

   queue_.setThold(queueDepth);

   log_ = rogue::Logging::create("SmurfFrameCounter");

   // Start read thread
   thread_ = new boost::thread(boost::bind(&SmurfFrameCounter::runThread, this));
}

//! Deconstructor
SmurfFrameCounter::~SmurfFrameCounter() {
}

//! Accept a frame from master
void SmurfFrameCounter::acceptFrame ( ris::FramePtr frame ) {

   rogue::GilRelease noGil;

   // FIFO is full, drop frame
   if ( queue_.busy()  ) {
      return;
   }

   // Append to buffer
   queue_.push(frame);
}

void SmurfFrameCounter::frameToBuffer( ris::FramePtr frame, uint8_t * const buffer) {
   ris::Frame::BufferIterator src;
   uint8_t *dst = buffer;

   for (src=frame->beginBuffer(); src != frame->endBuffer(); ++src) {
      dst = std::copy((*src)->begin(), (*src)->endPayload(), dst);
   }

}

void SmurfFrameCounter::processFrame( ris::FramePtr frame ) {
   uint32_t size;
   uint32_t frameCounter;

   ris::FrameLockPtr lock = frame->lock();

   size = frame->getPayload();

   if ( (size != frameSize) || (frame->getError()) || (frame->getFlags() & 0x100) ) {
      //process old frame
   } else {
      frameToBuffer(frame, &input[0]); 
   }

   std::copy(&input[0], &input[headerSize], output);

// process frame:

   return;
}

//! Thread background
void SmurfFrameCounter::runThread() {
   ris::FramePtr frame;
   uint32_t prevFrameNumber;
   uint32_t frameNumber;
   uint32_t prevNanoSeconds;
   uint32_t nanoSeconds;
   uint32_t prevSeconds;
   uint32_t seconds;
   int32_t diffNanoSeconds;
   int32_t diffSeconds;
   std::time_t time;
   std::tm* now;

   log_->logThreadId();

   try {
      while(1) {
         frame = queue_.pop();
         processFrame( frame );

         prevFrameNumber = frameNumber;
         frameNumber     = *((uint32_t *)(input + frameCounterOffset)); 

         prevNanoSeconds = nanoSeconds; 
         nanoSeconds     = *((uint32_t *)(input + nanoSecondsOffset)); 

         prevSeconds     = seconds; 
         seconds         = *((uint32_t *)(input + secondsOffset)); 

         diffNanoSeconds = nanoSeconds - prevNanoSeconds;
         diffSeconds     = seconds - prevSeconds;

         if (diffNanoSeconds < 0 ) {
             diffNanoSeconds += 1e9;
             diffSeconds--;
         }

         // frame should increment by 1
         if( ++prevFrameNumber != frameNumber ) {
            time = std::time(0);
            now  = std::localtime(&time);
            std::cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << "  ";
            std::cout << (now->tm_hour) << ':' << (now->tm_min) << ':' << (now->tm_sec) << "   --  ";
            std::cout << "Got frame number " << frameNumber << ", should've got " << prevFrameNumber;
            std::cout << ".  Missing " << frameNumber-prevFrameNumber+1 << " frames.\n";

            std::cout << "Time difference s:ns  --  " << diffSeconds << ":" << diffNanoSeconds << "\n";
         }
         else if( (diffSeconds != 0) || (diffNanoSeconds >  500000) ) { //4kHz smurf rate 250000ns/frame
            std::cout << "Missed trigger - time difference s:ns  --  " << diffSeconds << ":" << diffNanoSeconds << "\n";
         }
      }
   } catch (boost::thread_interrupted&) { }
}

BOOST_PYTHON_MODULE(SmurfFrameCounter) {
   PyEval_InitThreads();
   try {
      SmurfFrameCounter::setup_python();
   } catch (...) {
      printf("Failed to load module. import rogue first\n");
   }
   printf("Loaded SMuRF Frame Counter\n");
};
