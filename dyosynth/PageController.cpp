#include "PageController.h"
#include "HardwareInterface.h"

PagePot::PagePot(POT_HARDWARE_INTERFACE pot, IntMap mapper) {
  this->pot = pot;
  this->mapper = &mapper;
}

/* Default constructor */
PagePot::PagePot() {
  PagePot(GENERIC_POT_1, BYTE_MAP);
}


Page::Page(SYNTH_PAGE_NAME name, uint8_t page_pos) {
  this->name = name;
  this->page_pos = page_pos;
}

Page::Page() {
  Page(PAGE_LIVE, 0);  
}

PageController::PageController() {
  // Filter Page
  // PAGE_FILTER pots
  Page filter_page = Page(PAGE_FILTER, 0);
  filter_page.pots[0] = PagePot(GENERIC_POT_1, BYTE_MAP);//, &Preset::setFilterCutoff, &Preset::getFilterCutoff);  
  filter_page.pots[0].setValueCallback = &Preset::setFilterCutoff;
  filter_page.pots[0].getValueCallback = &Preset::getFilterCutoff;
  _pages[PAGE_FILTER] = filter_page;
    
}

Page PageController::getNextPage(Page current_page) {
  uint8_t next_page_pos = current_page.page_pos + 1;
  if(next_page_pos == NUM_OF_PAGES) {
    next_page_pos = 0;
  }
  return this->getPage(next_page_pos); 
}

Page PageController::getPage(int page_position) {
  return _pages[page_position];
}

void PageController::processPageChanges(Page page, HardwareInterface hardwareInterface) {
  for(uint8_t i = 0; i < 1; i++) {
    uint16_t value = hardwareInterface.getPotValue(i);
    int mapped_value = (*page.pots[i].mapper)(value);
    page.pots[i].setValueCallback(mapped_value);
  }
}

void PageController::loadPreset() {

}

void PageController::savePreset() {

}