cmake_minimum_required(VERSION 3.28.3)

set(SRC rendererSFML.cpp)
set(HEADER rendererSFML.hpp)

add_library(rendererSFML ${SRC} ${HEADER})

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_link_libraries(rendererSFML sfml-graphics sfml-window sfml-system)
target_link_libraries(rendererSFML engine)

target_include_directories(rendererSFML PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})