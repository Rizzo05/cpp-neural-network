
#ifndef LINEARLAYER_H
#define LINEARLAYER_H

#include "Module.h" //include module header file
#include <vector>

class LinearLayer : public Module {
private:
    //stores weights for each input and output
    std::vector<std::vector<double>> weights;

    //stores bias values
    std::vector<double> bias;

public:
    //constructor initializes weights and biases
    LinearLayer(int input_size, int output_size);

    //performs forward propagation
    std::vector<double> forward(
        const std::vector<double>& input
    ) override;
};

#endif
