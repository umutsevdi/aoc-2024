#include "aoc.h"
#include "util.h"
#include <errno.h>

void help()
{

    puts("         ╒══════════════════════════════════════════╕\r\n"
         "                      Usage: aoc [OPTIONS]\r\n"
         "          Advent of Code 2024 Command Line Interface\r\n"
         "         ╘══════════════════════════════════════════╛\r\n"
         "\r\n"
         "Options:\r\n"
         "  ┌─────────────────────────────────────────────────────────┐\r\n"
         "  │   -h, --help           │   Shows this message           │\r\n"
         "  │   -r, --read [day]     │   Prints the question of the   │\r\n"
         "  │                        │day for the specified day       │\r\n"
         "  │   -q, --question [day] │   Solves the question of the   │\r\n"
         "  │                        │day for the specified day       │\r\n"
         "  │   --[question-name]    │   Solves the question by its   │\r\n"
         "  │                        │name (e.g. --turing-machine)    │\r\n"
         "  └─────────────────────────────────────────────────────────┘\r\n"
         "\r\n"
         "Examples:\r\n"
         "  aoc  -r 1             │ Displays the question of Day 1\r\n"
         "  aoc  -q 2             │ Solves the question for Day 2\r\n"
         "  aoc  --turing-machine │ Solves the question with the name "
         "\"turing-machine\"\r\n");
}

int main(int argc, char* argv[])
{
    setup_solution_list();
    if (argc < 2 || cmparg("--help", "-h", argv[1])) {
        help();
        return AOC_OK;
    }

    char* endptr = NULL;
    if (cmparg("--question", "-q", argv[1])) {
        long id = strtol(argv[2], &endptr, 10);
        if (errno == ERANGE) { return ERROR(AOC_SOLUTION_ID_PARSE); }
        if (id < 1 || id > SOLUTION_SIZE) { return ERROR(AOC_OUT_OF_BOUNDS); }
        if (solutions[id - 1]->run == NULL) {
            return ERROR(AOC_SOLUTION_NOT_COMPLETE);
        }
        solutions[id - 1]->run(argc - 2, &argv[3]);
    } else if (cmparg("--read", "-r", argv[1])) {
        long id = strtol(argv[2], &endptr, 10);
        if (errno == ERANGE) { return ERROR(AOC_SOLUTION_ID_PARSE); }
        if (id < 1 || id > SOLUTION_SIZE) { return ERROR(AOC_OUT_OF_BOUNDS); }
        printf("                ┌────────────────────────┐ \r\n"
               "                │ Advent of Code Day: %ld  │ \r\n"
               "                └────────────────────────┘ \r\n",
               id);
        printf("%s", solutions[id - 1]->description);
    }

    else {
        /* Run command by name */
        for (int i = 0; i < SOLUTION_SIZE; i++) {
            if (cmparg_s(solutions[i]->cmd, argv[2])) {}
        }
    }
    return AOC_OK;
}
