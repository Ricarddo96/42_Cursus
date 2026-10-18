#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== DiamondTrap construction chaining =====" << std::endl;
	DiamondTrap diamond("DI4MND");

	std::cout << "\n===== whoAmI =====" << std::endl;
	diamond.whoAmI();

	std::cout << "\n===== Inherited abilities =====" << std::endl;
	diamond.attack("Bandit");
	diamond.takeDamage(25);
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n===== Copy constructor =====" << std::endl;
	{
		DiamondTrap copy(diamond);
		copy.whoAmI();
		copy.attack("Psycho");
	}
	std::cout << "(copy destroyed — DiamondTrap → ScavTrap/FragTrap → ClapTrap)" << std::endl;

	std::cout << "\n===== Assignment operator =====" << std::endl;
	{
		DiamondTrap other("Temp");
		other = diamond;
		other.whoAmI();
		other.attack("Skag");
	}

	std::cout << "\n===== Parents still work =====" << std::endl;
	{
		FragTrap frag("FR4G-TP");
		frag.highFivesGuys();
		ScavTrap scav("SC4V-TP");
		scav.guardGate();
	}

	std::cout << "\n===== End of main (diamond destruction) =====" << std::endl;
	return 0;
}
