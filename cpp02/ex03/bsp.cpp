#include "Point.hpp"

long long zDir(Point const p1, Point const p2, Point const p3)
{
    long long bax = static_cast<long long>(p2.getX().getRawBits()) - p1.getX().getRawBits();
    long long bay = static_cast<long long>(p2.getY().getRawBits()) - p1.getY().getRawBits();
    long long pax = static_cast<long long>(p3.getX().getRawBits()) - p1.getX().getRawBits();
    long long pay = static_cast<long long>(p3.getY().getRawBits()) - p1.getY().getRawBits();

    return (bax * pay) - (bay * pax);
}

bool sameSign(long long r1, long long r2, long long r3)
{
    if ((r1 > 0 && r2 > 0 && r3 > 0) || (r1 < 0 && r2 < 0 && r3 < 0))
        return true;
    else 
        return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    long long resultABP = zDir(a, b, point);
    long long resultBCP = zDir(b, c, point);
    long long resultCAP = zDir(c, a, point);

    return sameSign(resultABP, resultBCP, resultCAP);
};