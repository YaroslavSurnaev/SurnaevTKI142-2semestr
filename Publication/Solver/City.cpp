#include "City.h"

City::City(const std::string& cityName) : name(cityName) {}

std::string City::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
    os << city.name;
    return os;
}

std::istream& operator>>(std::istream& is, City& city) {
    std::getline(is >> std::ws, city.name); // Чтение всей строки (с пробелами)
    return is;
}
