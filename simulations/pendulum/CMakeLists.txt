cmake_minimum_required(VERSION 3.28.3)

set(SRC pendulum.cpp)
set(HEADER pendulum.hpp)

add_library(pendulum ${SRC} ${HEADER})

target_link_libraries(pendulum engine)
target_link_libraries(pendulum rendererSFML)
target_link_libraries(pendulum core)

target_include_directories(pendulum PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..)