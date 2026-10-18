#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap clap("Robot 1");

	clap.attack("Robot 2");
	clap.takeDamage(3);
	clap.beRepaired(2);

	clap.takeDamage(20);
	clap.attack("Robot 3");
	clap.beRepaired(5);

	ClapTrap copy(clap);
	ClapTrap assigned("Robot 4");
	assigned = copy;
	assigned.attack("Robot 5");

	return 0;
}
