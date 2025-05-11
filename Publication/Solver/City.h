#pragma once
#include <string>
#include <set>
#include <iostream>

class City {
private:
    static std::set<std::string> availableCities;
    std::string name;

public:
    static void initCities();
    City(const std::string& cityName);

    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& os, const City& city);
    friend std::istream& operator>>(std::istream& is, City& city);
};
