/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/

class DistortionProcessor;
class DelayProcessor;
class ReverbProcessor;

class GuitarPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    GuitarPluginAudioProcessor();
    ~GuitarPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getValueTreeState() { return state; }

    int numSamples;

private:
    juce::AudioProcessorValueTreeState state;

    std::unique_ptr<DistortionProcessor> distortionProcessor;
    std::unique_ptr<DelayProcessor> delayProcessor;
    std::unique_ptr<ReverbProcessor> reverbProcessor;

    bool bypassDistortion{ false };
    bool bypassDelay{ false };
    bool bypassReverb{ false };

    bool test = true;

    juce::dsp::ProcessorChain<> a;

    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GuitarPluginAudioProcessor)
};