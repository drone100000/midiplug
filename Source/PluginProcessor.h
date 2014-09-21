/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Parameter.h"
#include <map>

//==============================================================================
/**
*/
class MidiplugAudioProcessor  : public AudioProcessor
{
    MIDIParameter _channel;
    MIDIParameter _program;

    std::map<int, MIDICCParameter> _ccParameters;

    MidiBuffer  _midiMessages;

public:
    enum Parameters
    {
        channelParam = 0,
        programParam,

        numDefaultParams
    };

    //==============================================================================
    MidiplugAudioProcessor();
    ~MidiplugAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    int getMIDIParameter (int index);
    void setMIDIParameter (int index, int newValue);

    MIDIParameter& findMIDIParameter(int index);

    const String getParameterName (int index);
    const String getParameterText (int index);

    int getParameterNumSteps(int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

    int lastUIWidth, lastUIHeight;

    //==============================================================================


private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiplugAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED