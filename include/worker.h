#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include "matrix.impl.h"
#include "point.impl.h"
#include <memory>

class Worker {
private:
    const Point2U NoDirection = Point2U(0, 0);
    const Point2U Up = Point2U(0, 1);
    const Point2U Down = Point2U(0, -1);
    const Point2U Right = Point2U(1, 0);
    const Point2U Left = Point2U(-1, 0);
    const Point2U UpRight = Up + Right;
    const Point2U UpLeft = Up + Left;
    const Point2U DownRight = Down + Right;
    const Point2U DownLeft = Down + Left;
public:
    Worker(const char& toSearch, const std::shared_ptr<Matrix<char> >& crossword, const std::shared_ptr<Matrix<bool> >& visited);

    void work();
private:
    std::shared_ptr<Matrix<char> > _crossword;
    std::shared_ptr<Matrix<bool> > _visited;
    char _search;
};

#endif//WORKER_H
