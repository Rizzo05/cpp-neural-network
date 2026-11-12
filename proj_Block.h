
#ifndef BLOCK_H
#define BLOCK_H

#include "Module.h" //include module header file
#include <vector>
#include <cstddef>

class Block : public Module {
private:
    std::vector<Module*> layers; //stores layers in block

public:
    Block() = default; //constructor

    //destructor to delete allocated layers
    ~Block() override;

    //prevent accidental copying
    Block(const Block&) = delete;
    Block& operator=(const Block&) = delete;

    //adds new layer to block
    void addLayer(Module* layer);

    //performs forward propagation
    std::vector<double> forward(
        const std::vector<double>& input
    ) override;

    //returns number of layers
    std::size_t getSize() const;
};

#endif
