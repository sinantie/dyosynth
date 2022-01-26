#ifndef __HARDWARE_INTERFACE_H__
#define __HARDWARE_INTERFACE_H__
/*
 * Hardware (buttons, pots) helper methods.
 * @sinantie based on code from Aciduino project (http://midilab.co/aciduino/) 
 */

#include <Arduino.h>
#include "hardware_config.h"

// hardware-oriented pot data
struct HARDWARE_POT {
  uint8_t pin;
  int state;
  bool lock = true;
};

// hardware-oriented button data
struct HARDWARE_BUTTON {
  uint8_t pin;
  bool state = LOW;
};

class HardwareInterface {
  private:
    HARDWARE_POT _pot[NUM_OF_POTS];
    HARDWARE_BUTTON _button[NUM_OF_BUTTONS];

    void _connectPot(uint8_t pot_id, uint8_t pot_pin);
    void _connectButton(uint8_t button_id, uint8_t button_pin);
    uint16_t _analogRead(uint8_t pot_id);

  public:
    void initHardwareInterface();
    void lockPotsState(bool lock);
    bool isPressed(uint8_t button_id);
    bool isDoublePressed(uint8_t button1_id, uint8_t button2_id);
    uint16_t getPotValue(uint8_t pot_id);
};
#endif