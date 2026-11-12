#include <optforge/quadratic.hpp>
#include <vector>
#include <iostream>
#include <stdexcept>

int main() {
    optforge::QuadraticObjective quad_obj;
    std::vector<double> x = {2.0, -3.0};
    std::vector<double> grad = {0.0, 0.0};

    if (quad_obj.value(x) != 6.5) {
        std::cerr << "Value test failed\n";
        return 1;
    }

    quad_obj.gradient(x, grad);
    if (grad[0] != 2.0 || grad[1] != -3.0) {
        std::cerr << "Gradient test failed\n";
        return 1;
    }

    grad = {99.0};
    try {
        quad_obj.gradient(x, grad);
        std::cerr << "Expected invalid_argument for gradient size mismatch\n";
        return 1;
    } catch (const std::invalid_argument&) {
        if (grad[0] != 99.0) {
            std::cerr << "Gradient invalid written";
            return 1;
        }
    }

    std::vector <double>  empty_x;
    std::vector <double> empty_grad;
    try {
        quad_obj.value(empty_x);
        std::cerr << "Expected invalid_argument for empty input\n";
        return 1;
    } catch (const std::invalid_argument&){}
    try {
        quad_obj.gradient(empty_x, empty_grad);
        std::cerr << "Expected invalid_argument for empty input\n";
        return 1;
    } catch (const std::invalid_argument&){}

    return 0;
}