#include <gtest/gtest.h>
#include <model/include/Train.hpp>

TEST(TrainTests, TrainConfig1) {
    std::vector<Animal> animals = {
        Animal("Test1", WeightClass::Heavy, DietType::Carnivore),
        Animal("Test2", WeightClass::Medium, DietType::Herbivore),
        Animal("Test3", WeightClass::Heavy, DietType::Herbivore),
        Animal("Test4", WeightClass::Light, DietType::Herbivore),
        Animal("Test5", WeightClass::Heavy, DietType::Herbivore),
        Animal("Test6", WeightClass::Medium, DietType::Herbivore),
        Animal("Test7", WeightClass::Medium, DietType::Herbivore),
        Animal("Test8", WeightClass::Light, DietType::Herbivore),
        Animal("Test9", WeightClass::Light, DietType::Carnivore),
    };

    Train train(10);
    train.AddAnimals(animals);
    ASSERT_EQ(train.GetCars().size(), 4);
}

TEST(TrainTests, TrainConfig2) {
    std::vector<Animal> animals = {
            Animal("Test1", WeightClass::Medium, DietType::Herbivore),
            Animal("Test2", WeightClass::Medium, DietType::Herbivore),
            Animal("Test3", WeightClass::Medium, DietType::Herbivore),
            Animal("Test4", WeightClass::Light, DietType::Carnivore),
    };

    Train train(10);
    train.AddAnimals(animals);
    ASSERT_EQ(train.GetCars().size(), 1);
}

TEST(TrainTests, TrainConfig3) {
    std::vector<Animal> animals = {
            Animal("Test1", WeightClass::Heavy, DietType::Herbivore),
            Animal("Test2", WeightClass::Heavy, DietType::Herbivore),
            Animal("Test3", WeightClass::Medium, DietType::Herbivore),
            Animal("Test4", WeightClass::Medium, DietType::Carnivore),
    };

    Train train(10);
    train.AddAnimals(animals);
    ASSERT_EQ(train.GetCars().size(), 2);
}


TEST(TrainTests, TrainConfig3Redistrubute) {
    std::vector<Animal> animals = {
            Animal("Test1", WeightClass::Heavy, DietType::Herbivore),
            Animal("Test2", WeightClass::Heavy, DietType::Herbivore),
    };

    std::vector<Animal> animals2 = {
            Animal("Test3", WeightClass::Medium, DietType::Herbivore),
            Animal("Test4", WeightClass::Medium, DietType::Carnivore),
    };

    Train train(10);
    train.AddAnimals(animals);
    ASSERT_EQ(train.GetCars().size(), 1);
    train.AddAnimals(animals2);
    ASSERT_EQ(train.GetCars().size(), 2);
}


TEST(TrainTests, TestConfig4) {
    std::vector<Animal> animals = {
            Animal("Test1", WeightClass::Medium, DietType::Herbivore),
            Animal("Test2", WeightClass::Medium, DietType::Carnivore),
    };

    std::vector<Animal> animals2 = {
            Animal("Test3", WeightClass::Medium, DietType::Herbivore),
            Animal("Test4", WeightClass::Medium, DietType::Carnivore),
    };

    Train train(10);
    train.AddAnimals(animals);
    ASSERT_EQ(train.GetCars().size(), 2);
    train.AddAnimals(animals2);
    ASSERT_EQ(train.GetCars().size(), 3);
}

TEST(TrainTests, TrainConfig5) {
    std::vector<Animal> animals = {
            Animal("Test1", WeightClass::Heavy, DietType::Herbivore),
            Animal("Test2", WeightClass::Heavy, DietType::Herbivore),
            Animal("Test3", WeightClass::Medium, DietType::Herbivore),
            Animal("Test4", WeightClass::Medium, DietType::Herbivore),
            Animal("Test5", WeightClass::Medium, DietType::Herbivore),
            Animal("Test6", WeightClass::Light, DietType::Carnivore),
    };

    Train train(10);
    train.AddAnimals(animals);
    ASSERT_EQ(train.GetCars().size(), 2);
}
