cmake_minimum_required(VERSION 3.28.3)

project(my_physic_engine)

add_subdirectory(core)
add_subdirectory(engine)
add_subdirectory(renderer)
add_subdirectory(simulations)
add_subdirectory(app)

find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYFILE_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
    set(DOXYFILE_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating documentation with Doxygen"
        VERBATIM
    )
endif()

enable_testing()
add_subdirectory(tests)