#include <iostream>
#include <fstream>
#include "io.h"

//////////////////////////////////////////////////////////
// inline bool fileExists(const std::string& filename){ //
//     return (access(filename.c_str(), F_OK) != -1);   //
// }                                                    //
//////////////////////////////////////////////////////////

void IO::readFile(int &width, int &height, std::vector<std::string> &map){
    std::string filename;
    std::ifstream infile;

    do {
        std::cout << "Filename: ";
        std::cin >> filename;

        // if (!fileExists(filename)){
        //     std::cout << "Error, file does not exist.\n";
        //     exit(1);
        // }

        infile.open(filename.c_str());

    } while (!infile.is_open());

    // get first line with w/h
    while (infile >> width >> height){
        break;
    };

    std::string dummyString;
    std::getline(infile, dummyString); // get rid of the first line.

    for (std::string line; getline(infile, line);){
        map.push_back(line);
    }
}
