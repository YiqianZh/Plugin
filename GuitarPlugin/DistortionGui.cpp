/*
  ==============================================================================

    DistortionGui.cpp
    Created: 6 Jul 2020 10:47:52pm
    Author:  Ante

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DistortionGui.h"

//==============================================================================
DistortionGui::DistortionGui()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(600, 150);

    // TONE
    toneSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    toneSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&toneSlider);

    toneLabel.setText("Tone", juce::NotificationType::dontSendNotification);
    toneLabel.setJustificationType(juce::Justification::centredTop);
    toneLabel.attachToComponent(&toneSlider, false);

    // GAIN
    gainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&gainSlider);

    gainLabel.setText("Gain", juce::NotificationType::dontSendNotification);
    gainLabel.setJustificationType(juce::Justification::centredTop);
    gainLabel.attachToComponent(&gainSlider, false);

    // BLEND
    blendSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    blendSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&blendSlider);

    blendLabel.setText("Blend", juce::NotificationType::dontSendNotification);
    blendLabel.setJustificationType(juce::Justification::centredTop);
    blendLabel.attachToComponent(&blendSlider, false);

    // CLIPPING SELECTION
    clipMenu.addItem("atan", atanSoftClip);
    clipMenu.addItem("hard", hardClip);
    addAndMakeVisible(&clipMenu);

    clipMenuLabel.setText("Clipping function", juce::NotificationType::dontSendNotification);
    clipMenuLabel.setJustificationType(juce::Justification::centredTop);
    clipMenuLabel.attachToComponent(&clipMenu, false);

    // DISTORTION BYPASS
    addAndMakeVisible(&distortionBypass);

    distortionBypassLabel.setText("Bypass", juce::NotificationType::dontSendNotification);
    distortionBypassLabel.setJustificationType(juce::Justification::centred);
    distortionBypassLabel.attachToComponent(&distortionBypass, false);
}

DistortionGui::~DistortionGui()
{
}

void DistortionGui::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
}

void DistortionGui::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    toneSlider.setBounds(((getWidth() / 6) * 1) - 50, getHeight() / 2 - 40, 100, 100);
    gainSlider.setBounds(((getWidth() / 6) * 2) - 50, getHeight() / 2 - 40, 100, 100);
    blendSlider.setBounds(((getWidth() / 6) * 3) - 50, getHeight() / 2 - 40, 100, 100);
    clipMenu.setBounds(((getWidth() / 6) * 4) - 50, getHeight() / 2 - 15, 100, 30);
    distortionBypass.setBounds(((getWidth() / 6) * 5) - 50, getHeight() / 2 - 5, 100, 30);
}
