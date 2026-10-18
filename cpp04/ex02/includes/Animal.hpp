#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

    public:

    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &rsh);
    virtual ~Animal(); 
    virtual void makeSound() const = 0; // el virtual +  = 0 + implementar esa funcion en una clase hija , la convierte en una clase abstacta (solo para clases derivadas, no sirve para instanciarla)
    std::string getType() const;

    protected:

    std::string type;
};

#endif
