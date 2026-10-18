#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{    
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy._name),
      _hit_points(copy._hit_points),
      _energy_points(copy._energy_points),
      _attack_damage(copy._attack_damage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rsh)
{
    if (this != &rsh)
    {
        this->_attack_damage = rsh._attack_damage;
        this->_energy_points = rsh._energy_points;
        this->_hit_points = rsh._hit_points;
        this->_name = rsh._name;   
    }
    std::cout << "ClapTrap asignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
		std::cout << "\033[31m" << this->_name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "\033[31m" << this->_name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < this->_hit_points)
        this->_hit_points -= amount;
    else
    {
        this->_hit_points = 0;
        std::cout << "\033[31m" << this->_name << " is dead\033[0m" << std::endl;
        return;
    }
    std::cout << "\033[33mClapTrap " << this->_name << " has taken " << amount << " points of damage. Total HP: " << this->_hit_points << "\033[0m" << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points > 0 && this->_energy_points > 0)
    {
        this->_hit_points = amount;
        this->_energy_points--;
        std::cout << "\033[32mClapTrap " << this->_name << " repaired itself and gained " << amount << " of hit points. Total HP: " << this->_hit_points << "\033[0m" << std::endl;
    }
    else if (this->_hit_points == 0)
        std::cout << "\033[31m" << this->_name << " is dead. No repair available\033[0m" << std::endl;
    else if (this->_energy_points == 0) 
        std::cout << this->_name << " has 0 energy points. No repair available" << std::endl;
    // puede tener mas de 10 HP ??, supondré que si
};

unsigned int ClapTrap::getHitPoints() const
{
    return this->_hit_points;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return this->_energy_points;
}

std::string ClapTrap::getName() const
{
    return this->_name;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->_attack_damage;
}

void ClapTrap::setHitPoints(unsigned int hit_points)
{
    this->_hit_points = hit_points;
}

void ClapTrap::setEnergyPoints(unsigned int energy_points)
{
    this->_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(unsigned int attack_damage)
{
    this->_attack_damage = attack_damage;
}