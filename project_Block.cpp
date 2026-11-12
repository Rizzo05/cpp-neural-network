
#include "Block.h" //include block header file
#include <iostream>
using namespace std;

//destructor to delete allocated layers
Block::~Block() {
    for (Module* layer : layers) {
        delete layer;
    }
    layers.clear();
}

//adds new layers to block
void Block::addLayer(Module* layer) {
    if (layer != nullptr) { //check if layer exists
        layers.push_back(layer); //appends layer to layers vector
        cout << "Layer added to Block." << endl;
    }
}

//performs propagation through all layers in block
std::vector<double> Block::forward(const std::vector<double>& input) {
    std::vector<double> output = input; //initialize output

    for (auto& layer : layers) { //loop thru each layer in the block
        output = layer->forward(output);
        //passes output from one layer to input of the next layer
    }

    cout << "Block forward pass completed." << endl;
    return output; //returns final output after passing layers
}

//returns number of layers in block
std::size_t Block::getSize() const {
    return layers.size();
}
