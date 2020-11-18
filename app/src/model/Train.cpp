#include "include/Train.hpp"

#include <algorithm>

void Train::AddAnimal(Animal animal) {
    for (auto& car : m_cars) {
        if (car.AddAnimal(animal)) {
            return;
        }

        if (auto replaced = car.ReplaceLowerPriorityAnimals(animal); !replaced.empty()) {
            AddAnimals(std::move(replaced));
            return;
        }
    }

    auto& newCar = m_cars.emplace_back(m_carSize);
    newCar.AddAnimal(std::move(animal));
}

void Train::AddAnimals(std::vector<Animal> animals) {
    std::sort(animals.begin(), animals.end(), AnimalSorter);
    std::for_each(animals.begin(), animals.end(), [this](const auto& animal) {
        AddAnimal(animal);
    });
}

bool Train::AnimalSorter(const Animal &a, const Animal &b) {
    return a.GetPriority() > b.GetPriority();
}
