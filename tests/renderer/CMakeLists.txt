cmake_minimum_required(VERSION 3.28.3)

find_package(Catch2 3 REQUIRED)

set(TEST_SOURCES
    test_main.cpp
    test_rendererSFML.cpp   
)

add_executable(rendererSFML_test ${TEST_SOURCES})

target_link_libraries(rendererSFML_test engine)
target_link_libraries(rendererSFML_test rendererSFML)
target_link_libraries(rendererSFML_test Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(rendererSFML_test)