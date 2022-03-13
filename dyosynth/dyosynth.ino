/*
 * Mono/Poly-phonic synthesizer for Arduino and Mozzi. 
 * @sinantie
 *
 * To upload using Arduino IDE on groovesizer board choose: 
 * 1. Board -> MiniCore -> ATmega328
 * 2. Clock -> External 16MHz
 * 3. Variant -> 328P/328PA
 * 4. Programmer -> USBasp (MiniCore)
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
Page* current_page;

void setup() {  
  // for debugging purposes only
  initSerial(true);
  
  // init LED display interface
  displayInterface = DisplayLedInterface();
  displayInterface.ledsOff();

  // init MIDI interface
  // midiController = MIDIController();
  // init User Interface, aka Switches (Buttons) and Pots
  hardwareInterface = HardwareInterface();  

  // // load default preset
  current_preset = Preset();
  current_preset.loadPreset(BASIC_SAW_MONO);
  debug("Default preset values:\n\n" + current_preset.toString());
  // // on startup always load Live Page as the current_page
  pageController = PageController(hardwareInterface);
  current_page = pageController.getPage(PAGE_FILTER);
  hardwareInterface.lockPotsState(true);  
}

void loop() {
  // displayInterface.showPage(PAGE_OSCS);  
  delay(1000);
  // displayInterface.showPage(PAGE_AMP_ADSR);
  // displayInterface.flashDisplay();
  if(pageController.isMenuButtonPressed()) {
    current_page = pageController.getNextPage(current_page);   
    debug("Moving to Page " + String(current_page->name));
    hardwareInterface.lockPotsState(true); 
  }
  pageController.processPageChanges(current_page);
  // delay(100);
  //debug("New preset values:\n\n" + current_preset.toString());
}
