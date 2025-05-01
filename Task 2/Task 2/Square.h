#pragma once
#include "Point.h"

/**
 * @brief класс, представляющий квадрат в двумерном пространстве.
 *  вадрат задается четырьм¤ точками и проходит проверку геометрических свойств.
 */
class Square
{
private:
    Point point1;
    Point point2;
    Point point3;
    Point point4;
    double side;

    void validateSquare() const;
    double calculateDistance(const Point& p1, const Point& p2) const;
public:
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    double getPerimeter() const;
    double getArea() const;
    void printPoints() const;
};