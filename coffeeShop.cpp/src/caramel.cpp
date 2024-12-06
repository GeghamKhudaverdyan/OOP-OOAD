#include "../hpp/caramel.hpp"

Caramel::Caramel(Beverage* beverage) : AddOnDecorator(beverage) {}

std::string Caramel::getDescription() const  {
    return "Milk with " + m_bevarage->getDescription();
}

double Caramel::cost() const {
    return m_cost + m_bevarage->cost();
}