#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:

    Zombie();
    void announce(void);
    Zombie(std::string name);
    ~Zombie(void);

    private:
    
    std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif