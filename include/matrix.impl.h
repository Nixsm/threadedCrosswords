#ifndef MATRIX_IMPL_H
#define MATRIX_IMPL_H

#include "matrix.h"

template<typename T> Matrix<T>::Matrix(const unsigned int& rows, const unsigned int& cols)
    :_data(std::vector<T>(rows * cols)), _rows(rows), _cols(cols)
{

}

template<typename T> bool Matrix<T>::valid( const unsigned int &x, const unsigned int &y ) const {
    if ((x >= 0 && x < _rows) && (y >= 0 && y < _cols))
        return true;

    return false;
}

template<typename T> bool Matrix<T>::valid( const Point2U &p ) const {
    if ((p.getX() >= 0 && p.getX() < _rows) && (p.getY() >= 0 && p.getY() < _cols))
        return true;

    return false;
}

template<typename T> T Matrix<T>::get( const unsigned int &x, const unsigned int &y ) const {
    return _data.at(_get2DIdx(x, y));
}

template<typename T> void Matrix<T>::set( const unsigned int &x, const unsigned int &y, const T &value ) {
    _data.at(_get2DIdx(x, y)) = value;
}


template<typename T> T Matrix<T>::get(const Point2U& point) const {
    return _data.at(_get2DIdx(point.getX(), point.getY()));
}

template<typename T> void Matrix<T>::set(const Point2U& point, const T &value ) {
    _data.at(_get2DIdx(point.getX(), point.getY())) = value;
}

template<typename T> unsigned int Matrix<T>::_get2DIdx(const unsigned int& x, const unsigned int& y) const {
    return (x * _cols) + y;
}


#endif//MATRIX_IMPL_H
