#include <cmath>
#include <limits>
#include "Point.h"

/**
 * @brief �������� ��������� ���� ����� �� ���������.
 * @param point1 ������ ����� ��� ���������.
 * @param point2 ������ ����� ��� ���������.
 * @return true ���� ����� �����, false � ��������� ������.
 */
bool operator==(const Point& point1, const Point& point2)
{
    return std::abs(point1.getX() - point2.getX()) <= std::numeric_limits<double>::epsilon()
        && std::abs(point1.getY() - point2.getY()) <= std::numeric_limits<double>::epsilon();
}

/**
 * @brief �������� ��������� ���� ����� �� �����������.
 * @param point1 ������ ����� ��� ���������.
 * @param point2 ������ ����� ��� ���������.
 * @return true ���� ����� �� �����, false � ��������� ������.
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