#pragma once

#include "matrix_template.hpp"

namespace pw
{


template <typename M>
inline Matrix<M>::Matrix(const Matrix<M> &other)
{
    this->__m = other.__m;
    this->__empty = false;
    this->same_transpose();
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
    this->same_transpose();
}

template <typename M>
inline void Matrix<M>::operator=(const Matrix<M> &other)
{
    if(!this->__empty)
    {
        if(this->__width != other.__width || this->__height != other.__height)
            return;

        this->__m.clear();
        this->__mt.clear();
    }

    this->__m = other.__m;
    this->__width = other.__width;
    this->__height = other.__height;
    this->__empty = false;
    this->same_transpose();
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
    this->same_transpose();
}

template <typename M>
inline void Matrix<M>::operator=(const M val)
{
    if(this->__width == 0 && this->__height == 0)
        this->__m[0][0] = val;
}

template <typename M>
inline Matrix<M> Matrix<M>::operator[](size_t index)
{
    Matrix<M> temp;

    if(index < 0 || index >= this->__width)
        temp.__m.ref_push_back(&(this->__m[0]));
    else
        temp.__m.ref_push_back(&(this->__m[index]));

    return temp;
}

template <typename M>
inline Matrix<M> Matrix<M>::operator[](const std::string c)
{
    Matrix<M> temp;
    temp.__m.ref_copy(&(this->__mt));

    return temp;
}

template <typename M>
inline List<List<M>> &Matrix<M>::get_matrix()
{
    return this->__m;
}

template <typename M>
inline void Matrix<M>::same_transpose()
{
    for(int i = 0; i < this->__height; i++)
    {
        this->__mt.push_back(List<M>{});
        for(int j = 0; j < this->__width; j++)
        {
            M* temp = this->__m[j].get_elem(i);
            this->__mt[i].ref_push_back(temp);
        }
    }
}

} // namespace pw

