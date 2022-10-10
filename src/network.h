#pragma once
#include <stdint.h>

// Macros are used instead of normal variables
// because C99 VLAs aren't universally supported.
#define M_NUMINPUTS 2
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
	double* Inputs;
	double* Weights;
	double Bias;
	uint8_t ActivationType;
}neuron_t;

typedef struct Layer
{
	int NeuronCount;
	struct neuron_t *neuron;
}layer_t;

layer_t* new_layer(int depth)
{
	layer_t* p = malloc(sizeof(layer_t));
	p->NeuronCount = depth;
	p->neuron = malloc((sizeof(neuron_t) * depth));
}
