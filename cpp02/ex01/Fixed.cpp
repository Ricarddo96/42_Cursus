#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fb = 8;

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rsh)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rsh)
    {
        this->value = rsh.getRawBits();
    }  
    return *this;
}

Fixed::Fixed(const Fixed &copy)
{    
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int Constructor called" << std::endl;
    this->value = n << this->fb;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float Constructor called" << std::endl;
    this->value = roundf(f * (1 << this->fb)); // 1 << fb es lo mismo que 2^fb
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}
void Fixed::setRawBits( int const raw )
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)this->value / (1 << this->fb);
}

int Fixed::toInt( void ) const
{
    return this->value >> this->fb;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
} // por lo general en la implementacion de las funciones que son los operadores el primer parametro es el que esta a la izquierda del operador y el segundo el de la derecha