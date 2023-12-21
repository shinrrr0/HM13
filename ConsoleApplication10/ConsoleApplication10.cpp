#include <iostream>
#include <iomanip>
#include <cmath>

class Calculator {
public:
    Calculator(int precision) : precision(precision) {};
    void change_precision(int precision) {
        this->precision = precision;
    }
protected:
    int precision;
};

class PathLengthCalculator: public Calculator {
public:
    PathLengthCalculator(int precision = 2) : Calculator(precision) {};
    double operator()(double radius) {
        std::cout << std::fixed << std::setprecision(precision);
        return std::floor(2 * pi * radius * pow(10, precision)) / pow(10, precision);
    }
private:
    double pi = 3.14159265358979323846;
};


class RotationSpeedCalculator: public Calculator {
public:
    RotationSpeedCalculator(int precision = 2) : Calculator(precision) {};
    double operator()(double angularVelocity, double radius) const {
        std::cout << std::fixed << std::setprecision(precision);
        return  std::floor(angularVelocity * radius * pow(10, precision) + 0.5) / pow(10, precision);
    }
};

int main() {
    PathLengthCalculator lengthCalculator;
    RotationSpeedCalculator speedCalculator;

    double radius = 5.0;
    double angularVelocity = 3.912123124;
    
    std::cout << "Path Length (Precision 2): " << lengthCalculator(radius) << std::endl;
    lengthCalculator.change_precision(12);
    std::cout << "Path Length (Precision 4): " << lengthCalculator(radius) << std::endl;

    std::cout << "Rotation Speed (Precision 2): " << speedCalculator(angularVelocity, radius) << std::endl;
    speedCalculator.change_precision(12);
    std::cout << "Rotation Speed (Precision 4): " << speedCalculator(angularVelocity, radius) << std::endl;

    return 0;
}