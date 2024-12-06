#include <iostream>
#include "../hpp/beverage.hpp"
#include "../hpp/milk.hpp"
#include "../hpp/coffee.hpp"
#include "../hpp/milk.hpp"
#include "../hpp/sugar.hpp"
#include "../hpp/caramel.hpp"

void clientCode(Beverage* beverage) {
    std::cout << "Your " << beverage->getDescription();
    std::cout << "and cost is: " << beverage->cost();    
}

int main() {

    Beverage* beverage = new Coffee();
    beverage = new Milk(beverage);
    beverage = new Sugar(beverage);
    beverage = new Caramel(beverage);

    std::cout << beverage->getDescription() << "cost is: " << beverage->cost() << std::endl;


    return 0;
}