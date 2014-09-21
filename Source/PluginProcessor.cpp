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
MidiplugAudioProcessor::MidiplugAudioProcessor() :
    _channel(MIDIParameter("MIDI Channel", 15)),
    _program(MIDIParameter("MIDI Program", 127))
{
    for(int i = 0; i < 128; i++){
        MIDICCParameter param = MIDICCParameter("CC ", 127);
        param.setSetting(i);
        _ccParameters.insert(std::pair<int, MIDICCParameter>(i+numDefaultParams, param));
    }
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
    return 2 + _ccParameters.size();
}

MIDIParameter& MidiplugAudioProcessor::findMIDIParameter(int index){
    if(index == channelParam)
        return _channel;

    if(index == programParam)
        return _program;

    return _ccParameters.at(index);
}

float MidiplugAudioProcessor::getParameter (int index)
{
    return findMIDIParameter(index).getValue();
}

void MidiplugAudioProcessor::setParameter (int index, float newValue)
{
    if(index == channelParam)
        _channel.setValue(newValue);

    if(index == programParam){
        _program.setValue(newValue);
        _midiMessages.addEvent(_program.getMIDIMessage(_channel.getMIDIValue()), _midiMessages.getNumEvents());
    }

    if(_ccParameters.count(index) == 1) {
        MIDICCParameter& param = _ccParameters.at(index);
        param.setValue(newValue);
        _midiMessages.addEvent(param.getMIDIMessage(_channel.getMIDIValue()), _midiMessages.getNumEvents());
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
    return 1;
}

int MidiplugAudioProcessor::getCurrentProgram()
{
    return 1;
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
