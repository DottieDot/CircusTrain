#pragma once

#include <vector>
#include <algorithm>

#include "RailCar.hpp"

class Train {
private:
    std::vector<RailCar> m_cars;
    int m_carSize;

    static bool AnimalSorter(const Animal& a, const Animal& b);

public:
    explicit Train(int carSize)
        : m_carSize(carSize)
    {}

    void AddAnimal(Animal animal);

    void AddAnimals(std::vector<Animal> animals);

    [[nodiscard]]
    inline const auto& GetCars() const { return m_cars; }
};
