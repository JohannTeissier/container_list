#include <iostream>

#include "list.hpp"

int main()
{
    pw::List<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);

    l.push(5, 13);

    l.print_list();

    l.pop(2);

    l.print_list();

    std::cout << "Cardinal : " << l.get_cardinal() << std::endl;

    return 0;
}
