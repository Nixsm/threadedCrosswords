#ifndef IO_H
#define IO_H

#include <vector>
#include <string>
#include <fstream>

class IO {
public:
    
    static void readFile(int &, int &, std::vector<std::string> &);
private:
    //inline bool fileExists(const std::ifstream &);
};
#endif//IO_H
