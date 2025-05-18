#include <iostream>
#include <string>
#include <sstream>
#include "Person.h"

Person::Person(const std::string& first, const std::string& last)
    : firstName(first), lastName(last) {}

std::string Person::getFullName() const {
    return firstName + " " + lastName;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getFullName();
    return os;
}

std::istream& operator>>(std::istream& is, Person& person) {
    std::cout << "Введите имя: ";
    is >> person.firstName;
    std::cout << "Введите фамилию: ";
    is >> person.lastName;

    return is;
}