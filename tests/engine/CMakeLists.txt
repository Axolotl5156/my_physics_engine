cmake_minimum_required(VERSION 3.28.3)

find_package(Catch2 3 REQUIRED)

set(TEST_SOURCES
    test_main.cpp
    test_body.cpp
    test_world.cpp    
)

add_executable(engine_tests ${TEST_SOURCES})

target_link_libraries(engine_tests engine)
target_link_libraries(engine_tests Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(engine_tests)