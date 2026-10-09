#include "Point.hpp"
#include <iostream>

static void test(const char *name, Point const &a, Point const &b, Point const &c,
                 Point const &p, bool expected)
{
    bool got = bsp(a, b, c, p);
    std::cout << name << ": " << (got ? "inside" : "outside")
              << " (expected " << (expected ? "inside" : "outside") << ")"
              << (got == expected ? " | OK |" : " | FAIL |") << std::endl;
}

int main()
{
    Point a(0.5f, 0.5f);
    Point b(9.5f, 0.5f);
    Point c(0.5f, 9.5f);

    test("inside",       a, b, c, Point(3.25f, 3.75f),  true);
    test("outside",      a, b, c, Point(8.125f, 8.25f), false);
    test("on vertex a",  a, b, c, Point(0.5f, 0.5f),    false);
    test("on vertex b",  a, b, c, Point(9.5f, 0.5f),    false);
    test("on edge ab",   a, b, c, Point(5.125f, 0.5f),  false);
    test("on edge ac",   a, b, c, Point(0.5f, 4.75f),   false);
    test("outside near", a, b, c, Point(0.25f, 3.125f), false);

    Point d(1.25f, 2.375f);
    Point e(7.875f, 1.125f);
    Point f(4.5f, 8.0625f);

    test("skew inside",  d, e, f, Point(4.125f, 3.5f),   true);
    test("skew outside", d, e, f, Point(9.75f, 6.25f),   false);
    test("skew vertex",  d, e, f, Point(1.25f, 2.375f),  false);

    return 0;
}
