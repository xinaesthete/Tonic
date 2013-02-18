//
//  FMDrone.h
//  TonicDemo
//
//  Created by Morgan Packard on 2/15/13.
//  Copyright (c) 2013 Morgan Packard. All rights reserved.
//



#ifndef TonicDemo_FMDrone_h
#define TonicDemo_FMDrone_h

#include "Synth.h"
#include "SineWave.h"
#include "Multiplier.h"
#include "Adder.h"
#include "FixedValue.h"
#include "RampedValue.h"

using namespace Tonic;

class FMDroneSynth : public Synth {
  

public:
  FMDroneSynth(){
    outputGen = SineWave().freq(
       RampedValue().target( registerMessage("baseFreq", 200) ).lengthMs(100)
      + (
          SineWave().freq( 2 * RampedValue().target( registerMessage("baseFreq") ) )
          * 10 * RampedValue().target(registerMessage("fmAmount", 1))
         )
    );
  }
  
  static SourceRegister<FMDroneSynth> reg;
};


SourceRegister<FMDroneSynth> FMDroneSynth::reg("FMDroneSynth");

#endif
