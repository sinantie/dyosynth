#include "HardwareInterface.h"
#include <IntMap.h>

static IntMap BYTE_MAP(0, 127, 0, ADC_RESOLUTION);
static IntMap OCT_MAP(-2, 2, 0, ADC_RESOLUTION);
static IntMap PERCENT_MAP(0, 100, 0, ADC_RESOLUTION);

class PagePot {
  private:
    HardwarePot* pot;

  public:    
    IntMap* mapper;
    void (* setValueCallback)(uint8_t value);  
    uint8_t (* getValueCallback)(void);
    void processChanges();
    PagePot(HardwarePot* pot, IntMap mapper);
    // PagePot(HardwarePot* pot, IntMap mapper, void (* setValueCallback)(uint8_t value), uint8_t (* getValueCallback)(void));    
    PagePot();
};
