#include "../hpp/addOnDecorator.hpp"

AddOnDecorator::AddOnDecorator(Beverage* bevarage) : m_bevarage(bevarage) {}

std::string AddOnDecorator::getDescription() const  {
    return m_bevarage->getDescription();
}

double AddOnDecorator::cost() const {
    return m_bevarage->cost();
}
