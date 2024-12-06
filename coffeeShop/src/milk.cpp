#include "../hpp/milk.hpp"

Milk::Milk(Beverage* beverage) : AddOnDecorator(beverage) {}

std::string Milk::getDescription() const  {
    return "Milk with " + m_bevarage->getDescription();
}

double Milk::cost() const {
    return m_cost + m_bevarage->cost();
}