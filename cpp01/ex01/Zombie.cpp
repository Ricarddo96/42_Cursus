#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("")
{
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie(void)
{
    std::cout << name << " destroyed" << std::endl;
}