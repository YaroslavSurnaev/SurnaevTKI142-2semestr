#pragma once
#include <string>
#include <iostream>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    std::string prefix;
    std::string suffix;

public:
    Person(const std::string& first, const std::string& last,
        const std::string& middle = "", const std::string& pref = "",
        const std::string& suff = "");

    std::string getFullName() const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    friend std::istream& operator>>(std::istream& is, Person& person);
};

