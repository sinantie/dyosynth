/*
 * Mono/Poly-phonic synthesizer for Arduino and Mozzi. 
 * @sinantie
 */

#include "hardware_config.h"
#include "synth_config.h"
#include "preset.h"
#include "default_presets.h"
#include "HardwareInterface.h"
#include "DisplayLedInterface.h"
#include "MIDIController.h"
#include "PageController.h"
#include "utils.h"
#include <MozziGuts.h>
#include <mozzi_midi.h>
#include <Oscil.h>
#include <ADSR.h>

HardwareInterface hardwareInterface;
DisplayLedInterface displayInterface;
MIDIController midiController;
PageController pageController;
Preset current_preset;
Page current_page;

void setup() {  
  // for debugging purposes only
  Serial.begin(9600);

  // init LED display interface
  displayInterface = DisplayLedInterface();
  // init MIDI interface
  midiController = MIDIController();
  // init User Interface, aka Switches (Buttons) and Pots
  hardwareInterface = HardwareInterface();  

  // load default preset
  current_preset = Preset();
  current_preset.loadPreset(BASIC_SAW_MONO);
  debug("Default preset values:\n\n" + current_preset.toString());
  // on startup always load Live Page as the current_page
  pageController = PageController();
  current_page = pageController.getPage(PAGE_FILTER);  
}

void loop() {
  if(hardwareInterface.isPressed(pageController.MENU_BUTTON)) {
    current_page = pageController.getNextPage(current_page);    
  }
  pageController.processPageChanges(current_page, hardwareInterface);
  delay(10);
  debug("New preset values:\n\n" + current_preset.toString());
}
