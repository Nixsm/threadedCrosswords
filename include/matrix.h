#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include "point.h"
#include "point.impl.h"

template<typename T> class Matrix {
public:
    Matrix() {}
    Matrix(const unsigned int& rows, const unsigned int& cols);
    
    void set(const unsigned int& x, const unsigned int& y, const T& value);
    void set(const Point2U& point, const T& value);
    
    T get(const unsigned int& x, const unsigned int& y) const;
    T get(const Point2U& point) const;

    bool valid(const unsigned int& x, const unsigned int& y) const;
    bool valid(const Point2U& p) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (unsigned i = 0; i < matrix._rows; ++i) {
            for (unsigned j = 0; j < matrix._cols; ++j) {
                os << matrix._data.at(matrix._get2DIdx(i, j));
            }
            os << std::endl;
        }

        return os;
    }

    unsigned int rows() {
        return _rows;
    }

    unsigned int cols() {
        return _cols;
    }

private:
    unsigned int _get2DIdx(const unsigned int& x, const unsigned int& y) const;
    
public:
    std::vector<T> _data;
    unsigned int _rows;
    unsigned int _cols;
};

#endif//MATRIX_H
