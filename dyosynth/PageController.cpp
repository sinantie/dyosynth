#include "PageController.h"
#include "HardwareInterface.h"
#include "hardware_config.h"
#include "utils.h"



Page::Page(SYNTH_PAGE_NAME name, uint8_t page_pos) {
  this->name = name;
  this->page_pos = page_pos;
}

Page::Page() {
  Page(PAGE_LIVE, 0);  
}

PageController::PageController() {

}

PageController::PageController(HardwareInterface hardwareInterface) {
  // Assign menu button
  menuButton = hardwareInterface.getButton(GENERIC_BUTTON_5);

  // Live Page  
  Page* live_page = new Page(PAGE_LIVE, 0);  
  // PAGE_LIVE pots
  // TODO
  _pages[PAGE_LIVE] = live_page;

  // Oscs Page  
  Page* oscs_page = new Page(PAGE_OSCS, 1);  
  // PAGE_OSCS pots
  // TODO
  _pages[PAGE_OSCS] = oscs_page;

  // Amp ADSR Page  
  Page* amp_adsr_page = new Page(PAGE_AMP_ADSR, 2);  
  // PAGE_AMP_ADSR pots
  // TODO
  _pages[PAGE_AMP_ADSR] = amp_adsr_page;

  // Filter Page  
  Page* filter_page = new Page(PAGE_FILTER, 3);
  // PAGE_FILTER pots
  filter_page->pots[0] = new PagePot(hardwareInterface.getPot(GENERIC_POT_1), BYTE_MAP);//, &Preset::setFilterCutoff, &Preset::getFilterCutoff);  
  filter_page->pots[0]->setValueCallback = &Preset::setFilterCutoff;
  filter_page->pots[0]->getValueCallback = &Preset::getFilterCutoff;

  filter_page->pots[1] = new PagePot(hardwareInterface.getPot(GENERIC_POT_2), BYTE_MAP);//, &Preset::setFilterCutoff, &Preset::getFilterCutoff);  
  filter_page->pots[1]->setValueCallback = &Preset::setFilterResonance;
  filter_page->pots[1]->getValueCallback = &Preset::getFilterResonance;

  filter_page->pots[2] = new PagePot(hardwareInterface.getPot(GENERIC_POT_3), PERCENT_MAP);//, &Preset::setFilterCutoff, &Preset::getFilterCutoff);  
  filter_page->pots[2]->setValueCallback = &Preset::setPortamentoRate;
  filter_page->pots[2]->getValueCallback = &Preset::getPortamentoRate;

  filter_page->pots[3] = new PagePot(hardwareInterface.getPot(GENERIC_POT_4), PERCENT_MAP);//, &Preset::setFilterCutoff, &Preset::getFilterCutoff);  
  filter_page->pots[3]->setValueCallback = &Preset::setFilterEnvModPercent;
  filter_page->pots[3]->getValueCallback = &Preset::getFilterEnvModPercent;

  //PAGE_FILTER buttons
  filter_page->buttons[0] = new PageButton(hardwareInterface.getButton(GENERIC_BUTTON_1));
  filter_page->buttons[0]->nextValueCallback = &Preset::nextFilterValue;

  _pages[PAGE_FILTER] = filter_page;
    
  // Filter ADSR Page  
  Page* filter_adsr_page = new Page(PAGE_FILTER_ADSR, 4);  
  // PAGE_FILTER_ADSR pots
  // TODO
  _pages[PAGE_FILTER_ADSR] = filter_adsr_page;
  
}

Page* PageController::getNextPage(Page* current_page) {  
  return this->getPage((current_page->page_pos + 1) % NUM_OF_PAGES);    
}

Page* PageController::getPage(int page_position) {
  return _pages[page_position];
}

bool PageController::isMenuButtonPressed() {
  return menuButton->isPressed();
}

void PageController::processPageChanges(Page* page) {
  for(uint8_t i = 0; i < 4; i++) {     
    if(page->pots[i] != NULL) {
      page->pots[i]->processChanges();
    }
    if(page->buttons[i] != NULL) {
      page->buttons[i]->processChanges();
    }    
  }  
  
}

void PageController::loadPreset(Preset preset, HardwareInterface hardwareInterface) {
  //  for(uint8_t i = 0; i < 1; i++) {

  //  }
}

void PageController::savePreset() {

}