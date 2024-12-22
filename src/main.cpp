#include <iostream>

#include "matrix.hpp"

int main()
{
    pw::Matrix<int> m{{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};

    m[0] = {10, 10, 10};

    for(auto &elem : m[":"])
        std::cout << elem << std::endl;

    m[":"][1] = {-20, -20, -20};

    std::cout << "\n\n";

    for(auto &elem : m.get_matrix())
        std::cout << elem << std::endl;

    return 0;
}
