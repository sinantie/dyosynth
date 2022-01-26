#ifndef __PAGE_CONTROLLER_H__
#define __PAGE_CONTROLLER_H__

#include <Arduino.h>
#include <IntMap.h>
#include "hardware_config.h"
#include "page_config.h"
#include "HardwareInterface.h"
#include "preset.h"

static IntMap BYTE_MAP(0, 127, 0, ADC_RESOLUTION);
static IntMap OCT_MAP(-2, 2, 0, ADC_RESOLUTION);
static IntMap PERCENT_MAP(0, 100, 0, ADC_RESOLUTION);

class PagePot {
  public:
    POT_HARDWARE_INTERFACE pot;  
    IntMap* mapper;
    void (* setValueCallback)(uint8_t value);  
    uint8_t (* getValueCallback)(void);
    PagePot(POT_HARDWARE_INTERFACE pot, IntMap mapper);
    // PagePot(POT_HARDWARE_INTERFACE pot, IntMap mapper, void (* setValueCallback)(uint8_t value), uint8_t (* getValueCallback)(void));
    PagePot();
};

class Page {
  public:
    SYNTH_PAGE_NAME name;
    uint8_t page_pos;
    PagePot pots[4];  

    Page(SYNTH_PAGE_NAME name, uint8_t page_pos);
    Page();
};

class PageController {
  private:
    Page _pages[NUM_OF_PAGES];    

  public:
    BUTTON_HARDWARE_INTERFACE MENU_BUTTON = GENERIC_BUTTON_5;
    SYNTH_PAGE_NAME SYNTH_PAGE_ORDER[5] = {
      PAGE_LIVE,
      PAGE_OSCS,
      PAGE_AMP_ADSR,
      PAGE_FILTER,
      PAGE_FILTER_ADSR  
    };

    PageController();

    Page getNextPage(Page current_page);

    Page getPage(int page_position);

    void processPageChanges(Page page, HardwareInterface hardwareInterface);

    void loadPreset();

    void savePreset();
};

#endif