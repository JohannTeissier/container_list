#include "vector_template.hpp"

namespace pw
{

template <typename V>
inline Vector<V>::Vector(const Vector<V> &other)
{
    this->__size = other.__size;
    this->__vect = other.__vect;
}

template <typename V>
inline Vector<V>::Vector(std::initializer_list<V> list)
{
    this->__size = list.size();

    for(auto &elem : list)
        this->__vect.push_back(elem);
}

template <typename V>
inline void Vector<V>::operator=(const Vector<V> &other)
{
    if(this->__size != other.__size && this->__size != 0)
        return;

    this->__vect = other.__vect;
}

template <typename V>
inline void Vector<V>::operator=(std::initializer_list<V> list)
{
    if(this->__size != list.size() && this->__size != 0)
        return;

    this->__vect = list;
}

template <typename V>
inline List<V> &Vector<V>::get_list()
{
    return this->__vect;
}

} // namespace pw
