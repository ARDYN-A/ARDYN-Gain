/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ArdynGainAudioProcessorEditor::ArdynGainAudioProcessorEditor (ArdynGainAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible(gainKnob = new Slider("Gain"));
    gainKnob->setSliderStyle(Slider::Rotary);
    gainKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    gain = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "gain", *gainKnob);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ArdynGainAudioProcessorEditor::~ArdynGainAudioProcessorEditor()
{
}

//==============================================================================
void ArdynGainAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::ghostwhite);

    g.setColour (Colours::black);
    g.setFont (15.0f);

    Rectangle<int> area = getLocalBounds();
    Rectangle<int> textArea = area.removeFromBottom(50);

    g.drawText("Gain", textArea, Justification::centred);
}

void ArdynGainAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    int border = 50;

    area.reduced(border);

    gainKnob->setBounds(area);
}
