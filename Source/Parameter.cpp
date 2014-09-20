#include "Parameter.h"

MIDIParameter::MIDIParameter(String name, int steps) {
    _name = name;
    _value = 0;
    _steps = steps;
}

float MIDIParameter::getValue() {
    Logger::writeToLog("getting " + getName() + "._value:" + std::to_string(this->_value));
    return ((float) this->_value);
}

void MIDIParameter::setValue(float val) {
    this->_value = (int) (val);
    Logger::writeToLog("setting " + getName() + "._value:" + std::to_string(this->_value));
}

int MIDIParameter::getMIDIValue() {
    return _value;
}

String MIDIParameter::getValueText() {
    String text = "VAL: " +  std::to_string(_value);
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