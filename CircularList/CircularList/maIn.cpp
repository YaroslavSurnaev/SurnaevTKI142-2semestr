#include "CircularList.h"
#include <iostream>

/**
 * @brief Основная функция демонстрационной программы
 * @return 0 - успешное выполнение
 */
int main() {
    // Создание списка
    CircularList list = { 1, 2, 3 };
    std::cout << "Initial list: " << list.toString() << std::endl;

    // Добавление элементов
    list << 4 << 5;
    std::cout << "After adding: " << list.toString() << std::endl;

    // Удаление элемента
    list.remove(3);
    std::cout << "After removal: " << list.toString() << std::endl;

    // Извлечение элемента
    int val;
    list >> val;
    std::cout << "Extracted: " << val << std::endl;
    std::cout << "After extraction: " << list.toString() << std::endl;

    // Проверка на пустоту
    std::cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}