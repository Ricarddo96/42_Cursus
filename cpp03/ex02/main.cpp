#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== FragTrap construction chaining =====" << std::endl;
	FragTrap frag("FR4G-TP");

	std::cout << "\n===== FragTrap actions =====" << std::endl;
	frag.attack("Bandit");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "\n===== FragTrap copy constructor =====" << std::endl;
	{
		FragTrap copy(frag);
		copy.attack("Psycho");
		copy.highFivesGuys();
	}
	std::cout << "(copy destroyed — FragTrap dtor then ClapTrap dtor)" << std::endl;

	std::cout << "\n===== FragTrap assignment =====" << std::endl;
	{
		FragTrap other("Temp");
		other = frag;
		other.attack("Skag");
		other.highFivesGuys();
	}

	std::cout << "\n===== ScavTrap still works =====" << std::endl;
	{
		ScavTrap scav("SC4V-TP");
		scav.attack("Dummy");
		scav.guardGate();
	}

	std::cout << "\n===== ClapTrap still works =====" << std::endl;
	{
		ClapTrap clap("CL4P-TP");
		clap.attack("Target");
	}

	std::cout << "\n===== End of main (frag destruction) =====" << std::endl;
	return 0;
}
