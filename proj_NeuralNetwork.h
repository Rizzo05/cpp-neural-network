
#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Block.h" //include block header file
#include <vector>

class NeuralNetwork {
private:
    std::vector<Block*> blocks; //stores blocks in network

public:
    NeuralNetwork() = default; //constructor

    //destructor to delete allocated memory
    ~NeuralNetwork();

    //prevent accidental copying
    NeuralNetwork(const NeuralNetwork&) = delete;
    NeuralNetwork& operator=(const NeuralNetwork&) = delete;

    //adds block to neural network
    void addBlock(Block* block);

    //performs forward propagation
    std::vector<double> forward(
        const std::vector<double>& input
    );

    //prints model structure
    void printModel();

    //prints size of blocks
    void printBlockSizes();
};

#endif
