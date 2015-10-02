#include "worker.h"

Worker::Worker(const char& toSearch, const std::shared_ptr<Matrix<char> >& crossword, const std::shared_ptr<Matrix<bool> >& visited)
    :_crossword(crossword), _visited(visited), _search(toSearch)
{
    std::thread t(&Worker::work, this);

    t.join();
}

void Worker::work() {
    std::cout << "I worked" << std::endl;
    std::cout << "I'm searching for " << _search << std::endl;

    std::cout << "My crossword is: " << std::endl;
    std::cout << *_crossword << std::endl;
}
