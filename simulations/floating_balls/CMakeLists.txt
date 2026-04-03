cmake_minimum_required(VERSION 3.28.3)

set(SRC floating_balls.cpp)
set(HEADER floating_balls.hpp)

add_library(floating_balls ${SRC} ${HEADER})

target_link_libraries(floating_balls engine)
target_link_libraries(floating_balls rendererSFML)

target_include_directories(floating_balls PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..)