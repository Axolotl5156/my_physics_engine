cmake_minimum_required(VERSION 3.28.3)

set(SRC test_sim.cpp)
set(HEADER test_sim.hpp)

add_library(test_sim ${SRC} ${HEADER})

target_link_libraries(test_sim engine)
target_link_libraries(test_sim rendererSFML)

target_include_directories(test_sim PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..)