#include "../hpp/coffee.hpp"

std::string Coffee::getDescription() const  {
    return "Coffee ";
}

double Coffee::cost() const {
    return m_cost;
}