#include <optforge/quadratic.hpp>
#include <vector>
#include <iostream>

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

    return 0;
}