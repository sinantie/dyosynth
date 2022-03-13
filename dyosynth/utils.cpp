#include "utils.h"

SoftwareSerial swSerial(RX_PIN, TX_PIN);
bool is_arduino;

void initSerial(bool is_arduino_in) {
  is_arduino = is_arduino_in;
  if(!is_arduino_in) {
    pinMode(RX_PIN, INPUT);
    pinMode(TX_PIN, OUTPUT);
    swSerial.begin(9600);
  }
  else {
    Serial.begin(9600);
  }    
}

void debug(String msg) {
  if(DEBUG) {
    if (is_arduino) {
      Serial.println(msg);
    }
    else {
      swSerial.println(msg);
    }
  }
}

void debug(int msg) {
  if(DEBUG) {
    if (is_arduino) {
      Serial.println(String(msg));
    }
    else {
      swSerial.println(String(msg));
    }
  }
}