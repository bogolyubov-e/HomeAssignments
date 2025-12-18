/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment5
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T>
class Matrix
{
private:
    size_t rows_;
    size_t cols_;
    std::vector<T> data_;

public:
    Matrix(size_t rows, size_t cols, const T& value = T())
        : rows_(rows), cols_(cols), data_(rows * cols, value) {}

    Matrix() : rows_(0), cols_(0) {}

    size_t rows() const
    {
        return rows_;
    }
    size_t cols() const
    {
        return cols_;
    }

    T& at(size_t i, size_t j)
    {
        if (i >= rows_ || j >= cols_)
            throw std::out_of_range("Matrix index out of range");
        return data_[i * cols_ + j];
    }

    const T& at(size_t i, size_t j) const
    {
        if ( i >= rows_ || j >= cols_ )
            throw std::out_of_range("Matrix index out of range");
        return data_[i * cols_ + j];
    }

    Matrix operator+(const Matrix& other) const
    {
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Matrix dimensions must match for addition");
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < data_.size(); ++i)
        {
            result.data_[i] = data_[i] + other.data_[i];
        }
        return result;
    }

    Matrix operator*(const T& scalar) const
    {
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < data_.size(); ++i)
        {
            result.data_[i] = data_[i] * scalar;
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const
    {
        if (cols_ != other.rows_)
            throw std::invalid_argument("Inner dimensions must match for matrix multiplication");
        Matrix result(rows_, other.cols_, T{});
        for (size_t i = 0; i < rows_; ++i)
        {
            for (size_t j = 0; j < other.cols_; ++j)
            {
                T sum = T{};
                for (size_t k = 0; k < cols_; ++k)
                {
                    sum = sum + at(i, k) * other.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }
        return result;
    }

    Matrix transpose() const
    {
        Matrix result(cols_, rows_);
        for (size_t i = 0; i < rows_; ++i)
        {
            for (size_t j = 0; j < cols_; ++j)
            {
                result.at(j, i) = at(i, j);
            }
        }
        return result;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m)
{
    for (size_t i = 0; i < m.rows(); ++i)
    {
        for (size_t j = 0; j < m.cols(); ++j)
        {
            os << m.at(i, j);
            if (j + 1 < m.cols()) os << " ";
        }
        os << "\n";
    }
    return os;
}

#endif
