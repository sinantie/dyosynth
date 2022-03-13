#include "PagePot.h"
#include "utils.h"

PagePot::PagePot(HardwarePot* pot, IntMap mapper) {
  this->pot = pot;
  this->mapper = &mapper;
}

/* Default constructor */
PagePot::PagePot() {  
}

void PagePot::processChanges() {
    int value = pot->getValue();            
    if(!pot->isLocked()) {
      int mapped_value = value;//pot->mapper(value);
      setValueCallback(mapped_value);      
      pot->setLockState(true);       
    }
}

// HardwarePot* PagePot::getPot() {
//   return this->pot;
// }
