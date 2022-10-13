#include "network.h"
#include "helpers.h"

void NeuronActivation(neuron_t Neuron, unsigned int InputCount, double* InputArray)
{
	double activation = Neuron.Bias;
	for (unsigned int i = 0; i < InputCount; i++)
	{
		activation += *(InputArray + i);
	}
	return activation;
}

neuron_t* new_neuron(uint8_t ActivationFunction)
{
	neuron_t p = { 0 };
	p.ActivationFunction = ActivationFunction;
	p.Output = init_weight();
	p.Bias = init_weight();
	return &p;
}

layer_t* new_layer(uint8_t ActivationFunction, unsigned int NeuronCount)
{
	layer_t p = { 0 };
	p.neuron = new_neuron(ActivationFunction);
	return &p;
}

network_t new_network(unsigned int InputCount, unsigned int HiddenLayerCount, unsigned int OutputCount, unsigned int HiddenLayerNeuronCount)
{
	network_t network = { 0 };
	network.InputCount = InputCount;
	network.InputLayer = *new_layer(SIGMOID, InputCount);
	network.HiddenLayerCount = HiddenLayerCount;
	network.HiddenLayers = new_layer(SIGMOID, HiddenLayerNeuronCount);
	network.OutputCount = OutputCount;
	network.OutputLayer = *new_layer(SIGMOID, OutputCount);
	return network;
}
