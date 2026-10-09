#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

    public:

    Point();
    Point(const Point &copy);
    Point(const float xf, const float yf);
    Point &operator=(const Point &b);
    ~Point();
    Fixed const &getX() const;
    Fixed const &getY() const;
    
    private:

    Fixed const x;
    Fixed const y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
