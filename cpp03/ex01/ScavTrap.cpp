#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{   
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20); 
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) // le pasamos al constructor copia de la clase padre una ScavTrap porque al ser hija tambien es una Claptrap
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rsh)
{
    std::cout << "ScavTrap copy asignment operator called" << std::endl;
    if (this != &rsh)
    {
        ClapTrap::operator=(rsh);
    } 
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target) // usamos getters para acceder a los atributos private de la clase padre
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
			<< ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else if (this->getEnergyPoints() == 0)
		std::cout << "\033[31mScavTrap " << this->getName() << " is not able to attack " << target
			<< ", because he has no energy points left.\033[0m" << std::endl;
	else if (this->getHitPoints() == 0)
		std::cout << "\033[31mScavTrap " << this->getName() << " is not able to attack " << target
			<< ", because he has not enough hit points.\033[0m" << std::endl;
}