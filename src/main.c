#include <stdio.h>

#include "helpers.h"
#include "matrix.h"

#define M_NUMINPUTS 2
#define M_NUMHIDDENLAYERS 1
#define M_NUMHIDDENNODES 2
#define M_NUMOUTPUTS 1
#define M_NUMTRAININGSETS 4

static const float LearningRate = 0.1f;

int main() {
    float HiddenLayerOutput[M_NUMHIDDENNODES];
    float HiddenWeights[M_NUMINPUTS][M_NUMHIDDENNODES];
    float HiddenBias[M_NUMHIDDENNODES];

    float OutputLayer[M_NUMOUTPUTS];
    float OutputBias[M_NUMOUTPUTS];
    float OutputWeights[M_NUMHIDDENNODES][M_NUMOUTPUTS];


    // Basic XOR dataset

    float TrainingInputs[M_NUMTRAININGSETS][M_NUMINPUTS] = {
        {0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}
    };

    float TrainingOutputs[M_NUMTRAININGSETS][M_NUMOUTPUTS] = {
        {0.0f}, {1.0f}, {1.0f}, {0.0f}
    };

    for (int i = 0; i < M_NUMINPUTS; i++) {
        for (int j = 0; j < M_NUMHIDDENNODES; j++) {
            HiddenWeights[i][j] = init_weight();
        }
    }
    for (int i = 0; i < M_NUMHIDDENNODES; i++) {
        HiddenBias[i] = init_weight();
        for (int j = 0; j < M_NUMOUTPUTS; j++) {
            OutputWeights[i][j] = init_weight();
        }
    }
    for (int i = 0; i < M_NUMOUTPUTS; i++) {
        OutputBias[i] = init_weight();
    }

    // At the moment, you'll need to move this to the binary directory for it to work while debugging.
    matrix_t* InputData = matrix_load_text("res/InputData.txt");

    unsigned int epochs = 10000000;
    // Iterate through training for a set number of epochs
    for (int n = 0; n < epochs; n++) {

        // Update progress every 1 million cycles to avoid slowing down too much
        if (n % 1000000 == 0) {
            printf("\rIn progress %d%%", (int) (((float) (n + 1) / epochs) * 100));
        }

        // As per SGD, shuffle the order of the training set
        int trainingSetOrder[] = { 0,1,2,3 };
        shuffle(trainingSetOrder, M_NUMTRAININGSETS);

        // Cycle through each of the training set elements
        for (int x = 0; x < M_NUMTRAININGSETS; x++) {
            int i = trainingSetOrder[x];

            // Compute hidden layer activation
            for (int j = 0; j < M_NUMHIDDENNODES; j++) {
                float activation = HiddenBias[j];
                for (int k = 0; k < M_NUMINPUTS; k++) {
                    activation += TrainingInputs[i][k] * HiddenWeights[k][j];
                }

                HiddenLayerOutput[j] = sigmoid(activation);
            }

            // Compute output layer activation
            for (int j = 0; j < M_NUMOUTPUTS; j++) {
                float activation = OutputBias[j];
                for (int k = 0; k < M_NUMHIDDENNODES; k++) {
                    activation += HiddenLayerOutput[k] * OutputWeights[k][j];
                }
                OutputLayer[j] = sigmoid(activation);
            }

            if (n == 9999999) {
                printf("\nInputs: %f %f    Output: %f", TrainingInputs[i][0], TrainingInputs[i][1], OutputLayer[0]);
                printf("    Expected Output: %f\n", TrainingOutputs[i][0]);
            }

            // Compute change in output weights
            float deltaOutput[M_NUMOUTPUTS];
            for (int j = 0; j < M_NUMOUTPUTS; j++) {
                float dError = (TrainingOutputs[i][j] - OutputLayer[j]);
                if (n == 9999999)
                {
                    printf("Error: %f\n", dError);
                }
                deltaOutput[j] = dError * dSigmoid(OutputLayer[j]);
            }

            // Compute change in hidden weights
            float deltaHidden[M_NUMHIDDENNODES];
            for (int j = 0; j < M_NUMHIDDENNODES; j++) {
                float dError = 0.0f;
                for (int k = 0; k < M_NUMOUTPUTS; k++) {
                    dError += deltaOutput[k] * OutputWeights[j][k];
                }
                deltaHidden[j] = dError * dSigmoid(HiddenLayerOutput[j]);
            }

            // Apply change in output weights
            for (int j = 0; j < M_NUMOUTPUTS; j++) {
                OutputBias[j] += deltaOutput[j] * LearningRate;
                for (int k = 0; k < M_NUMHIDDENNODES; k++) {
                    OutputWeights[k][j] += HiddenLayerOutput[k] * deltaOutput[j] * LearningRate;
                }
            }
            // Apply change in hidden weights
            for (int j = 0; j < M_NUMHIDDENNODES; j++) {
                HiddenBias[j] += deltaHidden[j] * LearningRate;
                for (int k = 0; k < M_NUMINPUTS; k++) {
                    HiddenWeights[k][j] += TrainingInputs[i][k] * deltaHidden[j] * LearningRate;
                }
            }
        }
    }
    if (InputData != NULL) { matrix_free(InputData); }
    printf("\nDone!");
    return 0;
}
