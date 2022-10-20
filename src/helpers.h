#pragma once

// Activation function and its derivative
float sigmoid(float x);
float dSigmoid(float x);

// Init all weights and biases between 0.0 and 1.0
float init_weight();

// Randomly shuffle elements of an int array
void shuffle(int* array, size_t n);
