#include <iostream>

#include "list.hpp"

int main()
{
    pw::List<pw::List<int>> l = {{5,5,5},{6,6,6},{7,7,7}};

    std::cout << l << std::endl;

    return 0;
}
