/**
 *-----------------------------------------------------------------------------
 * Title         : SMURF Stream Processor
 * ----------------------------------------------------------------------------
 * File          : streamProcessor.h
 * Author        : Mitch D'Ewart <mdewart@slac.stanford.edu>
 * Created       : 10/01/2018
 *-----------------------------------------------------------------------------
 * Description :
 *    SMURF AXI Stream processor
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

#include "process_frame_v0.h"

namespace bp  = boost::python;
namespace ris = rogue::interfaces::stream;

class SmurfProcessorV0 : public rogue::interfaces::stream::Master,
             public rogue::interfaces::stream::Slave {

      rogue::LoggingPtr log_;

      static const unsigned queueDepth   = 100;
      static const unsigned downsample   = 20;

      static const unsigned frameSize    = 4112;
      static const unsigned headerSize   = 16;
      static const unsigned blockOffset0 = 16;

      //input/output contiguous buffers
      uint8_t input[frameSize];
      uint8_t output[frameSize];

      unsigned count;

      process_frame_v0StackData      process_frame_v0StackDataGlobal;
      process_frame_v0PersistentData c_process_frame_v0PersistentDat;

      void bufferToFrame(uint8_t * const buffer, boost::shared_ptr<rogue::interfaces::stream::Frame> frame);

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
      SmurfProcessorV0();

      //! Deconstructor
      ~SmurfProcessorV0();

      //! Accept a frame from master
      void acceptFrame ( boost::shared_ptr<rogue::interfaces::stream::Frame> frame );

};

// Convienence
typedef boost::shared_ptr<SmurfProcessorV0> SmurfProcessorV0Ptr;

#endif

