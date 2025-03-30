#include <stdexcept>
#include <cmath>
#include "Square.h"

Square::Square(const Point& point1, const Point& point2, const Point& point3):
    point1(point1), point2(point2), point3(point3)
{
    if (point1 == point2 || point1 == point3 || point2 == point3)
    {
        throw std::logic_error("Points must be different!");
    }
    calculateSides();
}

void Square::calculateSides()
{
    side1 = sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2));
    side2 = sqrt(pow(point1.getX() - point3.getX(), 2) + pow(point1.getY() - point3.getY(), 2));

    if (side1 > side2)
    {
        std::swap(side1, side2);
    }
}

double Square::getPerimeter() const
{
    return 4 * side1;
}

double Square::getArea() const
{
    return side1 * side1;
}