
#ifndef MODULE_H
#define MODULE_H

#include <vector>

class Module {
public:
    //performs forward propagation
    virtual std::vector<double> forward(
        const std::vector<double>& input
    ) = 0;

    //virtual destructor
    virtual ~Module() {}
};

#endif
