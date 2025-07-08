#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
    return Fixed((a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1 = area(point, a, b);
    Fixed d2 = area(point, b, c);
    Fixed d3 = area(point, c, a);
    bool isInside = (d1 > Fixed(0) && d2 > Fixed(0) && d3 > Fixed(0));
    if (isInside)
        return true;
    return false;
}
