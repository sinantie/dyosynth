#ifndef __PAGE_CONFIG_H__
#define __PAGE_CONFIG_H__

#define NUM_OF_PAGES 5

typedef enum {
  PAGE_LIVE,
  PAGE_OSCS,
  PAGE_AMP_ADSR,
  PAGE_FILTER,
  PAGE_FILTER_ADSR  
} SYNTH_PAGE_NAME;

#endif