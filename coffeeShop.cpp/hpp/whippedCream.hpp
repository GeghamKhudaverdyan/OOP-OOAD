#pragma once

#include "../hpp/addOnDecorator.hpp"   

class WhippedCream : public AddOnDecorator {
public:
    explicit WhippedCream(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual double cost() const override;

private:
    const double m_cost = 10;
};