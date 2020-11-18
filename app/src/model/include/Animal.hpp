#pragma once

#include <string>

#include "WeightClass.hpp"
#include "DietType.hpp"

class Animal {
private:
    std::string m_name;
    WeightClass m_weight;
    DietType m_diet;

    [[nodiscard]]
    bool EatsMeat() const;

public:
    Animal(std::string name, WeightClass weight, DietType diet)
        : m_name(std::move(name)), m_weight(weight), m_diet(diet)
    {}

    [[nodiscard]]
    bool IsCompatibleWith(const Animal& animal) const;

    [[nodiscard]]
    int GetVolume() const;

    [[nodiscard]]
    inline DietType GetDiet() const { return m_diet; }

    [[nodiscard]]
    inline WeightClass GetWeight() const { return m_weight; }

    [[nodiscard]]
    inline std::string GetName() const { return m_name; }

    [[nodiscard]]
    int GetPriority() const;
};
