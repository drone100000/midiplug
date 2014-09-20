#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MIDIParameter {
private:
    String _name;
    int  _value;
    int    _steps;

public:
    MIDIParameter(String name, int steps);

    float getValue();
    void setValue(float val);

    int getMIDIValue();

    String getValueText();

    String getName();
    int getSteps();
};


class MIDICCParameter : public MIDIParameter {
private:
    int _ccSetting = 0;

public:
    float getSetting();
    void setSetting(float setting);
};

#endif