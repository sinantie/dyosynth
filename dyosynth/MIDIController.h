#ifndef __MIDI_INTERFACE_H__
#define __MIDI_INTERFACE_H__

#include <Arduino.h>
#include <MIDI.h>

class MIDIController {

  public:
    MIDIController();
    static void handleNoteOn(byte channel, byte note, byte velocity);
    static void handleNoteOff(byte channel, byte note, byte velocity);
};

#endif