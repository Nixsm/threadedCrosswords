#include <iostream>
#include "io.h"
#include "matrix.impl.h"
#include "worker.h"

int main(int argc, char** argv){
    int width, height;
    std::vector<std::string> map;

    // Reads a file
    IO::readFile(width, height, map);

    std::shared_ptr<Matrix<char> > crossword = std::make_shared<Matrix<char> >(width, height);
    std::shared_ptr<Matrix<bool> > visited = std::make_shared<Matrix<bool> >(width, height);

    for (auto i = 0; i < width; ++i) {
        for (auto j = 0; j < height; ++j) {
            crossword->set(i, j, map.at(i).at(j));
            visited->set(i, j, false);
        }
    }

    std::cout << *crossword << std::endl;

    Worker work('a', crossword, visited);
    return 0;
}
