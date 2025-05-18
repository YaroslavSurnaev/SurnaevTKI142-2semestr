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
    std::string middleName;
    std::string prefix;
    std::string suffix;

public:
    /**
     * @brief Конструктор персоны.
     * @param first Имя.
     * @param last Фамилия.
     * @param middle Отчество (по умолчанию "").
     * @param pref Префикс (по умолчанию "").
     * @param suff Суффикс (по умолчанию "").
     */
    Person(const std::string& first, const std::string& last,
        const std::string& middle = "", const std::string& pref = "",
        const std::string& suff = "");

    /**
     * @brief Возвращает полное имя персонажа.
     * @return std::string Полное имя в формате "Префикс Имя Отчество Фамилия Суффикс".
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

