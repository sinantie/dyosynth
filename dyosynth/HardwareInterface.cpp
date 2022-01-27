/*
 * Hardware (buttons, pots) helper methods.
 * @sinantie based on code from Aciduino project (http://midilab.co/aciduino/) 
 */

#include "HardwareInterface.h"
#include "utils.h"

HardwareInterface::HardwareInterface() {
  // Buttons config
  _connectButton(GENERIC_BUTTON_1, GENERIC_BUTTON_1_PIN);
  _connectButton(GENERIC_BUTTON_2, GENERIC_BUTTON_2_PIN);
  _connectButton(GENERIC_BUTTON_3, GENERIC_BUTTON_3_PIN);
  _connectButton(GENERIC_BUTTON_4, GENERIC_BUTTON_4_PIN);
  _connectButton(GENERIC_BUTTON_5, GENERIC_BUTTON_5_PIN);

  // Pots config
  _connectPot(GENERIC_POT_1, GENERIC_POT_1_PIN);
  _connectPot(GENERIC_POT_2, GENERIC_POT_2_PIN);
  _connectPot(GENERIC_POT_3, GENERIC_POT_3_PIN);
  _connectPot(GENERIC_POT_4, GENERIC_POT_4_PIN);
  _connectPot(GENERIC_POT_5, GENERIC_POT_5_PIN);
}

void HardwareInterface::_connectPot(uint8_t pot_id, uint8_t pot_pin) {
  _pot[pot_id].pin = pot_pin;
  // get first state data
  _pot[pot_id].state = _analogRead(_pot[pot_id].pin);
  // _pot[pot_id].lock = true;
}

void HardwareInterface::_connectButton(uint8_t button_id, uint8_t button_pin) {
  _button[button_id].pin = button_pin;
  // use internal pullup for buttons
  pinMode(_button[button_id].pin, INPUT_PULLUP);
  // get first state data
  // _button[button_id].state = digitalRead(_button[button_id].pin);
}

void HardwareInterface::lockPotsState(bool lock) {
  for (uint8_t i = 0; i < NUM_OF_POTS; i++) {
    _pot[i].lock = lock;
  }
}

bool HardwareInterface::isPressed(uint8_t button_id) {
  bool current_value = digitalRead(_button[button_id].pin);
  bool prev_value = _button[button_id].state;
  _button[button_id].state = current_value;
  debug("Button " + String(button_id) + " was pressed");

  // using internal pullup pressed button goes LOW
  return current_value != prev_value && current_value == LOW;
}

bool HardwareInterface::isDoublePressed(uint8_t button1_id, uint8_t button2_id) {
  bool value1, value2;

  value1 = digitalRead(_button[button1_id].pin);
  value2 = digitalRead(_button[button2_id].pin);

  // using internal pullup pressed button goes LOW
  if (value1 == LOW && value2 == LOW) {
    _button[button1_id].state = LOW;
    _button[button2_id].state = LOW;
    return true;
  }
  return false;  
}

uint16_t HardwareInterface::_analogRead(uint8_t pot_id) {
  // The Mozzi implementation for AnalogRead is a faster, non-blocking, bounded (0-1023) function
  // return mozziAnalogRead(_pot[pot_id].pin);
  return analogRead(_pot[pot_id].pin);
}

uint16_t HardwareInterface::getPotValue(uint8_t pot_id) {
  uint16_t current_value = _analogRead(pot_id);
  uint16_t previous_value = _pot[pot_id].state;
  
  // a lock system to not mess with some data (pots are terrible for some kind of user interface data controls)
  if ( _pot[pot_id].lock) {
    // user needs to move 1/8 of total adc range to get pot unlocked
    if ( abs(current_value - previous_value) < MIN_POT_CHANGE ) {
      return -1;
    }
  }

  if ( abs(current_value - previous_value) >= POT_SENSITIVITY ) {
    _pot[pot_id].state = current_value;
    if ( _pot[pot_id].lock) {
      _pot[pot_id].lock = false;
    }
    debug("The value of " + String(pot_id) + " is: " + String(current_value));
    return current_value;    
  } 
  return -1;  
}
