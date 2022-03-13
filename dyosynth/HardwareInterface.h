#ifndef __HARDWARE_INTERFACE_H__
#define __HARDWARE_INTERFACE_H__
/*
 * Hardware (buttons, pots) helper methods.
 * @sinantie based on code from Aciduino project (http://midilab.co/aciduino/) 
 */

#include <Arduino.h>
#include <MozziGuts.h>
#include "hardware_config.h"

// hardware-oriented pot data
class HardwarePot {
  private:
    uint8_t id;
    uint8_t pin;
    int value;
    bool lock;

    uint16_t _analogRead();

  public:
    HardwarePot();
    HardwarePot(uint8_t id, uint8_t pin);
    uint8_t getId();
    uint8_t getPin();
    int getValue();    
    void setValue(int state);    
    void setLockState(bool lock);
    bool isLocked();        
};

// hardware-oriented button data
class HardwareButton {
  private:
    uint8_t id;
    uint8_t pin;
        
  public:
    HardwareButton();
    HardwareButton(uint8_t id, uint8_t pin);
    uint8_t getPin();        
    bool isPressed();
};

class HardwareInterface {
  private:
    HardwarePot* _pots[NUM_OF_POTS];
    HardwareButton* _buttons[NUM_OF_BUTTONS];
    

  public:
    HardwareInterface();    
    void lockPotsState(bool lock);    
    bool isDoublePressed(uint8_t button1_id, uint8_t button2_id);
    HardwarePot* getPot(POT_HARDWARE_INTERFACE pot_id);
    HardwareButton* getButton(BUTTON_HARDWARE_INTERFACE button_id);    
};
#endif