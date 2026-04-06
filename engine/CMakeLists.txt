cmake_minimum_required(VERSION 3.28.3)

set(SRC
    world.cpp
    body.cpp
    circleShape.cpp
    rectangleShape.cpp
    distance_constraint.cpp)

set(HEADER
    world.hpp
    body.hpp
    circleShape.hpp
    rectangleShape.hpp
    shape.hpp
    distance_constraint.hpp
    constraint.hpp)

add_library(engine ${SRC} ${HEADER})
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})