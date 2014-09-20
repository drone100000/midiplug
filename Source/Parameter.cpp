#include "Parameter.h"

MIDIParameter::MIDIParameter(String name, int steps) {
    _name = name;
    _value = 0;
    _steps = steps;
}

float MIDIParameter::getValue() {
    return ((float) this->_value / _steps);
}

void MIDIParameter::setValue(float val) {
    this->_value = (int) (val * _steps);
}

int MIDIParameter::getMIDIValue() {
    return _value;
}

void MIDIParameter::setMIDIValue(int val) {
    _value = val;
}

String MIDIParameter::getValueText() {
    String text = std::to_string(getMIDIValue());
    return text;
}

String MIDIParameter::getName() {
    return _name;
}

int MIDIParameter::getSteps() {
    return _steps;
}


void MIDICCParameter::setSetting(float setting) {
    _ccSetting = setting;
}

float MIDICCParameter::getSetting() {
    return _ccSetting;
}