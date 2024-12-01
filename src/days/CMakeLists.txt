file(GLOB_RECURSE DAY_SOLUTIONS "*/solution.c")

include_directories(../../include)
add_library(aoc-days default.c ${DAY_SOLUTIONS})
