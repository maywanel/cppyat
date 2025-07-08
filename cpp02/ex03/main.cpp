#include <iostream>
#include "Point.hpp"

void test(Point const& p, std::string label, Point const& a, Point const& b, Point const& c) {
    std::cout << label << ": (" << p.getX() << ", " << p.getY() << ") → ";
    std::cout << (bsp(a, b, c, p) ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(2.5f, 5);

    test(Point(2.5f, 2), "Inside center", a, b, c);
    test(Point(0, 0),     "Corner A", a, b, c);
    test(Point(5, 0),     "Corner B", a, b, c);
    test(Point(2.5f, 5),  "Corner C", a, b, c);
    test(Point(2.5f, 0),  "Mid edge AB", a, b, c);
    test(Point(1.25f, 2.5f), "Mid edge AC", a, b, c);
    test(Point(3.75f, 2.5f), "Mid edge BC", a, b, c);
    test(Point(2.5f, 5.1f), "Just outside above", a, b, c);
    test(Point(2.5f, -0.1f), "Just below base", a, b, c);

    return 0;
}
