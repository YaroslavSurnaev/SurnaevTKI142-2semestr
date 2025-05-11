#include <iostream>
#include <string>
#include <sstream>
#include "Person.h"

Person::Person(const std::string& first, const std::string& last,
    const std::string& middle, const std::string& pref,
    const std::string& suff)
    : firstName(first), lastName(last), middleName(middle), prefix(pref), suffix(suff) {}

std::string Person::getFullName() const {
    std::ostringstream oss;
    if (!prefix.empty()) oss << prefix << " ";
    oss << firstName << " ";
    if (!middleName.empty()) oss << middleName << " ";
    oss << lastName;
    if (!suffix.empty()) oss << " " << suffix;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getFullName();
    return os;
}

std::istream& operator>>(std::istream& is, Person& person) {
    std::string first, last, middle, pref, suff;
    std::cout << "Введите имя: ";
    is >> first;
    std::cout << "Введите фамилию: ";
    is >> last;
    std::cout << "Введите отчество (если есть): ";
    std::getline(is >> std::ws, middle);
    std::cout << "Введите префикс (если есть): ";
    std::getline(is >> std::ws, pref);
    std::cout << "Введите постфикс (если есть): ";
    std::getline(is >> std::ws, suff);

    person = Person(first, last, middle, pref, suff);
    return is;
}