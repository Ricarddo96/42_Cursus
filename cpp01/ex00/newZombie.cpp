#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* the_heap_zombie = new Zombie(name);
    return (the_heap_zombie);
}
