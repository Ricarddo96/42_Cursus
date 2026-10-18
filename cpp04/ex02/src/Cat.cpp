#include "../includes/Cat.hpp"
#include <iostream>
#include "../includes/Brain.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain("Cat");
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->brain = new Brain(*copy.brain); // le decimos "este objeto va a inicializar su brain, que va a ser una copia del brain de copy" // esto es deep copy una copia del objeto copiando el contenido tambien
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rsh)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rsh)
	{
		Animal::operator=(rsh);
		delete this->brain;
		this->brain = new Brain(*rsh.brain); //  aqui le decimos "este objeto ya tenia inicializado un brain pero lo vamos a borrar y lo vamos a sustituir por el de rsh"
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
