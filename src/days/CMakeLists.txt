file(GLOB_RECURSE DAY_SOLUTIONS "*.c")

include_directories(../../include)
add_library(aoc-days ${DAY_SOLUTIONS})
