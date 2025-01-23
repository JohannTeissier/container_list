#pragma once

#include "list.hpp"

namespace pw
{

template <typename V>
class Vector
{
public:

    Vector() = default;
    Vector(const Vector<V> &other);
    Vector(std::initializer_list<V> list);

    void operator =(const Vector<V> &other);
    void operator =(std::initializer_list<V> list);

    List<V> &get_list();

private:

    List<V> __vect;

    int __size = 0;
};

} // namespace pw
