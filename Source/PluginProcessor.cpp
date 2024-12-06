/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
EquatoneAudioProcessor::EquatoneAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
    ,valueTreeState(*this, nullptr, juce::Identifier("Equatone"), {
            std::make_unique<juce::AudioParameterFloat>("paramA","ParamA",0.f,1.f,0.f),
            std::make_unique<juce::AudioParameterFloat>("paramB","ParamB",0.f,1.f,0.f),
            std::make_unique<juce::AudioParameterFloat>("paramC","ParamC",0.f,1.f,0.f),
            std::make_unique<juce::AudioParameterFloat>("paramD","ParamD",0.f,1.f,0.f),
        })
    
{

    
}

EquatoneAudioProcessor::~EquatoneAudioProcessor()
{
}

//==============================================================================
const juce::String EquatoneAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EquatoneAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EquatoneAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool EquatoneAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double EquatoneAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EquatoneAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EquatoneAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EquatoneAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String EquatoneAudioProcessor::getProgramName (int index)
{
    return {};
}

void EquatoneAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void EquatoneAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    if (!expression.num_symbol_tables()) {
        DBG("expression inited!");
        setEquation("0");
    }

    // initialisation that you need..
}

void EquatoneAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EquatoneAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void EquatoneAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    paramA = valueTreeState.getRawParameterValue("paramA")->load();
    paramB = valueTreeState.getRawParameterValue("paramB")->load();
    paramC = valueTreeState.getRawParameterValue("paramC")->load();
    paramD = valueTreeState.getRawParameterValue("paramD")->load();

    for (const auto midiMessage : midiMessages) {
        midiNote = midiMessage.getMessage().getNoteNumber();
    }

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    int tmpPhase = phase;

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        channelIdx = static_cast<float>(channel);
        auto* channelData = buffer.getWritePointer (channel);

        input = channelData[0];

        phase = tmpPhase;

        for (int i = 0; i < buffer.getNumSamples(); i++) {
            
            input = channelData[i];
            channelData[i] = juce::jlimit(-1.f,1.f, expression.value());

            phase += 1.f;
        }

        // ..do something to the data...
    }
}

//==============================================================================
bool EquatoneAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* EquatoneAudioProcessor::createEditor()
{
    return new NewProjectAudioProcessorEditor (*this, valueTreeState);
}

//==============================================================================
void EquatoneAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void EquatoneAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EquatoneAudioProcessor();
}

juce::String EquatoneAudioProcessor::setEquation(juce::String str) {
    const int len = str.length();
    const char* charStr = str.toRawUTF8();

    exprtk::symbol_table<float> symbolTable;
    symbolTable.add_variable("channel", channelIdx);
    symbolTable.add_variable("index", phase);
    symbolTable.add_variable("input", input);

    symbolTable.add_variable("paramA", paramA);
    symbolTable.add_variable("paramB", paramB);
    symbolTable.add_variable("paramC", paramC);
    symbolTable.add_variable("paramD", paramD);

    symbolTable.add_variable("midiNote", midiNote);
    symbolTable.add_function("MidiNote2Hertz", [](const float n)->float {return juce::MidiMessage::getMidiNoteInHertz(n); });


    symbolTable.add_pi();
    symbolTable.add_constant("SampleRate", getSampleRate());
    
    expression.release();
    
    expression.register_symbol_table(symbolTable);

    exprtk::parser<float> parser;

    if (!parser.compile(charStr, expression)) {
        return "ERROR!";
    }

    return "Success!";
}