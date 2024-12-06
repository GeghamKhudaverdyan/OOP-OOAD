#include "../hpp/mocha.hpp"

Mocha::Mocha(Beverage* beverage) : AddOnDecorator(beverage) {}

std::string Mocha::getDescription() const  {
    return "Mocha " + m_bevarage->getDescription();
}

double Mocha::cost() const {
    return m_cost + m_bevarage->cost();
}