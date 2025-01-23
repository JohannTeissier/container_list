#pragma once

#include <string>

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
    void operator =(const M val);
    Matrix<M> operator [](size_t index);
    Matrix<M> operator [](const std::string c);

    List<List<M>>& get_matrix();

    friend std::ostream& operator <<(std::ostream& os, Matrix<M>& m)
    {
        for(auto &elem : m.__m)
            os << elem << "\n";

        return os;
    }

private:

    void same_transpose();

    List<List<M>> __m;
    List<List<M>> __mt;
    int __width = 0;
    int __height = 0;
    bool __empty = true;
};

} // namespace pw
