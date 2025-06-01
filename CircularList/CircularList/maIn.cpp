#include "CircularList.h"
#include <iostream>

/**
 * @brief Основная функция демонстрационной программы
 * @return 0 - успешное выполнение
 */
int main() {
    // Тестирование конструктора копирования
    CircularList list1 = { 1, 2, 3 };
    CircularList list2 = list1;  // Копирование
    std::cout << "Original: " << list1.toString() << std::endl;
    std::cout << "Copy: " << list2.toString() << std::endl;

    // Тестирование перемещающего конструктора
    CircularList list3 = std::move(list1);
    std::cout << "After move:" << std::endl;
    std::cout << "Source: " << list1.toString() << std::endl;
    std::cout << "Destination: " << list3.toString() << std::endl;

    // Тестирование копирующего присваивания
    CircularList list4;
    list4 = list3;
    std::cout << "Copy assignment: " << list4.toString() << std::endl;

    // Тестирование перемещающего присваивания
    CircularList list5;
    list5 = std::move(list3);
    std::cout << "Move assignment:" << std::endl;
    std::cout << "Source: " << list3.toString() << std::endl;
    std::cout << "Destination: " << list5.toString() << std::endl;

    return 0;
}