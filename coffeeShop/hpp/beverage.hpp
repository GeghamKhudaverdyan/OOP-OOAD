#pragma once

#include <string>

class Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Beverage() {}
};