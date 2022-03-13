/*
 * Hardware (buttons, pots) helper methods.
 * @sinantie based on code from Aciduino project (http://midilab.co/aciduino/) 
 */

#include "HardwareInterface.h"
#include "utils.h"

/* HardwarePot class*/

HardwarePot::HardwarePot() {

}

HardwarePot::HardwarePot(uint8_t id, uint8_t pin) {
  this->id = id;
  this->pin = pin;
  // get first state data
  this->value = _analogRead();
  this->lock = true;    
}

uint16_t HardwarePot::_analogRead() {
  // The Mozzi implementation for AnalogRead is a faster, non-blocking, bounded (0-1023) function
  // return mozziAnalogRead(this->pin);
  return analogRead(this->pin);
}

uint8_t HardwarePot::getId() {
  return this->id;
}

uint8_t HardwarePot::getPin() {
  return this->pin;
}


int HardwarePot::getValue() {    
  uint16_t current_value = _analogRead();
  uint16_t previous_value = this->value;    
  // debug(current_value);
  // debug(previous_value);
  
  // debug(val);
  // // a lock system to not mess with some data (pots are terrible for some kind of user interface data controls)
  // if (this->isLocked()) {
  //   // user needs to move 1/8 of total adc range to get pot unlocked
  //   if ( abs(current_value - previous_value) < MIN_POT_CHANGE ) {
  //     return previous_value;
  //   }
  // }

  if ( abs(current_value - previous_value) >= POT_SENSITIVITY ) {
    this->setValue(current_value);
    if (this->isLocked()) {
      this->setLockState(false);
    }
    // debug("The value of " + String(this->getId()) + " is: " + String(this->getValue()) + " and lock is: " + this->isLocked());
    return current_value;    
  } 
  return previous_value;  
}

void HardwarePot::setValue(int value) {
  this->value = value;
}

void HardwarePot::setLockState(bool lock) {
  this->lock = lock;
}

bool HardwarePot::isLocked() {
  return this->lock;
}


/* HardwareButton class*/

HardwareButton::HardwareButton() {

}

HardwareButton::HardwareButton(uint8_t id, uint8_t pin) {
  this->id = id;
  this->pin = pin;
  pinMode(this->pin, INPUT_PULLUP);
}

uint8_t HardwareButton::getPin() {
  return this->pin;
}


bool HardwareButton::isPressed() {
  // bool current_value = digitalRead(this->pin);
  // bool prev_value = this->state;  
  // if(current_value != prev_value) {
  //   this->setState(current_value);
  //   debug("Button " + String(this->id) + " was pressed");
  //   return true;
  // }
  // using internal pullup pressed button goes LOW
  if(digitalRead(this->pin) == LOW) {
    debug("Button " + String(this->id) + " was pressed");
    return true;
  }
  return false;
  
  // return current_value != prev_value && current_value == LOW;
}

/* HardwareInterface class*/

HardwareInterface::HardwareInterface() {
  // Buttons config
  _buttons[GENERIC_BUTTON_1] = new HardwareButton(GENERIC_BUTTON_1, GENERIC_BUTTON_1_PIN);
  _buttons[GENERIC_BUTTON_2] = new HardwareButton(GENERIC_BUTTON_2, GENERIC_BUTTON_2_PIN);
  _buttons[GENERIC_BUTTON_3] = new HardwareButton(GENERIC_BUTTON_3, GENERIC_BUTTON_3_PIN);
  _buttons[GENERIC_BUTTON_4] = new HardwareButton(GENERIC_BUTTON_4, GENERIC_BUTTON_4_PIN);
  _buttons[GENERIC_BUTTON_5] = new HardwareButton(GENERIC_BUTTON_5, GENERIC_BUTTON_5_PIN);
  
  // Pots config
  _pots[GENERIC_POT_1] = new HardwarePot(GENERIC_POT_1, GENERIC_POT_1_PIN);
  _pots[GENERIC_POT_2] = new HardwarePot(GENERIC_POT_2, GENERIC_POT_2_PIN);
  _pots[GENERIC_POT_3] = new HardwarePot(GENERIC_POT_3, GENERIC_POT_3_PIN);
  _pots[GENERIC_POT_4] = new HardwarePot(GENERIC_POT_4, GENERIC_POT_4_PIN);
  _pots[GENERIC_POT_5] = new HardwarePot(GENERIC_POT_5, GENERIC_POT_5_PIN);  
}

void HardwareInterface::lockPotsState(bool lock) {
  for (uint8_t i = 0; i < NUM_OF_POTS; i++) {
    _pots[i]->setLockState(lock);
  }
}

// bool HardwareInterface::isPressed(uint8_t button_id) {
//   HardwareButton* current_button = getButton(BUTTON_IDS[button_id]);
//   bool current_value = digitalRead(current_button->getPin());
//   bool prev_value = current_button->getState();
//   current_button->setState(current_value);
//   if(current_value != prev_value) {
//     debug("Button " + String(button_id) + " was pressed");
//   }

//   // using internal pullup pressed button goes LOW
//   return current_value != prev_value && current_value == LOW;
// }

bool HardwareInterface::isDoublePressed(uint8_t button1_id, uint8_t button2_id) {
  bool value1, value2;

  value1 = digitalRead((*_buttons[button1_id]).getPin());
  value2 = digitalRead((*_buttons[button2_id]).getPin());

  // using internal pullup pressed button goes LOW
  if (value1 == LOW && value2 == LOW) {
    // (*_buttons[button1_id]).setState(LOW);
    // (*_buttons[button2_id]).setState(LOW);
    return true;
  }
  return false;  
}

HardwarePot* HardwareInterface::getPot(POT_HARDWARE_INTERFACE pot_id) {
  // debug(_pots[pot_id].getPin());
  return _pots[pot_id];
}

HardwareButton* HardwareInterface::getButton(BUTTON_HARDWARE_INTERFACE button_id) {
  return _buttons[button_id];
}
