#include <iostream>

#include "matrix.hpp"

int main()
{
    pw::Matrix<int> m1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(auto &elem : m1.get_matrix())
        std::cout << elem << std::endl;

    std::cout << "--------------------------------------" << std::endl;

    pw::Matrix<int> m2{m1};

    for(auto &elem : m2.get_matrix())
        std::cout << elem << std::endl;

    std::cout << "--------------------------------------" << std::endl;

    m1.get_matrix()[0][0] = 548;

    for(auto &elem : m2.get_matrix())
        std::cout << elem << std::endl;

    std::cout << "--------------------------------------" << std::endl;

    for(auto &elem : m1.get_matrix())
        std::cout << elem << std::endl;

    std::cout << "--------------------------------------" << std::endl;

    return 0;
}
