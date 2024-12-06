#pragma once

#include "../hpp/addOnDecorator.hpp"   

class Milk : public AddOnDecorator {
public:
    explicit Milk(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual double cost() const override;

private:
    const double m_cost = 10;
};