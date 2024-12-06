#include "../hpp/espresso.hpp"

std::string Espresso::getDescription() const  {
    return "Espresso ";
}

double Espresso::cost() const {
    return m_cost;
}