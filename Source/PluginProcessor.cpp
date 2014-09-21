/*
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <utility>

//==============================================================================
MidiplugAudioProcessor::MidiplugAudioProcessor()
{
    _parameters.insert(std::pair<int, MIDIParameter>(channelParam, MIDIParameter("MIDI Channel", 15)));
    _parameters.insert(std::pair<int, MIDIParameter>(programParam, MIDIParameter("MIDI Program", 127)));
    _ccParameters.insert(std::pair<int, MIDICCParameter>(ccParam,    MIDICCParameter("CC ", 127)));
}

MidiplugAudioProcessor::~MidiplugAudioProcessor()
{
}

//==============================================================================
const String MidiplugAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int MidiplugAudioProcessor::getNumParameters()
{
    return _parameters.size() + _ccParameters.size();
}

MIDIParameter& MidiplugAudioProcessor::findMIDIParameter(int index){
    if(_parameters.count(index) == 1) {
        return _parameters.at(index);
    }
    return _ccParameters.at(index);
}

float MidiplugAudioProcessor::getParameter (int index)
{
    if(_parameters.count(index) == 1)
        return _parameters.at(index).getValue();
    else if(_ccParameters.count(index) == 1)
        return _ccParameters.at(index).getValue();
    return 0.0;
}

void MidiplugAudioProcessor::setParameter (int index, float newValue)
{
    if(_parameters.count(index) == 1){
        MIDIParameter& param = _parameters.at(index);
        param.setValue(newValue);
        _midiMessages.addEvent(param.getMIDIMessage(1), 1);

    } else if(_ccParameters.count(index) == 1){
        MIDICCParameter& param = _ccParameters.at(index);
        param.setValue(newValue);
        _midiMessages.addEvent(param.getMIDIMessage(1), 2);
    }
}

int MidiplugAudioProcessor::getMIDIParameter (int index)
{
    return findMIDIParameter(index).getMIDIValue();
}

void MidiplugAudioProcessor::setMIDIParameter (int index, int newValue)
{
    MIDIParameter param = findMIDIParameter(index);
    param.setMIDIValue(newValue);
    setParameterNotifyingHost(index, param.getValue());
}



const String MidiplugAudioProcessor::getParameterName (int index)
{
    return findMIDIParameter(index).getName();
}

const String MidiplugAudioProcessor::getParameterText (int index)
{
    return findMIDIParameter(index).getValueText();
}

int MidiplugAudioProcessor::getParameterNumSteps(int index) {
    return findMIDIParameter(index).getSteps();
}


const String MidiplugAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String MidiplugAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool MidiplugAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool MidiplugAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool MidiplugAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool MidiplugAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool MidiplugAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double MidiplugAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MidiplugAudioProcessor::getNumPrograms()
{
    return 0;
}

int MidiplugAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MidiplugAudioProcessor::setCurrentProgram (int index)
{
}

const String MidiplugAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void MidiplugAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MidiplugAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MidiplugAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MidiplugAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // flush audio outputs
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    midiMessages.clear();

    MIDIParameter channel = findMIDIParameter(channelParam);


    midiMessages.clear();
    _midiMessages.swapWith(midiMessages);
}

//==============================================================================
bool MidiplugAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MidiplugAudioProcessor::createEditor()
{
    return new MidiplugAudioProcessorEditor (*this);
}

//==============================================================================
void MidiplugAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MidiplugAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MidiplugAudioProcessor();
}
