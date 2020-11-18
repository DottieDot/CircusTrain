#include "include/Animal.hpp"

int Animal::GetVolume() const {
    switch (m_weight) {
        case WeightClass::Light:
            return 1;
        case WeightClass::Medium:
            return 3;
        case WeightClass::Heavy:
            return 5;
    }

    return 0;
}

bool Animal::IsCompatibleWith(const Animal &animal) const {
    if (EatsMeat()) {
        return
                (!animal.EatsMeat()) &&
                (GetVolume() < animal.GetVolume());
    }
    else if (animal.EatsMeat()) {
        return animal.IsCompatibleWith(*this);
    }

    return true;
}

bool Animal::EatsMeat() const {
    return
        (m_diet == DietType::Carnivore) ||
        (m_diet == DietType::Omnivore);
}

int Animal::GetPriority() const {
    if (GetWeight() == WeightClass::Light) {
        return GetVolume() + EatsMeat();
    }

    return GetVolume() + (EatsMeat() * 10);
}
