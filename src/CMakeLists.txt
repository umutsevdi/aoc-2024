file(GLOB SOURCES *.c)
add_executable(aoc ${SOURCES} )
add_subdirectory(days)
target_link_libraries(aoc
    aoc-days
)

