#pragma once

#include "beverage.hpp"

class Coffee : public Beverage {
public:
    virtual std::string getDescription() const override;
    virtual double cost() const override;

private:
    const double m_cost = 100;
};