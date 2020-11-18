project(Google_tests)

add_subdirectory(lib/gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../app/src)

add_executable(Google_Tests_run tests/Animal.cpp tests/RailCar.cpp tests/Train.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run CircusTrain_Lib)