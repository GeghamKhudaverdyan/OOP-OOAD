#include "../hpp/tea.hpp"

std::string Tea::getDescription() const {
    return "Tea ";
}

double Tea::cost() const {
    return m_cost;
}