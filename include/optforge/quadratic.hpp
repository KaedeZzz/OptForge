#pragma once

#include <optforge/objective.hpp>
#include <span>

namespace optforge{

class QuadraticObjective: public Objective {
public:
    double value(
        std::span<const double> x
    ) const override;

    void gradient(
        std::span<const double> x,
        std::span<double> grad
    ) const override;

};

}