/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public juce::Component,
                       public juce::Button::Listener,
                       public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent (NewProjectAudioProcessor& p, juce::AudioProcessorValueTreeState& vts);
    ~MainComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    NewProjectAudioProcessor& processor;
    juce::AudioProcessorValueTreeState& valueTreeState;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextEditor> codeText;
    std::unique_ptr<juce::TextButton> compileButton;
    std::unique_ptr<juce::Slider> paramA;
    std::unique_ptr<juce::Label> paramLabel;
    std::unique_ptr<juce::Slider> paramA2;
    std::unique_ptr<juce::Label> paramLabel2;
    std::unique_ptr<juce::Slider> paramA3;
    std::unique_ptr<juce::Label> paramLabel3;
    std::unique_ptr<juce::Slider> paramA4;
    std::unique_ptr<juce::Label> paramLabel4;
    std::unique_ptr<juce::Label> juce__label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

