#ifndef __PAGE_CONTROLLER_H__
#define __PAGE_CONTROLLER_H__

#include <Arduino.h>
#include "hardware_config.h"
#include "page_config.h"
#include "HardwareInterface.h"
#include "preset.h"
#include "PagePot.h"
#include "PageButton.h"

class Page {
  public:
    SYNTH_PAGE_NAME name;
    uint8_t page_pos;
    PagePot* pots[4] = {};
    PageButton* buttons[4] = {};

    Page(SYNTH_PAGE_NAME name, uint8_t page_pos);
    Page();
};

class PageController {
  private:
    Page* _pages[NUM_OF_PAGES];    
    HardwareButton* menuButton;
  public:    
    SYNTH_PAGE_NAME SYNTH_PAGE_ORDER[5] = {
      PAGE_LIVE,
      PAGE_OSCS,
      PAGE_AMP_ADSR,
      PAGE_FILTER,
      PAGE_FILTER_ADSR  
    };

    PageController();    
    PageController(HardwareInterface hardwareInterface);
    Page* getNextPage(Page* current_page);
    Page* getPage(int page_position);
    bool isMenuButtonPressed();
    void processPageChanges(Page* page);
    void loadPreset(Preset preset, HardwareInterface hardwareInterface);
    void savePreset();
};

#endif