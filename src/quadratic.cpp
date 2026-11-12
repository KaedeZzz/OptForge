#include <optforge/quadratic.hpp>
#include <cstddef>
#include <stdexcept>

namespace optforge {

double QuadraticObjective::value(std::span<const double> x) const {
    if (x.empty()) {
        throw std::invalid_argument("Input must not be empty");
    }

    double sum = 0.0;
    for (double e : x) {
        sum += 0.5 * e * e;
    }
    return sum;
}

void QuadraticObjective::gradient(
    std::span<const double> x,
    std::span<double> grad
) const {
    if (x.empty()) {
        throw std::invalid_argument("Input must not be empty");
    }

    if (x.size() != grad.size()) {
        throw std::invalid_argument("Input size must match grad size");
    }

    for (std::size_t i = 0; i < x.size(); ++i) {
        grad[i] = x[i];
    }
}

}