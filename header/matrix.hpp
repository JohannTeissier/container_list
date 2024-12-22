#pragma once

#include "matrix_template.hpp"

namespace pw
{


template <typename M>
inline Matrix<M>::Matrix(const Matrix<M> &other)
{
    this->__m = other.__m;
    this->__empty = false;
}

template <typename M>
inline Matrix<M>::Matrix(std::initializer_list<List<M>> list)
{
    int w = list.size();
    int h;
    if(w == 0)
        return;

    h = list.begin()->get_cardinal();

    for(auto &e : list)
    {
        if(h != e.get_cardinal())
            return;
    }


    this->__width = w;
    this->__height = h;
    this->__m = list;
    this->__empty = false;
}

template <typename M>
inline void Matrix<M>::operator=(const Matrix<M> &other)
{
    this->__m = other.__m;
    this->__empty = false;
}

template <typename M>
inline void Matrix<M>::operator=(std::initializer_list<List<M>> list)
{
    if(this->__width != 0 && this->__height != 0)
        this->__m.clear();

    int w = list.size();
    int h;
    if(w == 0)
        return;

    h = list.begin()->get_cardinal();

    for(auto &e : list)
    {
        if(h != e.get_cardinal())
            return;
    }


    this->__width = w;
    this->__height = h;
    this->__m = list;
    this->__empty = false;
}

template <typename M>
inline List<List<M>> &Matrix<M>::get_matrix()
{
    return this->__m;
}

} // namespace pw

