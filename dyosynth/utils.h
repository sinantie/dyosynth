#ifndef __UTILS_H__
#define __UTILS_H__

#include <Arduino.h>
#include <SoftwareSerial.h>

#define DEBUG true
#define RX_PIN 2
#define TX_PIN 3

void initSerial(bool is_arduino);
void debug(String msg);
void debug(int msg);

#endif