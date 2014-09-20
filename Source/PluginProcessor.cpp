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
    return findMIDIParameter(index).getValue();
}

void MidiplugAudioProcessor::setParameter (int index, float newValue)
{
    findMIDIParameter(index).setValue(newValue);
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
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        //        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
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
