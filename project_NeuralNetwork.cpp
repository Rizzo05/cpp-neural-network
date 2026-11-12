
#include "NeuralNetwork.h" //include the headerfile
#include <iostream>
using namespace std;

//destructor to delete allocated memory
NeuralNetwork::~NeuralNetwork() {
    for (Block* block : blocks) {
        delete block;
    }
    blocks.clear();
}

//adds block to neural network
void NeuralNetwork::addBlock(Block* block) {
    blocks.push_back(block); //adds block to blocks vector
    cout << "Block added to NeuralNetwork." << endl;
}

//performs forw. propagation through neural network
std::vector<double> NeuralNetwork::forward(const std::vector<double>& input) {
    cout << "NeuralNetwork forward pass started." << endl;

    std::vector<double> output = input;

    //passes output through each block
    for (Block* block : blocks) {
        output = block->forward(output);
    }

    return output; //returns final output
}

//prints the model structure
void NeuralNetwork::printModel() {
    cout << "Neural Network Structure:" << endl;

    for (size_t i = 0; i < blocks.size(); ++i) {
        cout << "Block " << i << " - ";
        cout << blocks[i]->getSize() << " layer(s)" << endl;
    }
}

//prints size of blocks
void NeuralNetwork::printBlockSizes() {
    cout << "Block Sizes:" << endl;

    for (size_t i = 0; i < blocks.size(); ++i) {
        cout << "Block " << i
             << " size: " << blocks[i]->getSize()
             << endl;
    }
}
