#include <iostream>
#include <string>
#include <sstream>
#include "Publisher.h"

Publisher::Publisher(const std::string& pubName, const City& pubCity)
    : name(pubName), city(pubCity) {}

std::string Publisher::getName() const { return name; }
City Publisher::getCity() const { return city; }

std::string Publisher::ToString() const {
    std::ostringstream oss;
    oss << "Издательство: " << name << ", Город: " << city.getName();
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Publisher& publisher) {
    os << publisher.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, Publisher& publisher) {
    std::string name;
    City city("Москва");

    std::cout << "Введите название издательства: ";
    std::getline(is >> std::ws, name);
    std::cout << "Введите город издательства: ";
    is >> city;

    publisher = Publisher(name, city);
    return is;
}