#pragma once
#include "City.h"
#include <string>
#include <iostream>

class Publisher {
private:
    std::string name;
    City city;

public:
    Publisher(const std::string& pubName, const City& pubCity);

    std::string getName() const;
    City getCity() const;

    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream& os, const Publisher& publisher);
    friend std::istream& operator>>(std::istream& is, Publisher& publisher);
};