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
    bool operator<(const Fixed &fixed) const;
    bool operator>(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    Fixed operator+(const Fixed &fixed) const;
    Fixed &operator+=(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed) const;
    Fixed &operator-=(const Fixed &fixed);
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;
    Fixed &operator++( void );
    Fixed &operator--( void );
    Fixed operator++( int );
    Fixed operator--( int );

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    private:

    int value; // fixed point value
    static const int fb; // fractional bits 
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif