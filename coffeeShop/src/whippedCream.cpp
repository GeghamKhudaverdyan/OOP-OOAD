#include "../hpp/whippedCream.hpp"

WhippedCream::WhippedCream(Beverage* beverage) : AddOnDecorator(beverage) {}

std::string WhippedCream::getDescription() const  {
    return "whippedCream " + m_bevarage->getDescription();
}

double WhippedCream::cost() const {
    return m_cost + m_bevarage->cost();
}