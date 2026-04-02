cmake_minimum_required(VERSION 3.28.3)

set(SRC world.cpp body.cpp circleShape.cpp)
set(HEADER world.hpp body.hpp circleShape.hpp shape.hpp)

add_library(engine ${SRC} ${HEADER})
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})