///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Christian Li <lichrist@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Weight.h"

int main() {
    Weight newWeight =  Weight(8);
    newWeight.dump();
    Weight newWeight2 = Weight(16, Weight::POUND, 16);
    newWeight2.dump();
    Weight newWeight3 = Weight(24, Weight::KILO, 24);
    newWeight3.dump();
    std::cout << newWeight2.getWeight(Weight::SLUG);
    std::cout << newWeight3.getWeight(Weight::SLUG);
    return false;

    /*
    Weight newWeight =  Weight(20);
    newWeight.dump();
    Weight newWeight2 = Weight(40, Weight::SLUG, 40);
    newWeight2.dump();
    std::cout << newWeight2.getWeight(Weight::POUND);
    return 0;

    Weight newWeight =  Weight(3);
    newWeight.dump();
    Weight newWeight2 = Weight(6, Weight::KILO, 6);
    newWeight2.dump();
    std::cout << newWeight2.getWeight(Weight::POUND);
    return 0;
    */
}
