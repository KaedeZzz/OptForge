#pragma once

#include <span>

namespace optforge{

class Objective{
public:
    virtual ~Objective() = default; 
    
    virtual double value(
        std::span<const double> x
    ) const = 0;

    virtual void gradient(
        std::span<const double> x,
        std::span<double> grad
    ) const = 0;
    
};

}
