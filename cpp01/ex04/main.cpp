#include <fstream>
#include <iostream>
#include <string>


#include "LoserSed.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4 || !argv[1] || !argv[2] || !argv[3] || !argv[1][0] || !argv[2][0])
    {
        std::cerr << "Error: Incorrect number of arguments" << std::endl
        << "Usage: ./loser_sed <file> <s1> <s2>" << std::endl;
        return 1;
    }
    LoserSed loser(argv[1], argv[2], argv[3]);
    loser.newFile();
    return 0;
}