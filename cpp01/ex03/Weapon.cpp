#include "Weapon.hpp"
#include <string>

void Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string &Weapon::getType() const
{
    return this->type; //this es un puntero al objeto actual, al que está llamando este método
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}
