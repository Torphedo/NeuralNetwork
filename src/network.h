#pragma once
#include <stdint.h>
#include <stdlib.h>

// Macros are used instead of normal variables
// because C99 VLAs aren't universally supported.
#define M_NUMINPUTS 2
#define M_NUMHIDDENLAYERS 1
#define M_NUMHIDDENNODES 2
#define M_NUMOUTPUTS 1
#define M_NUMTRAININGSETS 4

#define M_LEARNINGRATE 0.1f

enum ActivationFunctions
{
	SIGMOID = 0
};

typedef struct Neuron
{
	uint8_t ActivationFunction;
	double* Inputs;
	double* Weights;
	double Bias;
	double Output;
}neuron_t;

typedef struct Layer
{
	neuron_t *neuron;
}layer_t;

typedef struct Network
{
	unsigned int InputCount;
	layer_t InputLayer;
	unsigned int HiddenLayerCount;
	layer_t* HiddenLayers;
	unsigned int OutputCount;
	layer_t OutputLayer;
}network_t;

void NeuronActivation(neuron_t Neuron, unsigned int InputCount, double* InputArray);

neuron_t* new_neuron(uint8_t ActivationFunction);
layer_t* new_layer(uint8_t ActivationFunction, unsigned int NeuronCount);
network_t new_network(unsigned int InputCount, unsigned int HiddenLayerCount, unsigned int OutputCount, unsigned int HiddenLayerNeuronCount);
