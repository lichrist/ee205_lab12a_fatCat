///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Christian Li <lichrist@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>
#include "Weight.h"

Weight::Weight() noexcept{
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
}

Weight::Weight(float newWeight) {
    weight = newWeight;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const noexcept {
    return unitOfWeight;
}

float Weight::getWeight() const noexcept {
    return weight;
}

float Weight::getMaxWeight() const noexcept {
    return maxWeight;
}