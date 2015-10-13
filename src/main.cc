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

    for (auto i = 0; i < width; ++i) {
        for (auto j = 0; j < height; ++j) {
            crossword->set(i, j, map.at(i).at(j));
        }
    }

    std::cout << *crossword << std::endl;
    
    unsigned int numThreads;

    std::vector<std::string> words = {"threads", "arquivos", "sinais", "pipe", "processos", "mutex"};

    std::vector<std::shared_ptr<Worker> > workers;
    
    do {
        std::cout << "Numero de threads (Cada thread procura uma palavra)" << std::endl;
        std::cin >> numThreads;
    } while (!(numThreads - 1 < words.size() && numThreads > 0));

    auto start = std::chrono::high_resolution_clock::now();
    
    for (auto i = 0u; i <= words.size() - numThreads; i+=numThreads) {
        for (auto j = i; j < i + numThreads; ++j) {

            std::cout << j << " ";
            workers.push_back(std::make_shared<Worker>(words.at(j), crossword));
        }

        std::cout << std::endl;

        
        for (auto& worker : workers) {
            worker->join();
        }

        workers.clear();
    }

    if (numThreads > words.size() / 2) {
        for (auto i = numThreads; i < words.size(); ++i) {
            std::cout << i << "";
            workers.push_back(std::make_shared<Worker>(words.at(i), crossword));
        }
        std::cout << std::endl;
    }

    for (auto& worker : workers) {
        worker->join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "took " << elapsed.count() << " microseconds." << std::endl;
    
    std::cout << *crossword << std::endl;
    return 0;
}
