#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <limits>
#include "Square.h"

/**
 * @brief Конструктор квадрата по трём точкам.
 * @param p1 Первая точка квадрата.
 * @param p2 Вторая точка квадрата.
 * @param p3 Третья точка квадрата.
 */
Square::Square(const Point& p1, const Point& p2, const Point& p3)
    : point1(p1), point2(p2), point3(p3)
{
    point4 = calculateFourthPoint();
    validateSquare();
}

/**
* @brief Проверяет, образуют ли точки корректный квадрат
* @throw std::invalid_argument Если точки не образуют квадрат
*/
void Square::validateSquare()
{
    if (point1 == point2 || point1 == point3 || point1 == point4 ||
        point2 == point3 || point2 == point4 || point3 == point4)
    {
        throw std::invalid_argument("Точки квадрата должны быть разными");
    }

    // Вычисляем длины сторон и диагоналей
    double side1 = calculateDistance(point1, point2);
    double side2 = calculateDistance(point2, point3);
    double diagonal = calculateDistance(point1, point3);

    // Проверяем по теореме Пифагора (стороны равны и диагональ = сторона * √2)
    if (std::abs(side1 - side2) > std::numeric_limits<double>::epsilon() ||
        std::abs(diagonal - side1 * std::sqrt(2)) > std::numeric_limits<double>::epsilon())
    {
        throw std::invalid_argument("Точки не образуют квадрат");
    }

    sideLength = side1;
}

/**
* @brief Вычисляет четвертую точку квадрата по трем заданным
* @return Четвертая точка квадрата
*/
Point Square::calculateFourthPoint() const
{
    // Вычисляем вектор между точками 1 и 2
    double dx = point2.getX() - point1.getX();
    double dy = point2.getY() - point1.getY();

    // Поворачиваем вектор на 90 градусов и добавляем к точке 3
    return Point(point3.getX() - dy, point3.getY() + dx);
}

/**
* @brief Вычисляет расстояние между двумя точками
* @param p1 Первая точка
* @param p2 Вторая точка
* @return Расстояние между точками
*/
double Square::calculateDistance(const Point& p1, const Point& p2) const
{
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return std::sqrt(dx * dx + dy * dy);
}

/**
 * @brief Вычисляет периметр квадрата.
 * @return Периметр квадрата.
 */
double Square::getPerimeter() const
{
    return 4 * sideLength;
}

/**
 * @brief Вычисляет площадь квадрата.
 * @return Площадь квадрата.
 */
double Square::getArea() const
{
    return sideLength * sideLength;
}

/**
* @brief Выводит координаты вершин квадрата
*/
void Square::printPoints() const
{
    std::cout << "Точки квадрата:\n";
    std::cout << "1: (" << point1.getX() << ", " << point1.getY() << ")\n";
    std::cout << "2: (" << point2.getX() << ", " << point2.getY() << ")\n";
    std::cout << "3: (" << point3.getX() << ", " << point3.getY() << ")\n";
    std::cout << "4: (" << point4.getX() << ", " << point4.getY() << ")\n";
}