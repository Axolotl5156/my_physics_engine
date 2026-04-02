cmake_minimum_required(VERSION 3.28.3)

set(SRC bouncing_ball.cpp)
set(HEADER bouncing_ball.hpp)

add_library(bouncing_ball ${SRC} ${HEADER})

target_link_libraries(bouncing_ball engine)
target_link_libraries(bouncing_ball rendererSFML)

target_include_directories(bouncing_ball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..)