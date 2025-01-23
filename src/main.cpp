#include <iostream>

#include "vector.hpp"
#include "matrix.hpp"

int main()
{
    // pw::Vector<int> v{{1, 2, 3, 4, 5, 6}};

    // pw::Vector<int> v2;

    // v2 = {5, 5, 5, 5};

    // std::cout << v2.get_list() << std::endl;

    pw::Matrix<int> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    m[1] = {0, 0, 0};

    return 0;
}
