/**
 *-----------------------------------------------------------------------------
 * Title         : SMURF Stream Processor
 * ----------------------------------------------------------------------------
 * File          : streamProcessor.h
 * Author        : Mitch D'Ewart <mdewart@slac.stanford.edu>
 * Created       : 11/15/2018
 *-----------------------------------------------------------------------------
 * Description :
 *    SMURF frame counter
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
#ifndef __SMURF_PROCESSOR_H__
#define __SMURF_PROCESSOR_H__
#include <stdint.h>
#include <boost/thread.hpp>
#include <rogue/interfaces/stream/Master.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/Logging.h>

namespace bp  = boost::python;
namespace ris = rogue::interfaces::stream;

class SmurfFrameCounter : public rogue::interfaces::stream::Master,
             public rogue::interfaces::stream::Slave {

      rogue::LoggingPtr log_;

      static const unsigned queueDepth   = 100;

      static const unsigned frameSize    = 8320;
      static const unsigned headerSize   = 128;
      static const unsigned blockOffset0 = 128;

      static const unsigned nanoSecondsOffset  = 72;
      static const unsigned secondsOffset      = 76;
      static const unsigned frameCounterOffset = 84;

      //input/output contiguous buffers
      uint8_t input[frameSize];
      uint8_t output[frameSize];

      unsigned count;

      void frameToBuffer(boost::shared_ptr<rogue::interfaces::stream::Frame> frame, uint8_t * const buffer);

      void processFrame(boost::shared_ptr<rogue::interfaces::stream::Frame> frame);

      // Queue
      rogue::Queue<boost::shared_ptr<rogue::interfaces::stream::Frame>> queue_;

      // Transmission thread
      boost::thread* thread_;

      //! Thread background
      void runThread();

   public:

      //! Setup class in python
      static void setup_python();

      //! Creator
      SmurfFrameCounter();

      //! Deconstructor
      ~SmurfFrameCounter();

      //! Accept a frame from master
      void acceptFrame ( boost::shared_ptr<rogue::interfaces::stream::Frame> frame );

};

// Convienence
typedef boost::shared_ptr<SmurfFrameCounter> SmurfFrameCounterPtr;

#endif
