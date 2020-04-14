#include <iostream>
#include "Triangle.hpp"

int main() {
    int rows, felement;

    std::cout << "Input number of rows:";
    std::cin >> rows;
    std::cout << "Input first element:";
    std::cin >> felement;

    Triangle<int> t(felement, rows);

    for (int i = 1; i < rows; i++)
    {
        std::cin >> t;
        t.print();
        std::cout << t.get_rows() << std::endl;
    }

    std::cout << "Test for getAt:\n";
    for (int i = 0; i < t.get_rows(); ++i) {
        for (int j = i; j >= 0; --j) {
            std::cout << t.get_at(i, j) << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "Is symmetric? : " << std::boolalpha << t.is_symetric() << '\n';
    return 0;
}