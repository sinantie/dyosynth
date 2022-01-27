#ifndef __DISPLAY_LED_INTERFACE_H__
#define __DISPLAY_LED_INTERFACE_H__
/*
 * Visualisation methods using 2 series of 8 LEDs (total of 16) using 74HC595 encoders.
 *
 * @sinantie based on code from Groovesizer RED project (https://groovesizer.com/red/)
 */

#include <Arduino.h>
#include "page_config.h"

class DisplayLedInterface {
  private:
    byte _leds[2] = {
      0, 0
    };
    void _shiftOut(int dataPin, int clockPin, byte dataOut);

  public:    
    DisplayLedInterface();
    void ledsOff();
    void updateDisplay();
    void flashDisplay();
    void showValue(byte value);
    void showPage(SYNTH_PAGE_NAME page_name);
    void showPageParameters(SYNTH_PAGE_NAME page_name);
  };
#endif