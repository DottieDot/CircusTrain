#include "CsvLoader.hpp"

void CsvLoader::Load() {
    csv::CSVReader reader(m_path.string());
    m_animals.clear();

    for (const auto& row : reader) {
        LoadAnimal(row);
    }
}

void CsvLoader::LoadAnimal(const csv::CSVRow &row) {
    auto weight = ParseEnumValue<WeightClass>(row["weight"].get_sv());
    auto diet = ParseEnumValue<DietType>(row["diet"].get_sv());
    auto name = row["name"].get<>();

    m_animals.emplace_back(name, weight, diet);
}
