#include <stdlib.h>

// Activation function and its derivative
double sigmoid(double x)
{
    return 1 / ((float)1 + exp(-x));
}

double dSigmoid(double x)
{
    return x * (1 - x);
}

// Init all weights and biases between 0.0 and 1.0
double init_weight()
{
    return ((double)rand()) / ((double)RAND_MAX);
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
