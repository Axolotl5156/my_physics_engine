cmake_minimum_required(VERSION 3.28.3)

set(SRC main.cpp user_interface.cpp)
set(HEADER user_interface.hpp)
set(SIMULATIONS bouncing_ball floating_balls pendulum test_sim)

add_executable(my_physic_engine ${SRC} ${HEADER})

target_link_libraries(my_physic_engine engine)
target_link_libraries(my_physic_engine rendererSFML)
target_link_libraries(my_physic_engine ${SIMULATIONS})