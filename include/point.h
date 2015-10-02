#ifndef POINT_H
#define POINT_H

#include <iostream>


template<typename T> class Point {
public:
    Point() { }
    Point(const T& x, const T& y)
        :_x(x), _y(y)
    {
        
    }

    T getX() const;
    T getY() const;

    void setX(const T& x);
    void setY(const T& y);

    void addX(const T& x);
    void addY(const T& y);
    
    bool operator==(const Point<T>& other);

    friend Point<T> operator-(const Point<T>& p1, const Point<T>& p2) {
        Point<T> p(p1._x - p2._x, p1._y - p2._y);

        return p;
    }

    friend Point<T> operator+(const Point<T>& p1, const Point<T>& p2) {
        Point<T> p(p1._x + p2._x, p1._y + p2._y);

        return p;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& other) {
        os << "[ " << other._x << ", " << other._y << " ]";
        return os;
    }
private:
    T _x;
    T _y;
};

typedef Point<unsigned int> Point2U;

#endif//POINT_H
