#include <cmath>
#include <limits>
#include "Point.h"

/**
 * @brief оператор сравнения двух точек на равенство.
 * @param point1 первая точка для сравнения.
 * @param point2 вторая точка дл¤ сравнения.
 * @return true если точки равны, false в противном случае.
 */
bool operator==(const Point& point1, const Point& point2)
{
    return std::abs(point1.getX() - point2.getX()) <= std::numeric_limits<double>::epsilon()
        && std::abs(point1.getY() - point2.getY()) <= std::numeric_limits<double>::epsilon();
}

/**
 * @brief оператор сравнения двух точек на неравенство.
 * @param point1 первая точка дл¤ сравнения.
 * @param point2 вторая точка дл¤ сравнения.
 * @return true если точки не равны, false в противном случае.
 */
bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}

Point::Point(const double x, const double y):
    x(x), y(y)
{
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}