#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain("Dog");
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	this->brain = new Brain(*copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rsh)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rsh)
	{
		Animal::operator=(rsh);
		delete this->brain;
		this->brain = new Brain(*rsh.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}