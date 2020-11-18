#pragma once

#include <vector>
#include <memory>

#include "Animal.hpp"

class RailCar {
private:
    std::vector<Animal> m_animals;
    int m_size;
    int m_usedSpace = 0;

    [[nodiscard]]
    bool CanAddAnimal(const Animal &animal) const;

    [[nodiscard]]
    bool CanAnimalReplaceLowerPriorityAnimals(const Animal& animal) const;

public:
    explicit RailCar(int size)
        : m_size(size)
    {}

    [[nodiscard]]
    const auto& GetAnimals() const { return m_animals; }

    bool AddAnimal(Animal animal);

    [[nodiscard]]
    std::vector<Animal> ReplaceLowerPriorityAnimals(Animal animal);

    [[nodiscard]]
    inline int GetUsedSpace() const { return m_usedSpace; }
};
