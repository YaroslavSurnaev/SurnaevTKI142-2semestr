#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "Square.h"

/**
 * @brief Конструктор квадрата по четырём точкам.
 * @param p1 Первая точка квадрата.
 * @param p2 Вторая точка квадрата.
 * @param p3 Третья точка квадрата.
 * @param p4 Четвёртая точка квадрата.
 * @throw std::logic_error Если точки не образуют квадрат или совпадают.
 */
Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : point1(p1), point2(p2), point3(p3), point4(p4)
{
    if (point1 == point2 || point1 == point3 || point1 == point4 ||
        point2 == point3 || point2 == point4 || point3 == point4) {
        throw std::logic_error("Все точки должны быть разными!");
    }

    validateSquare();

    side = calculateDistance(point1, point2);
}

/**
* @brief Вычисляет расстояние между двумя точками
* @param p1 Первая точка
* @param p2 Вторая точка
* @return Расстояние между точками
*/
double Square::calculateDistance(const Point& p1, const Point& p2) const
{
    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

/**
* @brief Проверяет, образуют ли точки корректный квадрат
* @throw std::logic_error Если точки не образуют квадрат
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
            throw std::logic_error("Точки не образуют квадрат: стороны не равны!");
        }
    }

    if (std::abs(distances[4] - distances[5]) >= epsilon) {
        throw std::logic_error("Точки не образуют квадрат: диагонали не равны!");
    }

    double expectedDiagonal = distances[0] * sqrt(2);
    if (std::abs(distances[4] - expectedDiagonal) >= epsilon) {
        throw std::logic_error("Точки не образуют квадрат: соотношение сторон и диагоналей неверное!");
    }
}

/**
 * @brief Вычисляет периметр квадрата.
 * @return Периметр квадрата.
 */
double Square::getPerimeter() const
{
    return 4 * side;
}

/**
 * @brief Вычисляет площадь квадрата.
 * @return Площадь квадрата.
 */
double Square::getArea() const
{
    return side * side;
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