#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include "matrix.impl.h"
#include "point.impl.h"
#include <memory>
#include <string>

class Worker {
public:
    Worker(const std::string& toSearch, const std::shared_ptr<Matrix<char> >& crossword);

    void work();
    void join();
private:
    std::shared_ptr<Matrix<char> > _crossword;
    std::shared_ptr<Matrix<bool> > _visited;
    std::string _search;
    std::thread _thread;
};

#endif//WORKER_H
