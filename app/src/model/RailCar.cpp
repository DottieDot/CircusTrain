#include "include/RailCar.hpp"

#include <numeric>
#include <algorithm>

bool RailCar::CanAddAnimal(const Animal &animal) const {
    if ((m_usedSpace + animal.GetVolume()) > m_size) {
        return false;
    }

    return std::all_of(m_animals.begin(), m_animals.end(), [&](const auto& _animal) {
        return _animal.IsCompatibleWith(animal);
    });
}

bool RailCar::AddAnimal(Animal animal) {
    if (CanAddAnimal(animal)) {
        m_usedSpace += animal.GetVolume();
        m_animals.push_back(std::move(animal));
        return true;
    }

    return false;
}

bool RailCar::CanAnimalReplaceLowerPriorityAnimals(const Animal &animal) const {
    int result = std::accumulate(m_animals.begin(), m_animals.end(), 0, [=](int accumulator, const auto& _animal) {
        return accumulator += (animal.GetPriority() > _animal.GetPriority()) ? _animal.GetVolume() : 0;
    });
    return result != 0 && ((result + (m_size - m_usedSpace)) >= animal.GetVolume());
}

std::vector<Animal> RailCar::ReplaceLowerPriorityAnimals(Animal animal) {
    std::vector<Animal> result;
    if (CanAnimalReplaceLowerPriorityAnimals(animal)) {
        int totalVolumeRemoved = 0;
        for (auto it = m_animals.begin(); it != m_animals.end();) {
            if (animal.GetPriority() > it->GetPriority()) {
                totalVolumeRemoved += it->GetVolume();
                result.push_back(std::move(*it));
                it = m_animals.erase(it);
                if (totalVolumeRemoved >= animal.GetVolume() || it == m_animals.end()) {
                    break;
                }
            }
            else {
                ++it;
            }
        }
        m_usedSpace -= totalVolumeRemoved;
        AddAnimal(std::move(animal));
    }
    return result;
}
