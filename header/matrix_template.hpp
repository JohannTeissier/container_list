#pragma once

#include "list.hpp"

namespace pw
{

template <typename M>
class Matrix
{
public:

    Matrix() = default;
    Matrix(const Matrix<M> &other);
    Matrix(std::initializer_list<List<M>> list);

    void operator =(const Matrix<M> &other);
    void operator =(std::initializer_list<List<M>> list);

    List<List<M>>& get_matrix();

private:

    List<List<M>> __m;
    int __width = 0;
    int __height = 0;
    bool __empty = true;
};

} // namespace pw
