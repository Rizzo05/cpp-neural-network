
#include "LinearLayer.h" //include linear layer header file
#include <stdexcept>
#include <vector>
using namespace std;

//constructor initializes weights and biases
LinearLayer::LinearLayer(int input_size, int output_size) {

    //check that layer sizes are valid
    if (input_size <= 0 || output_size <= 0) {
        throw invalid_argument("Layer sizes must be positive");
    }

    //initialize weights to 0.5
    weights.resize(output_size, vector<double>(input_size, 0.5));

    //initialize biases to 0
    bias.resize(output_size, 0.0);
}

//performs forward propagation through linear layer
vector<double> LinearLayer::forward(const vector<double>& input) {

    //check that input has the correct size
    if (input.size() != weights[0].size()) {
        throw invalid_argument("Incorrect input size");
    }

    //initialize output with bias values
    vector<double> output = bias;

    //loop through each output neuron
    for (size_t i = 0; i < weights.size(); ++i) {

        //loop through each input value
        for (size_t j = 0; j < weights[i].size(); ++j) {

            //multiply each input by its weight
            output[i] += weights[i][j] * input[j];
        }
    }

    return output; //returns calculated output
}
