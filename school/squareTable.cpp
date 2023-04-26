#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    
    const double SQUARE = 0.5;

    const int START_INT = -5;
    const int END_INT = 10;

    std::cout << "  INPUT  |  OUTPUT" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (float i = START_INT; i <= END_INT; i += 0.1) {
        double result = pow(i + SQUARE * (i < 0 ? -1 : 1), 3);
        std::cout << std::setw(8) << i << " | ";
        std::cout << std::setw(8) << result << std::endl;
    }

    std::cout << "-------------------" << std::endl;
    return 0;
}
