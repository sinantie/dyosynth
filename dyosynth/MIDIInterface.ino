
MIDI_CREATE_DEFAULT_INSTANCE();

void initMIDIInterface() {
  MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function
  MIDI.setHandleNoteOff(HandleNoteOff);  // Put only the name of the function
  // Initiate MIDI communications, listen to all channels (not needed with Teensy usbMIDI)
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void HandleNoteOn(byte channel, byte note, byte velocity) {
}

void HandleNoteOff(byte channel, byte note, byte velocity) {
}