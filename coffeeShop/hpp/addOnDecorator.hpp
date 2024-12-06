#pragma once

#include "beverage.hpp"

class AddOnDecorator : public Beverage {
public:
    explicit AddOnDecorator(Beverage* bevarage);
    virtual std::string getDescription() const override;
    virtual double cost() const override;

protected:
    Beverage* m_bevarage;
};