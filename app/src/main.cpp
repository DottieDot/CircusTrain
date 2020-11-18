#include <iostream>
#include <filesystem>
#include <exception>

#include "model/include.hpp"
#include "CsvLoader.hpp"

int main(int argc, const char** args) {
    if (argc != 2) {
        std::cout << "Usage:" << std::endl << "CircusTrain <csv path>" << std::endl;
        return 1;
    }

    CsvLoader loader(args[1]);

    std::cout << "Loading " << std::filesystem::path(args[1]).parent_path() << std::endl;
    try {
        loader.Load();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    Train train(10);
    train.AddAnimals(loader.GetAnimals());
    for (int i = 0; const auto& car : train.GetCars()) {
        std::cout << "Railcar " << ++i  << " Used capacity: " << car.GetUsedSpace() << std::endl;
        std::cout << "==========================" << std::endl;
        for (const auto& animal : car.GetAnimals()) {
            std::cout
                << animal.GetName() << " "
                << magic_enum::enum_name(animal.GetWeight()) << " "
                << magic_enum::enum_name(animal.GetDiet()) << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
