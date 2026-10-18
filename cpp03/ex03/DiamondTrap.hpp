#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:

    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap &operator=(const DiamondTrap &rsh);
    ~DiamondTrap();
    void whoAmI();
    using ScavTrap::attack; // usamos la funcion attack de ScavTrap

    private:

    std::string _name;
};

#endif