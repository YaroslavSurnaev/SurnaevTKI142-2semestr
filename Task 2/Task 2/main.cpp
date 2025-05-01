#include <iostream>
#include <string>
#include "Point.h"
#include "Square.h"

/**
 * @brief Получает координаты точки от пользователя.
 * @param pointName Название точки для отображения в приглашении.
 * @return Объект Point с введёнными координатами.
 * @throw std::invalid_argument Если введены некорректные координаты.
 */
Point getPoint(const std::string& pointName);

/**
 * @brief Основная функция программы.
 * Запрашивает координаты четырёх точек, создаёт квадрат и выводит его свойства.
 * @return 0 при успешном выполнении, 1 при ошибке.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        Point p1 = getPoint("1");
        Point p2 = getPoint("2");
        Point p3 = getPoint("3");
        Point p4 = getPoint("4");

        Square square(p1, p2, p3, p4);

        square.printPoints();
        std::cout << "Периметр: " << square.getPerimeter() << std::endl;
        std::cout << "Площадь: " << square.getArea() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

Point getPoint(const std::string& pointName)
{
    std::cout << "Введите координаты точки " << pointName << ":\n";
    std::cout << "x: ";
    double x;
    std::cin >> x;
    if (std::cin.fail()) {
        throw std::invalid_argument("Некорректное значение x");
    }

    std::cout << "y: ";
    double y;
    std::cin >> y;
    if (std::cin.fail()) {
        throw std::invalid_argument("Некорректное значение y");
    }

    return Point(x, y);
}