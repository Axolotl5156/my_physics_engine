cmake_minimum_required(VERSION 3.28.3)

project(my_physic_engine)

add_subdirectory(engine)
add_subdirectory(renderer)
add_subdirectory(simulations)
add_subdirectory(app)

enable_testing()
add_subdirectory(tests)