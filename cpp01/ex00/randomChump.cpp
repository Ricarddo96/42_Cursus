#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie the_stack_zombie(name);
    the_stack_zombie.announce();
}