#include "Point.hpp"
#include "Fixed.hpp"


Point::Point() : x(0), y(0) 
{
};

Point::Point(const Point &copy) : x(copy.x), y(copy.y) 
{
};

Point::Point(const float xf, const float yf) : x(xf), y(yf)
{
};

Point &Point::operator=(const Point &b)
{
    (void)b;
    return *this;
};

Point::~Point()
{
};

Fixed const &Point::getX() const
{
    return this->x;
}

Fixed const &Point::getY() const
{
    return this->y;
}

