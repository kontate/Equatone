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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent (NewProjectAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    codeText.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (codeText.get());
    codeText->setMultiLine (false);
    codeText->setReturnKeyStartsNewLine (false);
    codeText->setReadOnly (false);
    codeText->setScrollbarsShown (true);
    codeText->setCaretVisible (true);
    codeText->setPopupMenuEnabled (true);
    codeText->setText (juce::String());

    codeText->setBounds (16, 144, 560, 96);

    compileButton.reset (new juce::TextButton ("compile"));
    addAndMakeVisible (compileButton.get());
    compileButton->setTooltip (TRANS("Compile"));
    compileButton->setButtonText (TRANS("Compile"));
    compileButton->addListener (this);

    compileButton->setBounds (424, 248, 150, 24);

    paramA.reset (new juce::Slider ("param"));
    addAndMakeVisible (paramA.get());
    paramA->setRange (0, 1, 0);
    paramA->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    paramA->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    paramA->addListener (this);

    paramA->setBounds (16, 32, 78, 104);

    paramLabel.reset (new juce::Label ("new label",
                                       TRANS("paramA")));
    addAndMakeVisible (paramLabel.get());
    paramLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    paramLabel->setJustificationType (juce::Justification::centred);
    paramLabel->setEditable (false, false, false);
    paramLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    paramLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    paramLabel->setBounds (16, 16, 80, 24);

    paramA2.reset (new juce::Slider ("param"));
    addAndMakeVisible (paramA2.get());
    paramA2->setRange (0, 1, 0);
    paramA2->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    paramA2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    paramA2->addListener (this);

    paramA2->setBounds (104, 33, 78, 104);

    paramLabel2.reset (new juce::Label ("new label",
                                        TRANS("paramB")));
    addAndMakeVisible (paramLabel2.get());
    paramLabel2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    paramLabel2->setJustificationType (juce::Justification::centred);
    paramLabel2->setEditable (false, false, false);
    paramLabel2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    paramLabel2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    paramLabel2->setBounds (104, 17, 80, 24);

    paramA3.reset (new juce::Slider ("param"));
    addAndMakeVisible (paramA3.get());
    paramA3->setRange (0, 1, 0);
    paramA3->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    paramA3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    paramA3->addListener (this);

    paramA3->setBounds (193, 33, 78, 104);

    paramLabel3.reset (new juce::Label ("new label",
                                        TRANS("paramC")));
    addAndMakeVisible (paramLabel3.get());
    paramLabel3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    paramLabel3->setJustificationType (juce::Justification::centred);
    paramLabel3->setEditable (false, false, false);
    paramLabel3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    paramLabel3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    paramLabel3->setBounds (193, 17, 80, 24);

    paramA4.reset (new juce::Slider ("param"));
    addAndMakeVisible (paramA4.get());
    paramA4->setRange (0, 1, 0);
    paramA4->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    paramA4->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    paramA4->addListener (this);

    paramA4->setBounds (280, 32, 78, 104);

    paramLabel4.reset (new juce::Label ("new label",
                                        TRANS("paramD")));
    addAndMakeVisible (paramLabel4.get());
    paramLabel4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    paramLabel4->setJustificationType (juce::Justification::centred);
    paramLabel4->setEditable (false, false, false);
    paramLabel4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    paramLabel4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    paramLabel4->setBounds (280, 16, 80, 24);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("usable parameter\n"
                                        "- channel : 0 or 1\n"
                                        "- index    : 0 to inf\n"
                                        "- input     : input val\n"
                                        "\n"
                                        "const\n"
                                        "- SampleRate")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (16, 272, 560, 112);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    codeText = nullptr;
    compileButton = nullptr;
    paramA = nullptr;
    paramLabel = nullptr;
    paramA2 = nullptr;
    paramLabel2 = nullptr;
    paramA3 = nullptr;
    paramLabel3 = nullptr;
    paramA4 = nullptr;
    paramLabel4 = nullptr;
    juce__label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == compileButton.get())
    {
        //[UserButtonCode_compileButton] -- add your button handler code here..

        DBG(processor.setEquation(codeText->getText()));
        //[/UserButtonCode_compileButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == paramA.get())
    {
        //[UserSliderCode_paramA] -- add your slider handling code here..
        auto param = valueTreeState.getRawParameterValue("paramA");
        param->store(paramA->getValue());
        //[/UserSliderCode_paramA]
    }
    else if (sliderThatWasMoved == paramA2.get())
    {
        //[UserSliderCode_paramA2] -- add your slider handling code here..
        auto param = valueTreeState.getRawParameterValue("paramB");
        param->store(paramA2->getValue());
        //[/UserSliderCode_paramA2]
    }
    else if (sliderThatWasMoved == paramA3.get())
    {
        //[UserSliderCode_paramA3] -- add your slider handling code here..
        auto param = valueTreeState.getRawParameterValue("paramC");
        param->store(paramA3->getValue());
        //[/UserSliderCode_paramA3]
    }
    else if (sliderThatWasMoved == paramA4.get())
    {
        //[UserSliderCode_paramA4] -- add your slider handling code here..
        auto param = valueTreeState.getRawParameterValue("paramD");
        param->store(paramA4->getValue());
        //[/UserSliderCode_paramA4]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="NewProjectAudioProcessor&amp; p, juce::AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="processor(p), valueTreeState(vts)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="ac603856a93f6bbe" memberName="codeText"
              virtualName="" explicitFocusOrder="0" pos="16 144 560 96" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="compile" id="29a7d554c2f1286a" memberName="compileButton"
              virtualName="" explicitFocusOrder="0" pos="424 248 150 24" tooltip="Compile"
              buttonText="Compile" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="param" id="f4b7c741fcc01c3f" memberName="paramA" virtualName=""
          explicitFocusOrder="0" pos="16 32 78 104" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="fa56f140051a31d9" memberName="paramLabel"
         virtualName="" explicitFocusOrder="0" pos="16 16 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="paramA" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="param" id="371e96a29adb24d9" memberName="paramA2" virtualName=""
          explicitFocusOrder="0" pos="104 33 78 104" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="20e947107c80c0c2" memberName="paramLabel2"
         virtualName="" explicitFocusOrder="0" pos="104 17 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="paramB" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="param" id="9b3f8055ea9b80a1" memberName="paramA3" virtualName=""
          explicitFocusOrder="0" pos="193 33 78 104" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="871e9fd53d09c5d4" memberName="paramLabel3"
         virtualName="" explicitFocusOrder="0" pos="193 17 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="paramC" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="param" id="4e32089604ac79a2" memberName="paramA4" virtualName=""
          explicitFocusOrder="0" pos="280 32 78 104" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="2155b307d24d17bf" memberName="paramLabel4"
         virtualName="" explicitFocusOrder="0" pos="280 16 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="paramD" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bd985a20c5883803" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="16 272 560 112" edTextCol="ff000000"
         edBkgCol="0" labelText="usable parameter&#10;- channel : 0 or 1&#10;- index    : 0 to inf&#10;- input     : input val&#10;&#10;const&#10;- SampleRate"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

