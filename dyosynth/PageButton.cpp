#include "PageButton.h"
#include "utils.h"

PageButton::PageButton(HardwareButton* button) {
  this->button = button;  
}

PageButton::PageButton() {

}

void PageButton::processChanges() {
    if(button->isPressed()) {
      nextValueCallback();
    }
}
// HardwareButton* PageButton::getButton() {
//   return this->button;
// }