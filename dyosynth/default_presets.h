#ifndef __DEFAULT_PRESET_H__
#define __DEFAULT_PRESET_H__

#include "synth_config.h"

int BASIC_SAW_MONO[] = {
  // Preset Parameters
  0,        // portamento_rate (0)
  0,        // polyphonic (1)
  // Osc's parameters
  64,       // control_1 (2)
  0,        // control_2 (3)
  127,      // mix_osc1 (4)
  0,        // mix_osc2 (5)
  SAW,      // wave_osc1 (6)
  SINE,     // wave_osc2 (7) (NOT USED IN THIS PRESET)
  0,        // oct_osc2  (8) (NOT USED IN THIS PRESET)
  // Amp ADSR Parameters
  0,        // amp_attack (9)
  64,       // amp_decay  (10)
  127,      // amp_sustain (11)
  10,       // amp_release (12)
  1,        // amp_env_reset (13)
  // Filter Parameters
  LPF_24,   // filter (14)
  64,       // filter_cutoff (15)
  64,       // filter_resonance (16)
  50,       // filter_env_mod_percent (17)
  // Filter ADSR Parameters
  0,        // filter_attack (18)
  64,       // filter_decay (19)
  127,      // filter_sustain (20)
  10        //filter_release (21)
};
#endif