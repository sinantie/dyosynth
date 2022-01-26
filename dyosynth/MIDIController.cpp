#include "MIDIController.h"

void MIDIController::initMIDIController() {
  MIDI_CREATE_DEFAULT_INSTANCE();
  MIDI.setHandleNoteOn(handleNoteOn);    // Put only the name of the function
  MIDI.setHandleNoteOff(handleNoteOff);  // Put only the name of the function
  // Initiate MIDI communications, listen to all channels (not needed with Teensy usbMIDI)
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void MIDIController::handleNoteOn(byte channel, byte note, byte velocity) {
}

void MIDIController::handleNoteOff(byte channel, byte note, byte velocity) {
}