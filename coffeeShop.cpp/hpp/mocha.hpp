#pragma once

#include "../hpp/addOnDecorator.hpp"   

class Mocha : public AddOnDecorator {
public:
    explicit Mocha(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual double cost() const override;

private:
    const double m_cost = 10;
};