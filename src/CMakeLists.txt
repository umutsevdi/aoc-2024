file(GLOB SOURCES *.c)
add_executable(aoc ${SOURCES} )
add_subdirectory(days)
add_subdirectory(cli)
target_link_libraries(aoc
    aoc-days
    aoc-cli
)

