
#ifndef RELUACTIVATION_H
#define RELUACTIVATION_H

#include "Module.h" //include module header file
#include <vector>

class ReLUActivation : public Module {
public:
    //constructor
    ReLUActivation() = default;

    //performs ReLU activation
    std::vector<double> forward(
        const std::vector<double>& input
    ) override;
};

#endif
