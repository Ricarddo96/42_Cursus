#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:

    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int n);
    Fixed(const float f);
    Fixed &operator=(const Fixed &rsh); 
    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    private:

    int value; // fixed point value
    static const int fb; // fractional bits 
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif