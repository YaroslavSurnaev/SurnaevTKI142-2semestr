#include "City.h"

std::set<std::string> City::availableCities;

void City::initCities() {
    availableCities = { "Москва", "Saint-Petersburg", "Novosibirsk", "Ekaterinburg", "Kazan" };
}

City::City(const std::string& cityName)
{
    if (availableCities.find(cityName) == availableCities.end()) {
        throw std::invalid_argument("Город не найден в списке доступных");
    }
    name = cityName;
}

std::string City::getName() const { return name; }

std::ostream& operator<<(std::ostream& os, const City& city) {
    os << city.name;
    return os;
}

std::istream& operator>>(std::istream& is, City& city) {
    std::string cityName;
    is >> cityName;
    city = City(cityName);
    return is;
}
