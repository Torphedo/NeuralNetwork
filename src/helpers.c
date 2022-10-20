#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Activation function and its derivative
float sigmoid(float x)
{
    return 1 / ((float)1 + exp(-x));
}

float dSigmoid(float x)
{
    return x * (1 - x);
}

// Init all weights and biases between 0.0 and 1.0
float init_weight()
{
    return ((float)rand()) / ((float)RAND_MAX);
}

void shuffle(int* array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
