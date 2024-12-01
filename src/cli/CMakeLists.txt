file(GLOB CLI_SOURCES *.c)

include_directories(../../include)
add_library(aoc-cli ${CLI_SOURCES})
