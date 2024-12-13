#include <iostream>

#include "list.hpp"

int main()
{
    pw::List<pw::List<int>> l;
    pw::List<int> temp;

    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);

    l.push_back(temp);
    temp.push(1, 1);
    temp[1] = 9;
    l.push_back(temp);
    temp[3] = 2;

    std::cout << l[0][1] << std::endl;

    return 0;
}
