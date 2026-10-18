#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << "---Array---" << std::endl << std::endl;

	Animal* array[4];

	for(int k = 0; k < 4; k++)
	{
		if (k < 2)
		{
			array[k] = new Dog();
		} 
		else 
		{
			array[k] = new Cat;
		}
	}
	for(int k = 0 ; k < 4 ; k++)
	{
		delete array[k];
	}

	std::cout << std::endl;
	std::cout << "---Deep copy---" << std::endl << std::endl;

	Cat cat_base;
	{
		Cat cat_copy = cat_base;
	}
	// descomentar la linea siguiente para que se vea que con ella no compila
	// new Animal();
	return 0;
}
