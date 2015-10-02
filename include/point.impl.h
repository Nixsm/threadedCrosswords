#ifndef POINT_IMPL_H
#define POINT_IMPL_H

#include "point.h"


template<typename T> T Point<T>::getX() const {
    return _x;
}

template<typename T> T Point<T>::getY() const {
    return _y;
}

template<typename T> void Point<T>::setX(const T& x) {
    _x = x;
}

template<typename T> void Point<T>::setY(const T& y) {
    _y = y;
}

template<typename T> bool Point<T>::operator==( const Point<T> &other ) {
    return getX() == other.getX() && getY() == other.getY();
}

template<typename T> void Point<T>::addX(const T& x) {
    _x += x;
}

template<typename T> void Point<T>::addY(const T& y) {
    _y += y;
}

    


#endif//POINT_IMPL_H
