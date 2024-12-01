cmake_minimum_required(VERSION 3.12)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

project(aoc C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-ggdb -D_DEBUG)

include_directories(./include/)

# Include Doxygen
find_package(Doxygen REQUIRED)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    message("Creating documentation using ${DOXYFILE_IN} ${DOXYFILE_OUT}")
    file(MAKE_DIRECTORY ${DOXYGEN_OUT})
    # Configure Doxygen output directory
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_OUTPUT_DIRECTORY ${DOXYGEN_OUT})
    # Add a custom target to generate documentation
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif()


add_subdirectory(src)
add_compile_options(-Wall
        -O3
        -Wextra
)
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()
