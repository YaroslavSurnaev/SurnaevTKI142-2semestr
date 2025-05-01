#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "Square.h"

/**
 * @brief ����������� �������� �� ������ ������.
 * @param p1 ������ ����� ��������.
 * @param p2 ������ ����� ��������.
 * @param p3 ������ ����� ��������.
 * @param p4 �������� ����� ��������.
 * @throw std::logic_error ���� ����� �� �������� ������� ��� ���������.
 */
Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : point1(p1), point2(p2), point3(p3), point4(p4)
{
    if (point1 == point2 || point1 == point3 || point1 == point4 ||
        point2 == point3 || point2 == point4 || point3 == point4) {
        throw std::logic_error("��� ����� ������ ���� �������!");
    }

    validateSquare();

    side = calculateDistance(point1, point2);
}

/**
* @brief ��������� ���������� ����� ����� �������
* @param p1 ������ �����
* @param p2 ������ �����
* @return ���������� ����� �������
*/
double Square::calculateDistance(const Point& p1, const Point& p2) const
{
    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

/**
* @brief ���������, �������� �� ����� ���������� �������
* @throw std::logic_error ���� ����� �� �������� �������
*/
void Square::validateSquare() const
{
    double distances[6];
    distances[0] = calculateDistance(point1, point2);
    distances[1] = calculateDistance(point1, point3);
    distances[2] = calculateDistance(point1, point4);
    distances[3] = calculateDistance(point2, point3);
    distances[4] = calculateDistance(point2, point4);
    distances[5] = calculateDistance(point3, point4);

    std::sort(distances, distances + 6);

    const double epsilon = std::numeric_limits<double>::epsilon() * 100;

    for (int i = 1; i < 4; ++i) {
        if (std::abs(distances[0] - distances[i]) >= epsilon) {
            throw std::logic_error("����� �� �������� �������: ������� �� �����!");
        }
    }

    if (std::abs(distances[4] - distances[5]) >= epsilon) {
        throw std::logic_error("����� �� �������� �������: ��������� �� �����!");
    }

    double expectedDiagonal = distances[0] * sqrt(2);
    if (std::abs(distances[4] - expectedDiagonal) >= epsilon) {
        throw std::logic_error("����� �� �������� �������: ����������� ������ � ���������� ��������!");
    }
}

/**
 * @brief ��������� �������� ��������.
 * @return �������� ��������.
 */
double Square::getPerimeter() const
{
    return 4 * side;
}

/**
 * @brief ��������� ������� ��������.
 * @return ������� ��������.
 */
double Square::getArea() const
{
    return side * side;
}

/**
* @brief ������� ���������� ������ ��������
*/
void Square::printPoints() const
{
    std::cout << "����� ��������:\n";
    std::cout << "1: (" << point1.getX() << ", " << point1.getY() << ")\n";
    std::cout << "2: (" << point2.getX() << ", " << point2.getY() << ")\n";
    std::cout << "3: (" << point3.getX() << ", " << point3.getY() << ")\n";
    std::cout << "4: (" << point4.getX() << ", " << point4.getY() << ")\n";
}