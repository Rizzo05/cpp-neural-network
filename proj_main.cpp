
#include "NeuralNetwork.h" //include neural network header
#include "Block.h" //include block header
#include "LinearLayer.h" //include linear layer header
#include "ReLUActivation.h" //include ReLU header
#include <iostream>
#include <vector>
using namespace std;

int main() {

    //create neural network
    NeuralNetwork network;

    //create a block for the network
    Block* block = new Block();

    //add linear layer with 3 inputs and 2 outputs
    block->addLayer(new LinearLayer(3, 2));

    //add ReLU activation layer
    block->addLayer(new ReLUActivation());

    //add block to neural network
    network.addBlock(block);

    //display neural network structure
    network.printModel();
    network.printBlockSizes();

    //initialize input values
    vector<double> input = {2.0, 4.0, -1.0};

    //perform forward propagation
    vector<double> output = network.forward(input);

    //display final output
    cout << "Final Neural Network Output: " << endl;

    for (double value : output) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
