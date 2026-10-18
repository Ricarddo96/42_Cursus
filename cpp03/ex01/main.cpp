#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Construction chaining =====" << std::endl;
	ScavTrap scav("SC4V-TP");

	std::cout << "\n===== ScavTrap actions =====" << std::endl;
	scav.attack("Bandit");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n===== Copy constructor =====" << std::endl;
	{
		ScavTrap copy(scav);
		copy.attack("Psycho");
		copy.guardGate();
	}
	std::cout << "(copy destroyed — ScavTrap destructor then ClapTrap destructor)" << std::endl;

	std::cout << "\n===== Assignment operator =====" << std::endl;
	{
		ScavTrap other("Temp");
		other = scav;
		other.attack("Skag");
	}

	std::cout << "\n===== ClapTrap still works =====" << std::endl;
	{
		ClapTrap clap("CL4P-TP");
		clap.attack("Dummy");
	}

	std::cout << "\n===== End of main (scav destruction) =====" << std::endl;
	return 0;
}
