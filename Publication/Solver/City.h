#pragma once
#include <string>
#include <set>
#include <iostream>

/**
* @class City
* @brief Класс, представляющий город издательства.
*/
class City {
private:
    std::string name;

public:
    /**
     * @brief Конструктор города.
     * @param cityName Название города.
     */
    City(const std::string& cityName);

    /**
     * @brief Возвращает название города.
     * @return std::string Название города.
     */
    std::string getName() const;

    /**
     * @brief Оператор вывода города в поток.
     * @param os Поток вывода.
     * @param city Город для вывода.
     * @return std::ostream& Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const City& city);

    /**
     * @brief Оператор ввода города из потока.
     * @param is Поток ввода.
     * @param city Город для заполнения.
     * @return std::istream& Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, City& city);
};
