#pragma once

#include <filesystem>
#include <magic_enum/magic_enum.hpp>
#include <stdexcept>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <csv/csv.hpp>

#include "model/include.hpp"

class CsvLoader {
private:
    std::filesystem::path m_path;
    std::vector<Animal> m_animals;

    template<typename T>
    [[nodiscard]]
    static T ParseEnumValue(std::string_view string) {
        if (auto res = magic_enum::enum_cast<T>(string); res.has_value()) {
            return res.value();
        }
        else {
            constexpr auto& names = magic_enum::enum_names<T>();
            throw std::runtime_error(fmt::format("Invalid value: {}; expected one of: {}", string.data(), fmt::join(names, ", ")));
        }
    }

    void LoadAnimal(const csv::CSVRow& row);

public:
    explicit CsvLoader(std::filesystem::path path)
        : m_path(std::move(path))
    {}

    void Load();

    [[nodiscard]]
    inline const auto& GetAnimals() const { return m_animals; }
};
