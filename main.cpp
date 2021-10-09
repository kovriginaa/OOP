#include <iostream>
#include <iostream>
#include "proga.hpp"

using namespace proga11;

int main() {
    Table *matrix = nullptr;
    matrix = input();
    if (matrix == nullptr) {
        std::cout << "Something goes wrong";
    } else {
        std::cout << "Matrix" << std::endl;
        output(matrix);
        //output_element(matrix);
        std::cout << "Changed Matrix" << std::endl;;
        if (!change(matrix)) {
            std::cout << "Something goes wrong";
        };
        output(matrix);
        //output_element(matrix);
    }
    erase(matrix);
    return 0;
}
