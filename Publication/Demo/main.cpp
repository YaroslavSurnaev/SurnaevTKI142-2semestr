#include <iostream>
#include <string>
#include "../Solver/Book.h"
#include "../Solver/City.h"

/**
* @brief Основная функция программы.
* @return 0 при успешном выполнении, 1 при ошибке.
*/
int main() {
    City::initCities();
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "Введите данные о книге:\n";
        Book book = Book::ReadFromStream(std::cin);

        std::cout << "\n»нформация о книге:\n";
        std::cout << book << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}