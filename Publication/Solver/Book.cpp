#include "Book.h"
#include <iostream>

Book::Book(const std::vector<Person>& auth, const std::string& t, int y,
    const Publisher& pub, const Person& ed)
    : authors(auth), title(t), year(y), publisher(pub), editor(ed) {}

std::string Book::ToString() const {
    std::ostringstream oss;
    oss << "Книга: " << title << "\nГод издания: " << year << "\nАвторы: ";
    for (const auto& author : authors) {
        oss << author << "; ";
    }
    oss << "\n" << publisher << "\nРедактор: " << editor;
    return oss.str();
}

Book Book::ReadFromStream(std::istream& is) {
    std::vector<Person> authors;
    std::string title;
    int year;
    Publisher publisher("", City("Москва"));
    Person editor("", "");

    std::cout << "Введите количество авторов: ";
    int authorCount;
    is >> authorCount;
    for (int i = 0; i < authorCount; ++i) {
        Person author("", "");
        std::cout << "Автор #" << i + 1 << ":\n";
        is >> author;
        authors.push_back(author);
    }

    std::cout << "Введите название книги: ";
    std::getline(is >> std::ws, title);

    std::cout << "Введите год издания: ";
    is >> year;

    std::cout << "Введите данные издательства:\n";
    is >> publisher;

    std::cout << "Введите данные редактора:\n";
    is >> editor;

    return Book(authors, title, year, publisher, editor);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.ToString();
    return os;
}