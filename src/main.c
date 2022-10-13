#include <stdio.h>

#include "network.h"
#include "helpers.h"


int main() {
    double HiddenLayerOutput[M_NUMHIDDENNODES];
    double HiddenWeights[M_NUMINPUTS][M_NUMHIDDENNODES];
    double HiddenBias[M_NUMHIDDENNODES];

    double OutputLayer[M_NUMOUTPUTS];
    double OutputBias[M_NUMOUTPUTS];
    double OutputWeights[M_NUMHIDDENNODES][M_NUMOUTPUTS];


    // Basic XOR dataset
    double TrainingInputs[M_NUMTRAININGSETS][M_NUMINPUTS] = {
        {0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}
    };
    
    double TrainingOutputs[M_NUMTRAININGSETS][M_NUMOUTPUTS] = {
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
    network_t Network = new_network(M_NUMINPUTS, M_NUMHIDDENLAYERS, M_NUMOUTPUTS, M_NUMHIDDENNODES);

    int epochs = 10000000;
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
                double activation = HiddenBias[j];
                for (int k = 0; k < M_NUMINPUTS; k++) {
                    activation += TrainingInputs[i][k] * HiddenWeights[k][j];
                }

                HiddenLayerOutput[j] = sigmoid(activation);
            }

            // Compute output layer activation
            for (int j = 0; j < M_NUMOUTPUTS; j++) {
                double activation = OutputBias[j];
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
            double deltaOutput[M_NUMOUTPUTS];
            for (int j = 0; j < M_NUMOUTPUTS; j++) {
                double dError = (TrainingOutputs[i][j] - OutputLayer[j]);
                if (n == 9999999)
                {
                    printf("Error: %f\n", dError);
                }
                deltaOutput[j] = dError * dSigmoid(OutputLayer[j]);
            }

            // Compute change in hidden weights
            double deltaHidden[M_NUMHIDDENNODES];
            for (int j = 0; j < M_NUMHIDDENNODES; j++) {
                double dError = 0.0f;
                for (int k = 0; k < M_NUMOUTPUTS; k++) {
                    dError += deltaOutput[k] * OutputWeights[j][k];
                }
                deltaHidden[j] = dError * dSigmoid(HiddenLayerOutput[j]);
            }

            // Apply change in output weights
            for (int j = 0; j < M_NUMOUTPUTS; j++) {
                OutputBias[j] += deltaOutput[j] * M_LEARNINGRATE;
                for (int k = 0; k < M_NUMHIDDENNODES; k++) {
                    OutputWeights[k][j] += HiddenLayerOutput[k] * deltaOutput[j] * M_LEARNINGRATE;
                }
            }
            // Apply change in hidden weights
            for (int j = 0; j < M_NUMHIDDENNODES; j++) {
                HiddenBias[j] += deltaHidden[j] * M_LEARNINGRATE;
                for (int k = 0; k < M_NUMINPUTS; k++) {
                    HiddenWeights[k][j] += TrainingInputs[i][k] * deltaHidden[j] * M_LEARNINGRATE;
                }
            }
        }
    }
    printf("\n");
    printf("Done!");
    return 0;
}
