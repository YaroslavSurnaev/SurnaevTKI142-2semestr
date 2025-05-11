#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Person.h"
#include "Publisher.h"

class Book {
private:
    std::vector<Person> authors;
    std::string title;
    int year;
    Publisher publisher;
    Person editor;

public:
    Book(const std::vector<Person>& auth, const std::string& t, int y,
        const Publisher& pub, const Person& ed);

    std::string ToString() const;

    static Book ReadFromStream(std::istream& is);

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};