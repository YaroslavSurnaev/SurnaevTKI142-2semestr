#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Person.h"
#include "Publisher.h"

/**
 * @class Book
 * @brief Класс, представляющий книгу.
 */
class Book {
private:
    std::vector<Person> authors;
    std::string title;
    int year;
    Publisher publisher;
    Person editor;

public:
    /**
     * @brief Конструктор книги.
     * @param auth Список авторов.
     * @param t Название.
     * @param y Год издания.
     * @param pub Издательство.
     * @param ed Редактор.
     */
    Book(const std::vector<Person>& auth, const std::string& t, int y,
        const Publisher& pub, const Person& ed);

    /**
     * @brief Сериализует книгу в строку.
     * @return std::string Информация о книге в формате:
     *         "Книга: Название\nГод: Год\nАвторы: ...\nИздательство: ...\nРедактор: ...".
     */
    std::string ToString() const;

    /**
     * @brief Создает книгу из потока ввода.
     * @param is Поток ввода (например, std::cin).
     * @return Book Объект книги.
     */
    static Book ReadFromStream(std::istream& is);

    /**
     * @brief Оператор вывода книги в поток.
     * @param os Поток вывода.
     * @param book Книга для вывода.
     * @return std::ostream& Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};