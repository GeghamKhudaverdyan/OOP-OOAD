#include "../hpp/sugar.hpp"

Sugar::Sugar(Beverage* beverage) : AddOnDecorator(beverage) {}

std::string Sugar::getDescription() const  {
    return "sugar " + m_bevarage->getDescription();
}

double Sugar::cost() const {
    return m_cost + m_bevarage->cost();
}