#pragma once

#include "../hpp/addOnDecorator.hpp"   

class Caramel : public AddOnDecorator {
public:
    explicit Caramel(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual double cost() const override;

private:
    const double m_cost = 10;
};