#ifndef __SYNTH_CONFIG_H__
#define __SYNTH_CONFIG_H__

typedef enum {
  SAW, 
  SQUARE,
  SINE,
  TRIANGLE
} WAVE_TYPE;

typedef enum {
  LPF_24,
  LPF_12,
  BPF_12,
  HPF_12
} FILTER_TYPE;

static FILTER_TYPE FILTER_IDS[] = {
  LPF_24,
  LPF_12,
  BPF_12,
  HPF_12
};

#define NUM_OF_WAVE_TYPES 4
#define NUM_OF_FILTER_TYPES 4

#endif