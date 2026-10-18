#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

    public:

    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &rsh);
    virtual ~Animal(); // Sin virtual: destruyes un Dog con un Animal* → solo se llama a ~Animal() (no a ~Dog()). Con virtual: mira el tipo real del objeto (Dog) → llama a ~Dog() y después a los destructores de la cadena de padres (~Animal()).
    virtual void makeSound() const;
    std::string getType() const;

    protected:

    std::string type;
};

#endif
