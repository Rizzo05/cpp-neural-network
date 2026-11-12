
#include "ReLUActivation.h" //include ReLU header file
#include <iostream>
using namespace std;

//performs ReLU activation on input values
std::vector<double> ReLUActivation::forward(
    const std::vector<double>& input) {

    std::vector<double> output = input; //copy input values

    //loop through each value
    for (double& val : output) {

        //if negative, change to zero
        if (val < 0) {
            val = 0;
        }
    }

    cout << "ReLUActivation applied." << endl;

    return output; //returns activated values
}
