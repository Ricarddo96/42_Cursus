#include "Fixed.hpp"
#include <iostream>

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
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}