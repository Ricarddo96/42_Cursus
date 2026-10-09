#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fb = 8;

Fixed::Fixed(): value(0)
{
}

Fixed &Fixed::operator=(const Fixed &rsh)
{
    if (this != &rsh)
    {
        this->value = rsh.getRawBits();
    }  
    return *this;
}

Fixed::Fixed(const Fixed &copy)
{    
    *this = copy;
}

Fixed::Fixed(const int n)
{
    this->value = n << this->fb;
}

Fixed::Fixed(const float f)
{
    this->value = roundf(f * (1 << this->fb));
}

Fixed::~Fixed() 
{
}

int Fixed::getRawBits( void ) const
{
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
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
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->value < fixed.value);
}

bool Fixed::operator>(const Fixed &fixed) const
{ 
    return (this->value > fixed.value);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->value <= fixed.value);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->value >= fixed.value);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->value == fixed.value);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->value != fixed.value);
}

Fixed &Fixed::operator+=(const Fixed &fixed)
{
    this->value = this->value + fixed.value;
    return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;
    result.value = this->value + fixed.value;
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;
    result.value = this->value - fixed.value;
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result;
    result.value = (this->value * fixed.value) / (1 << fb);
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result;
    result.value = (this->value * (1 << fb)) / fixed.value;
    return result;
}

Fixed &Fixed::operator-=(const Fixed &fixed)
{
    this->value = this->value - fixed.value;
    return *this;
}

Fixed &Fixed::operator++( void )
{
    this->value += 1;
    return *this;
}

Fixed &Fixed::operator--( void )
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed tmp(*this);
    ++this->value;
    return tmp;
}

Fixed Fixed::operator--( int )
{
    Fixed tmp(*this);
    --this->value;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.value < b.value)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.value > b.value)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.value < b.value)
        return a;
    return b;
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b)
{
    if (a.value > b.value)
        return a;
    return b;
}
