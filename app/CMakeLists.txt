cmake_minimum_required(VERSION 3.28.3)

set(SRC main.cpp)
set(SIMULATIONS bouncing_ball floating_balls)

add_executable(my_physic_engine ${SRC})

target_link_libraries(my_physic_engine engine)
target_link_libraries(my_physic_engine rendererSFML)
target_link_libraries(my_physic_engine ${SIMULATIONS})