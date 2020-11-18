#include <gtest/gtest.h>
#include <model/include/Animal.hpp>

TEST(AnimalTests, CtorAndGetters) {
    Animal animal("Test", WeightClass::Medium, DietType::Herbivore);

    ASSERT_EQ(animal.GetName(), "Test");
    ASSERT_EQ(animal.GetWeight(), WeightClass::Medium);
    ASSERT_EQ(animal.GetDiet(), DietType::Herbivore);
}

TEST(AnimalTests, IsCompatibleWith_LightAndLightHerbivores_Compatible) {
    Animal light1("Light1", WeightClass::Light, DietType::Herbivore);
    Animal light2("Light2", WeightClass::Light, DietType::Herbivore);

    ASSERT_TRUE(light1.IsCompatibleWith(light2));
    ASSERT_TRUE(light2.IsCompatibleWith(light1));
}

TEST(AnimalTests, IsCompatibleWith_LightAndMediumHerbivores_Compatible) {
    Animal medium("Medium", WeightClass::Medium, DietType::Herbivore);
    Animal light("Light", WeightClass::Light, DietType::Herbivore);

    ASSERT_TRUE(medium.IsCompatibleWith(light));
    ASSERT_TRUE(light.IsCompatibleWith(medium));
}

TEST(AnimalTests, IsCompatibleWith_LightAndHeavyHerbivores_Compatible) {
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Herbivore);
    Animal light("Light", WeightClass::Light, DietType::Herbivore);

    ASSERT_TRUE(heavy.IsCompatibleWith(light));
    ASSERT_TRUE(light.IsCompatibleWith(heavy));
}

TEST(AnimalTests, IsCompatibleWith_MediumAndLightHerbivores_Compatible) {
    Animal light("Light", WeightClass::Light, DietType::Herbivore);
    Animal medium("Light", WeightClass::Medium, DietType::Herbivore);

    ASSERT_TRUE(light.IsCompatibleWith(medium));
    ASSERT_TRUE(medium.IsCompatibleWith(light));
}

TEST(AnimalTests, IsCompatibleWith_MediumAndMediumHerbivores_Compatible) {
    Animal medium1("Medium1", WeightClass::Medium, DietType::Herbivore);
    Animal medium2("Medium2", WeightClass::Medium, DietType::Herbivore);

    ASSERT_TRUE(medium1.IsCompatibleWith(medium2));
    ASSERT_TRUE(medium2.IsCompatibleWith(medium1));
}

TEST(AnimalTests, IsCompatibleWith_MediumAndHeavyHerbivores_Compatible) {
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Herbivore);
    Animal medium("Medium", WeightClass::Medium, DietType::Herbivore);

    ASSERT_TRUE(heavy.IsCompatibleWith(medium));
    ASSERT_TRUE(medium.IsCompatibleWith(heavy));
}

TEST(AnimalTests, IsCompatibleWith_HeavyAndLightHerbivores_Compatible) {
    Animal light("Light", WeightClass::Light, DietType::Herbivore);
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Herbivore);

    ASSERT_TRUE(light.IsCompatibleWith(heavy));
    ASSERT_TRUE(heavy.IsCompatibleWith(light));
}

TEST(AnimalTests, IsCompatibleWith_HeavyAndMediumHerbivores_Compatible) {
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Herbivore);
    Animal medium("Medium", WeightClass::Medium, DietType::Herbivore);

    ASSERT_TRUE(heavy.IsCompatibleWith(medium));
    ASSERT_TRUE(medium.IsCompatibleWith(heavy));
}

TEST(AnimalTests, IsCompatibleWith_HeavyAndHeavyHerbivores_Compatible) {
    Animal heavy1("Heavy1", WeightClass::Heavy, DietType::Herbivore);
    Animal heavy2("Heavy2", WeightClass::Medium, DietType::Herbivore);

    ASSERT_TRUE(heavy1.IsCompatibleWith(heavy2));
    ASSERT_TRUE(heavy2.IsCompatibleWith(heavy1));
}

TEST(AnimalTests, IsCompatibleWith_LightAndLightCarnivores_Incompatible) {
    Animal light1("Light1", WeightClass::Light, DietType::Carnivore);
    Animal light2("Light2", WeightClass::Light, DietType::Carnivore);

    ASSERT_FALSE(light1.IsCompatibleWith(light2));
    ASSERT_FALSE(light2.IsCompatibleWith(light1));
}

TEST(AnimalTests, IsCompatibleWith_LightAndMediumCarnivores_Incompatible) {
    Animal medium("Medium", WeightClass::Medium, DietType::Carnivore);
    Animal light("Light", WeightClass::Light, DietType::Carnivore);

    ASSERT_FALSE(medium.IsCompatibleWith(light));
    ASSERT_FALSE(light.IsCompatibleWith(medium));
}

TEST(AnimalTests, IsCompatibleWith_LightAndHeavyCarnivores_Incompatible) {
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Carnivore);
    Animal light("Light", WeightClass::Light, DietType::Carnivore);

    ASSERT_FALSE(heavy.IsCompatibleWith(light));
    ASSERT_FALSE(light.IsCompatibleWith(heavy));
}

TEST(AnimalTests, IsCompatibleWith_MediumAndLightCarnivores_Incompatible) {
    Animal light("Light", WeightClass::Light, DietType::Carnivore);
    Animal medium("Light", WeightClass::Medium, DietType::Carnivore);

    ASSERT_FALSE(light.IsCompatibleWith(medium));
    ASSERT_FALSE(medium.IsCompatibleWith(light));
}

TEST(AnimalTests, IsCompatibleWith_MediumAndMediumCarnivores_Incompatible) {
    Animal medium1("Medium1", WeightClass::Medium, DietType::Carnivore);
    Animal medium2("Medium2", WeightClass::Medium, DietType::Carnivore);

    ASSERT_FALSE(medium1.IsCompatibleWith(medium2));
    ASSERT_FALSE(medium2.IsCompatibleWith(medium1));
}

TEST(AnimalTests, IsCompatibleWith_MediumAndHeavyCarnivores_Incompatible) {
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Carnivore);
    Animal medium("Medium", WeightClass::Medium, DietType::Carnivore);

    ASSERT_FALSE(heavy.IsCompatibleWith(medium));
    ASSERT_FALSE(medium.IsCompatibleWith(heavy));
}

TEST(AnimalTests, IsCompatibleWith_HeavyAndLightCarnivores_Incompatible) {
    Animal light("Light", WeightClass::Light, DietType::Carnivore);
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Carnivore);

    ASSERT_FALSE(light.IsCompatibleWith(heavy));
    ASSERT_FALSE(heavy.IsCompatibleWith(light));
}

TEST(AnimalTests, IsCompatibleWith_HeavyAndMediumCarnivores_Incompatible) {
    Animal heavy("Heavy", WeightClass::Heavy, DietType::Carnivore);
    Animal medium("Medium", WeightClass::Medium, DietType::Carnivore);

    ASSERT_FALSE(heavy.IsCompatibleWith(medium));
    ASSERT_FALSE(medium.IsCompatibleWith(heavy));
}

TEST(AnimalTests, IsCompatibleWith_HeavyAndHeavyCarnivores_Incompatible) {
    Animal heavy1("Heavy1", WeightClass::Heavy, DietType::Carnivore);
    Animal heavy2("Heavy2", WeightClass::Medium, DietType::Carnivore);

    ASSERT_FALSE(heavy1.IsCompatibleWith(heavy2));
    ASSERT_FALSE(heavy2.IsCompatibleWith(heavy1));
}

TEST(AnimalTests, CompatibilitySize) {
    Animal carnivore("", WeightClass::Medium, DietType::Carnivore);
    Animal lightHerbivore("", WeightClass::Light, DietType::Herbivore);
    Animal mediumHerbivore("", WeightClass::Medium, DietType::Herbivore);
    Animal heavyHerbivore("", WeightClass::Heavy, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(lightHerbivore));
    ASSERT_FALSE(carnivore.IsCompatibleWith(mediumHerbivore));
    ASSERT_TRUE(carnivore.IsCompatibleWith(heavyHerbivore));

    ASSERT_FALSE(lightHerbivore.IsCompatibleWith(carnivore));
    ASSERT_FALSE(mediumHerbivore.IsCompatibleWith(carnivore));
    ASSERT_TRUE(heavyHerbivore.IsCompatibleWith(carnivore));

    ASSERT_FALSE(carnivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_LightCarnivoreLightHerbivore_Incompatible) {
    Animal carnivore("", WeightClass::Light, DietType::Carnivore);
    Animal herbivore("", WeightClass::Light, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_FALSE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_LightCarnivoreMediumHerbivore_Compatible) {
    Animal carnivore("", WeightClass::Light, DietType::Carnivore);
    Animal herbivore("", WeightClass::Medium, DietType::Herbivore);

    ASSERT_TRUE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_TRUE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_LightCarnivoreHeavyHerbivore_Compatible) {
    Animal carnivore("", WeightClass::Light, DietType::Carnivore);
    Animal herbivore("", WeightClass::Heavy, DietType::Herbivore);

    ASSERT_TRUE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_TRUE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_MediumCarnivoreLightHerbivore_Incompatible) {
    Animal carnivore("", WeightClass::Medium, DietType::Carnivore);
    Animal herbivore("", WeightClass::Light, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_FALSE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_MediumCarnivoreMediumHerbivore_Incompatible) {
    Animal carnivore("", WeightClass::Medium, DietType::Carnivore);
    Animal herbivore("", WeightClass::Medium, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_FALSE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_MediumCarnivoreHeavyHerbivore_Compatible) {
    Animal carnivore("", WeightClass::Medium, DietType::Carnivore);
    Animal herbivore("", WeightClass::Heavy, DietType::Herbivore);

    ASSERT_TRUE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_TRUE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_HeavyCarnivoreLightHerbivore_Incompatible) {
    Animal carnivore("", WeightClass::Heavy, DietType::Carnivore);
    Animal herbivore("", WeightClass::Light, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_FALSE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_HeavyCarnivoreMediumHerbivore_Incompatible) {
    Animal carnivore("", WeightClass::Heavy, DietType::Carnivore);
    Animal herbivore("", WeightClass::Medium, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_FALSE(herbivore.IsCompatibleWith(carnivore));
}

TEST(AnimalTests, IsCompatibleWith_HeavyCarnivoreHeavyHerbivore_Incompatible) {
    Animal carnivore("", WeightClass::Heavy, DietType::Carnivore);
    Animal herbivore("", WeightClass::Heavy, DietType::Herbivore);

    ASSERT_FALSE(carnivore.IsCompatibleWith(herbivore));
    ASSERT_FALSE(herbivore.IsCompatibleWith(carnivore));
}





