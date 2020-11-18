#include <gtest/gtest.h>
#include <model/include/RailCar.hpp>

TEST(RailCarTests, AddAnimal_EmptyCar_Success) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);

    RailCar car(heavy.GetVolume());

    ASSERT_TRUE(car.AddAnimal(heavy));
    ASSERT_EQ(car.GetUsedSpace(), heavy.GetVolume());
}


TEST(RailCarTests, AddAnimal_FreeSpace_Success) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);

    RailCar car(heavy.GetVolume() * 2);
    car.AddAnimal(heavy);

    ASSERT_TRUE(car.AddAnimal(heavy));
    ASSERT_EQ(car.GetUsedSpace(), heavy.GetVolume() * 2);
}

TEST(RailCarTests, AddAnimal_NotEnoughSpace_Failure) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);

    RailCar car(heavy.GetVolume() + heavy.GetVolume() - 1);
    car.AddAnimal(heavy);

    ASSERT_FALSE(car.AddAnimal(heavy));
    ASSERT_EQ(car.GetUsedSpace(), heavy.GetVolume());
}

TEST(RailCarTests, AddAnimal_Full_Failure) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);

    RailCar car(heavy.GetVolume());
    car.AddAnimal(heavy);

    ASSERT_FALSE(car.AddAnimal(heavy));
    ASSERT_EQ(car.GetUsedSpace(), heavy.GetVolume());
}

TEST(RailCarTests, AddAnimal_Incompatible_Failure) {
    Animal herbivore("", WeightClass::Heavy, DietType::Herbivore);
    Animal carnivore("", WeightClass::Heavy, DietType::Carnivore);

    RailCar car(herbivore.GetVolume() + carnivore.GetVolume());
    car.AddAnimal(herbivore);

    ASSERT_FALSE(car.AddAnimal(carnivore));
    ASSERT_EQ(car.GetUsedSpace(), herbivore.GetVolume());
}

TEST(RailCarTests, ReplaceLowerPriorityAnimal_ReplaceHerbivoreWithCarnivore_Success) {
    Animal herbivore("", WeightClass::Heavy, DietType::Herbivore);
    Animal carnivore("", WeightClass::Heavy, DietType::Carnivore);

    RailCar car(herbivore.GetVolume());
    car.AddAnimal(herbivore);

    ASSERT_FALSE(car.ReplaceLowerPriorityAnimals(carnivore).empty());
    ASSERT_EQ(car.GetUsedSpace(), carnivore.GetVolume());
}

TEST(RailCarTests, ReplaceLowerPriorityAnimal_ReplaceCarnivoreWithHerbivore_Failure) {
    Animal herbivore("", WeightClass::Heavy, DietType::Herbivore);
    Animal carnivore("", WeightClass::Heavy, DietType::Carnivore);

    RailCar car(herbivore.GetVolume());
    car.AddAnimal(carnivore);

    ASSERT_TRUE(car.ReplaceLowerPriorityAnimals(herbivore).empty());
    ASSERT_EQ(car.GetUsedSpace(), herbivore.GetVolume());
}

TEST(RailCarTests, ReplaceLowerPriorityAnimal_ReplaceMultipleLightHerbivoresWithHeavyHerbivore_Success) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);
    Animal light("", WeightClass::Light, DietType::Herbivore);

    RailCar car(heavy.GetVolume());
    for (int i = 0; i < (heavy.GetVolume() / light.GetVolume()); ++i) {
        car.AddAnimal(light);
    }

    ASSERT_EQ(car.ReplaceLowerPriorityAnimals(heavy).size(), (heavy.GetVolume() / light.GetVolume()));
    ASSERT_EQ(car.GetUsedSpace(), heavy.GetVolume());
}


TEST(RailCarTests, ReplaceLowerPriorityAnimal_ReplaceMultipleLightHerbivoresAndEmptySpaceWithHeavyHerbivore_Success) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);
    Animal light("", WeightClass::Light, DietType::Herbivore);

    RailCar car(heavy.GetVolume());
    for (int i = 0; i < 2; ++i) {
        car.AddAnimal(light);
    }

    ASSERT_EQ(car.ReplaceLowerPriorityAnimals(heavy).size(), 2);
    ASSERT_EQ(car.GetUsedSpace(), heavy.GetVolume());
}

TEST(RailCarTests, ReplaceLowerPriorityAnimal_ReplaceNotEnoughLightHerbivoresWithHeavyHerbivore_Failure) {
    Animal heavy("", WeightClass::Heavy, DietType::Herbivore);
    Animal light("", WeightClass::Light, DietType::Herbivore);

    RailCar car(3);
    for (int i = 0; i < 3; ++i) {
        car.AddAnimal(light);
    }

    ASSERT_EQ(car.ReplaceLowerPriorityAnimals(heavy).size(), 0);
    ASSERT_EQ(car.GetUsedSpace(), 3);
}
