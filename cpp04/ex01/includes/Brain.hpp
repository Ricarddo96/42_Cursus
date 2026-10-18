#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

    public:

    Brain();
    Brain(std::string animal);
    Brain(const Brain &copy);
    Brain &operator=(const Brain &rsh);
    ~Brain();

    private:

    std::string ideas[100];
};

#endif