project(App)

include_directories(lib)
include_directories(lib/fmt/include)

set(SOURCE_FILES src/main.cpp src/model/include/Train.hpp src/model/Train.cpp src/model/include/RailCar.hpp src/model/include/Animal.hpp src/model/include/WeightClass.hpp src/model/RailCar.cpp src/model/include/DietType.hpp src/model/include.hpp src/CsvLoader.cpp src/CsvLoader.hpp src/model/Animal.cpp)

add_executable(CircusTrain ${SOURCE_FILES})
add_library(CircusTrain_Lib ${SOURCE_FILES})

add_subdirectory(lib/fmt)
target_link_libraries(CircusTrain fmt::fmt)
target_link_libraries(CircusTrain_Lib fmt::fmt)
