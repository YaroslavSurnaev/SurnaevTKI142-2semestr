#pragma once
#include "City.h"
#include <string>
#include <iostream>

/**
* @class Publisher
* @brief Класс, представляющий издательство.
*/
class Publisher {
private:
    std::string name;
    City city;

public:
    /**
     * @brief Конструктор издательства.
     * @param pubName Название издательства.
     * @param pubCity Город издательства.
     */
    Publisher(const std::string& pubName, const City& pubCity);

    /**
     * @brief Возвращает название издательства.
     * @return std::string Название.
     */
    std::string getName() const;

    /**
     * @brief Возвращает город издательства.
     * @return City Город.
     */
    City getCity() const;

    /**
     * @brief Сериализует издательство в строку.
     * @return std::string Строка в формате "Издательство: Название, Город: Город".
     */
    std::string ToString() const;

    /**
     * @brief Оператор вывода издательства в поток.
     * @param os Поток вывода.
     * @param publisher Издательство для вывода.
     * @return std::ostream& Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Publisher& publisher);

    /**
     * @brief Оператор ввода издательства из потока.
     * @param is Поток ввода.
     * @param publisher Издательство для заполнения.
     * @return std::istream& Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, Publisher& publisher);
};