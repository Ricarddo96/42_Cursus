#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Harl harl;

    std::string input = "";
    
    if (argc != 2)
    {
        std::cerr << "Incorrect number of arguments, please enter just one level" << std::endl;
        return 1;
    }
    input = argv[1];
    
    harl.complain(input);
    
    return 0;
}