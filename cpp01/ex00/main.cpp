#include "Zombie.hpp"

int main()
{
    randomChump("The sticky zombie");
    Zombie* the_heap_zombie = newZombie("The hippie zombie");
    the_heap_zombie->announce();
    delete the_heap_zombie;
    return 0;
}