#include <iostream>
#include <string>
#include "Point.h"
#include "Square.h"

double getCoordinate(std::string message);

int main()
{
    setlocale(LC_ALL, "Russian");
   
    auto x = getCoordinate("Введите координату x: ");
    auto y = getCoordinate("Введите координату y: ");
    Point point1(x, y);

    x = getCoordinate("Введите координату x: ");
    y = getCoordinate("Введите координату y: ");
    Point point2(x, y);

    x = getCoordinate("Введите координату x: ");
    y = getCoordinate("Введите координату y: ");
    Point point3(x, y);

    Square square(point1, point2, point3);
    std::cout << "Периметр квадрата равен " << square.getPerimeter() << std::endl;
    std::cout << "Площадь квадрата равна " << square.getArea() << std::endl;
    
    return 0;
}

double getCoordinate(std::string message)
{
    std::cout << message;
    double coordinate = 0.0;
    std::cin >> coordinate;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Введено некорректное значение");
    }
    return coordinate;
}