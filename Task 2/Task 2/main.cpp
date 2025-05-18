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
 * @brief Запрашивает и проверяет ввод числовой координаты с клавиатуры
 * @param coordinateName Приглашение для ввода, которое увидит пользователь
 * @return Введённое пользователем число типа double
 * @throw std::invalid_argument Если ввод не является числом или произошла ошибка чтения
 */
double getCoordinate(const std::string& coordinateName);

/**
 * @brief Основная функция программы.
 * Запрашивает координаты четырёх точек, создаёт квадрат и выводит его свойства.
 * @return 0 при успешном выполнении, 1 при ошибке.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "Введите координаты трех точек квадрата:\n";

        Point point1 = getPoint("1");
        Point point2 = getPoint("2");
        Point point3 = getPoint("3");

        Square square = Square(point1, point2, point3);

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
    std::cout << "Точка " << pointName << ":\n";
    double x = getCoordinate("x");
    double y = getCoordinate("y");
    return Point(x, y);
}

double getCoordinate(const std::string& coordinateName)
{
    std::cout << coordinateName << ": ";
    double value;
    std::cin >> value;
    if (std::cin.fail()) {
        throw std::invalid_argument("Некорректный ввод координаты " + coordinateName);
    }
    return value;
}