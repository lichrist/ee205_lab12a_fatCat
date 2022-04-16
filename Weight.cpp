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
#include "Weight.h"
#include <cassert>
#include <iostream>

const float Weight::UNKNOWN_WEIGHT = -1 ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;

const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL = "Kilo";
const std::string Weight::SLUG_LABEL = "Slug";

Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    weight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    weight = newWeight;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
    weight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
    weight = newWeight;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = POUND;
    maxWeight = newMaxWeight;
    weight = newWeight;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = false;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = newMaxWeight;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    maxWeight = newMaxWeight;
}

bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}

float Weight::getWeight() const noexcept {
    return weight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    float currWeight = convertWeight(weight, unitOfWeight, weightUnits);
    return currWeight;
}

float Weight::getMaxWeight() const noexcept {
    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(float newWeight) {
    weight = newWeight;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    weight = newWeight;
    unitOfWeight = weightUnits;
}

void Weight::setMaxWeight(float newMaxWeight) {
    maxWeight = newMaxWeight;
}

bool Weight::isWeightValid(float checkWeight) const noexcept{
    if( bHasMax ){
        if(checkWeight > maxWeight){
            return false;
        }
    }
    if(checkWeight <= 0){
        return false;
    }
    return true;
}

bool Weight::validate() const noexcept {
    if(isWeightKnown()!= bIsKnown){
        return false;
    }
    if(hasMaxWeight() != bHasMax){
        return false;
    }
    if(bIsKnown){
        if(weight <= 0){
            return false;
        }
    }
    if(bHasMax){
        if(weight > maxWeight){
            return false;
        }
    }
    return true;
}
///////////////////////Conversion/////////////////////////
float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram/Weight::KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound*Weight::KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug/Weight::SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound*Weight::SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept{
    switch(fromUnit){
        case POUND:
            switch(toUnit){
                case POUND:
                    return fromWeight;
                case KILO:
                    return fromPoundToKilogram(fromWeight);
                case SLUG:
                    return fromPoundToSlug(fromWeight);
            }
        case KILO:
            switch(toUnit){
                case POUND:
                    return fromKilogramToPound(fromWeight);
                case KILO:
                    return fromWeight;
                case SLUG:
                    float pound = fromKilogramToPound(fromWeight);
                    return fromPoundToSlug(pound);
            }
        case SLUG:
            switch(toUnit){
                case SLUG:
                    return fromWeight;
                case POUND:
                    return fromSlugToPound(fromWeight);
                case KILO:
                    float pound = fromSlugToPound(fromWeight);
                    return fromPoundToKilogram(pound);
            }
    }
    return 0;
}

bool Weight::operator==(const Weight &rhs_Weight) const{
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const{
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=(float rhs_addToWeight){
    weight += rhs_addToWeight;
    return *this;
}

void Weight::dump() const noexcept{
    std::cout << "" << std::endl;
    std::cout << "Value of bIsKnown: " << bIsKnown << std::endl;
    std::cout << "Value of bHasMax: " << bHasMax << std::endl;
    std::cout << "Value of unitofWeight: " << unitOfWeight << std::endl;
    std::cout << "Value of Weight: " << weight << std::endl;
    std::cout << "Value of MaxWeight: " << maxWeight << std::endl;
}

std::ostream& operator<<(std::ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight){
    switch(rhs_UnitOfWeight){
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
    }
    return lhs_stream << Weight::POUND_LABEL ;
}