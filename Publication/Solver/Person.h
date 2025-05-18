#pragma once
#include <string>
#include <iostream>

/**
* @class Person
* @brief Класс, представляющий человека (автора или редактора).
*/
class Person {
private:
    std::string firstName;
    std::string lastName;

public:
    /**
     * @brief Конструктор персоны.
     * @param first Имя.
     * @param last Фамилия.
     */
    Person(const std::string& first, const std::string& last);

    /**
     * @brief Возвращает полное имя персонажа.
     * @return std::string Полное имя в формате "Имя Фамилия".
     */
    std::string getFullName() const;

    /**
     * @brief Оператор вывода персоны в поток.
     * @param os Поток вывода.
     * @param person Персона для вывода.
     * @return std::ostream& Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    /**
     * @brief Оператор ввода персоны из потока.
     * @param is Поток ввода.
     * @param person Персона для заполнения.
     * @return std::istream& Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, Person& person);
};

