#pragma once
#include "Point.h"

class Square
{
private:
    Point point1;
    Point point2;
    Point point3;
    double side1;
    double side2;
    void calculateSides();
public:
    Square(const Point& point1, const Point& point2, const Point& point3);
    double getPerimeter() const;
    double getArea() const;
};
