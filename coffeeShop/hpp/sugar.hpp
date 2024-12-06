#pragma once

#include "../hpp/addOnDecorator.hpp"   

class Sugar : public AddOnDecorator {
public:
    explicit Sugar(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual double cost() const override;

private:
    const double m_cost = 20;
};