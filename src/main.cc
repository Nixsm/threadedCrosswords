#include <iostream>
#include "io.h"
#include "matrix.impl.h"
#include "worker.h"
#include <chrono>

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


    auto start = std::chrono::high_resolution_clock::now();

    //Worker work("threads", crossword);
    Worker work1("threads", crossword);
    Worker work2("arquivos", crossword);
    Worker work3("sinais", crossword);
    Worker work4("pipe", crossword);
    Worker work5("processos", crossword);
    Worker work6("mutex", crossword);

    work1.join();
    work2.join();
    work3.join();
    work4.join();
    work5.join();
    work6.join();

    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "took " << elapsed.count() << " microseconds." << std::endl;
    
    std::cout << *crossword << std::endl;
    return 0;
}
