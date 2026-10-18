#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &copy) : AMateria(copy.type)
{}

Cure &Cure::operator=(const Cure &rsh)
{
	if (this != &rsh)
		AMateria::operator=(rsh);
	return *this;
}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}
