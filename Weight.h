///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Christian Li <lichrist@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H


class Weight {

public:
//////////////Enumerations/////////////////
    enum UnitOfWeight { POUND, KILO, SLUG};

    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

public:
    float getWeight() const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getUnitOfWeight() const noexcept;

private:
    float weight;
    float maxWeight;
    enum UnitOfWeight unitOfWeight;

public:
//////////////Constructors/////////////////
    Weight() noexcept;
    Weight(float newWeight);

};


#endif //EE205_LAB12A_FATCAT_WEIGHT_H
