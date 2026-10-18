#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rsh)
{
    std::cout << "FragTrap asignment operator called" << std::endl;
    if (this != &rsh)
    {
        ClapTrap::operator=(rsh);   
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap yells: \"High-fives guys!!!\"" << std::endl;
}