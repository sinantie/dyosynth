#ifndef __PRESET_H__
#define __PRESET_H__

#include <Arduino.h>
#include "synth_config.h"
#include "utils.h"

class Preset {    
  private:
    // Preset Parameters
    inline static uint8_t portamento_rate;
    inline static bool polyphonic;

    // Osc's parameters
    inline static uint8_t control_1;
    inline static uint8_t control_2;
    inline static uint8_t mix_osc1;
    inline static uint8_t mix_osc2;  
    inline static WAVE_TYPE wave_osc1;
    inline static WAVE_TYPE wave_osc2;
    inline static int oct_osc2;

    // Amp ADSR Parameters
    inline static uint8_t amp_attack;
    inline static uint8_t amp_decay;
    inline static uint8_t amp_sustain;
    inline static uint8_t amp_release;
    inline static bool amp_env_reset;

    // Filter Parameters
    inline static FILTER_TYPE filter;        
    inline static uint8_t filter_cutoff;    
    inline static uint8_t filter_resonance;
    inline static uint8_t filter_env_mod_percent;
    
    // Filter ADSR Parameters
    inline static uint8_t filter_attack;
    inline static uint8_t filter_decay;
    inline static uint8_t filter_sustain;
    inline static uint8_t filter_release;
    inline static bool filter_env_reset;
    
  public:    
    Preset();
    void loadPreset(int values[]);
    String toString();
    
    static void setPortamentoRate(uint8_t value) {portamento_rate = value;}
    static uint8_t getPortamentoRate() {return portamento_rate;}

    static void setFilter(FILTER_TYPE value) {filter = value;}
    static void nextFilterValue() {
      uint8_t cur_index = filter;
      filter = FILTER_IDS[(cur_index + 1) % NUM_OF_FILTER_TYPES];      
    }
    static FILTER_TYPE getFilter() {return filter;}
    static void setFilterCutoff(uint8_t value) {filter_cutoff = value;}
    static uint8_t getFilterCutoff() {return filter_cutoff;}
    static void setFilterResonance(uint8_t value) {filter_resonance = value;}
    static uint8_t getFilterResonance() {return filter_resonance;}
    static void setFilterEnvModPercent(uint8_t value) {filter_env_mod_percent = value;}
    static uint8_t getFilterEnvModPercent() {return filter_env_mod_percent;}

    static void setFilterAttack(uint8_t value) {filter_attack = value;}
    static uint8_t getFilterAttack() {return filter_attack;}
    static void setFilterDecay(uint8_t value) {filter_decay = value;}
    static uint8_t getFilterDecay() {return filter_decay;}
    static void setFilterSustain(uint8_t value) {filter_sustain = value;}
    static uint8_t getFilterSustain() {return filter_sustain;}
    static void setFilterRelease(uint8_t value) {filter_release = value;}
    static uint8_t getFilterRelease() {return filter_release;}

};

#endif