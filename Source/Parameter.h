#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MIDIParameter {
protected:

    String     _name;
    int        _value; // MIDI Value
    int        _steps;

public:
    MIDIParameter(String name, int steps);

    float getValue();
    void setValue(float val);

    int getMIDIValue();
    void setMIDIValue(int val);

    MidiMessage getMIDIMessage(int channel);

    String getValueText();

    String getName();
    int getSteps();
};


class MIDICCParameter : public MIDIParameter {
private:
    int _ccSetting;

public:
    MIDICCParameter(String name, int steps);
    MidiMessage getMIDIMessage(int channel);

    float getSetting();
    void setSetting(float setting);
};

#endif