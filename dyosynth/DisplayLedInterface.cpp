/*
 * Visualisation methods using 2 series of 8 LEDs (total of 16) using 74HC595 encoders.
 *
 * @sinantie based on code from Groovesizer RED project (https://groovesizer.com/red/)
 */

#include "DisplayLedInterface.h"
#include "HardwareInterface.h"

void DisplayLedInterface::initDisplayLedInterface() {
  //define pin modes
  pinMode(ENCODER_LED_LATCH_PIN, OUTPUT);
  pinMode(ENCODER_LED_CLK_PIN, OUTPUT);
  pinMode(ENCODER_LED_DATA_PIN, OUTPUT);
}

void DisplayLedInterface::ledsOff() {
  _leds[0] = 0;
  _leds[1] = 0;
}

void DisplayLedInterface::updateDisplay() {
  digitalWrite(ENCODER_LED_LATCH_PIN, 0);
  //count up on GREEN LEDs
  this->_shiftOut(ENCODER_LED_DATA_PIN, ENCODER_LED_CLK_PIN, _leds[1]);
  //count down on RED LEDs
  this->_shiftOut(ENCODER_LED_DATA_PIN, ENCODER_LED_CLK_PIN, _leds[0]);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(ENCODER_LED_LATCH_PIN, 1);
}

void DisplayLedInterface::_shiftOut(int dataPin, int clockPin, byte dataOut) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i = 0;
  int pinState;
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);

  //for each bit in the byte myDataOutï¿½
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i = 7; i >= 0; i--) {
    digitalWrite(clockPin, 0);

    //if the value passed to dataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if (dataOut & (1 << i)) {
      pinState = 1;
    } else {
      pinState = 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(dataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(clockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);
  }

  //stop shifting
  digitalWrite(clockPin, 0);
}

void DisplayLedInterface::flashDisplay() {
  _leds[0] = B11111111;
  _leds[1] = B11111111;
  this->updateDisplay();
}

void DisplayLedInterface::showValue(byte value) {
  value -= 1;
  _leds[value / 8] = bitSet(_leds[value / 8], (value % 8));
}

void DisplayLedInterface::showPage(SYNTH_PAGE_NAME page_name) {
  switch (page_name) {
    case PAGE_LIVE:
      this->ledsOff();
      break;
    case PAGE_OSCS:
      this->showValue(1);
      break;
    case PAGE_AMP_ADSR:
      this->showValue(5);
      break;
  }
  this->updateDisplay();
}

void DisplayLedInterface::showPageParameters(SYNTH_PAGE_NAME page_name) {
  // TODO
}