#include "../includes/Brain.hpp"
#include <string>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string animal)
{
	std::cout << "Brain default constructor called by " << animal << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &rsh)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &rsh)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rsh.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
