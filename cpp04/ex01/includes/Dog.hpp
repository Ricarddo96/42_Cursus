#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{

    public:

    Dog();
    Dog(const Dog &copy);
    Dog &operator=(const Dog &rsh);
    ~Dog();
    void makeSound() const;

    private:

    Brain* brain;
};


#endif
