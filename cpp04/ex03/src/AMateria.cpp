#include "../includes/AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type)
{}

AMateria::AMateria(const AMateria &copy) : type(copy.type)
{}

AMateria &AMateria::operator=(const AMateria &rsh)
{
    (void)rsh;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria::~AMateria()
{}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "implemented by son" << std::endl;
};