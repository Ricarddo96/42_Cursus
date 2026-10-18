#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{}
Ice::Ice(const Ice &copy) : AMateria(copy.type)
{}

Ice &Ice::operator=(const Ice &rsh)
{
    if (this != &rsh)
        AMateria::operator=(rsh);
    return *this;
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}