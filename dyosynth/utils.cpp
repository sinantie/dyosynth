#include "utils.h"

void debug(String msg) {
  if(DEBUG) {
    Serial.print(msg);
  }
}