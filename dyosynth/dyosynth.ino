/*
 * Mono/Poly-phonic synthesizer for Arduino and Mozzi. 
 * @sinantie
 */

#include "hardware_config.h"
#include "synth_config.h"
#include <MIDI.h>
#include <MozziGuts.h>
#include <mozzi_midi.h>
#include <Oscil.h>
#include <ADSR.h>


void setup() {
  // init LED display interface
  initDisplayLedInterface();
  // init MIDI interface
  initMIDIInterface();
  // init User Interface, aka Switches (Buttons) and Pots
  // TODO
}

void loop() {
  // put your main code here, to run repeatedly:

}
