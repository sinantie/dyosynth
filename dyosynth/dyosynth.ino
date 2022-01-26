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
#include <MozziGuts.h>
#include <mozzi_midi.h>
#include <Oscil.h>
#include <ADSR.h>

HardwareInterface hardwareInterface = HardwareInterface();
DisplayLedInterface displayInterface = DisplayLedInterface();
MIDIController midiController = MIDIController();
PageController pageController = PageController();
Preset current_preset = Preset();
Page current_page;

void setup() {  
  // init LED display interface
  displayInterface.initDisplayLedInterface();
  // init MIDI interface
  midiController.initMIDIController();
  // init User Interface, aka Switches (Buttons) and Pots
  hardwareInterface.initHardwareInterface();

  // load default preset
  current_preset.loadPreset(BASIC_SAW_MONO);
  // on startup always load Live Page as the current_page
  current_page = pageController.getPage(PAGE_FILTER);  
}

void loop() {
  if(hardwareInterface.isPressed(pageController.MENU_BUTTON)) {
    current_page = pageController.getNextPage(current_page);    
  }
  pageController.processPageChanges(current_page, hardwareInterface);

}
