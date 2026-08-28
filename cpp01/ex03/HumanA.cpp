#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon_a) : name(name), weapon_a(weapon_a)
{
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon_a.getType() << std::endl;
}

HumanA::~HumanA()
{
}