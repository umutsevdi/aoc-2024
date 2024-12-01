#include "aoc.h"
#include "cli.h"
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
         "  ┌─────────────────────────────────────────────────────────────┐\r\n"
         "  │  -h/--help                 │   Shows this message           │\r\n"
         "  │  -r/--read [day]           │   Prints the question of the   │\r\n"
         "  │                            │day for the specified day       │\r\n"
         "  │  -q/--question [day] [file]│   Solves the question of the   │\r\n"
         "  │                            │day for the specified day       │\r\n"
         "  │  --[question-name] [file]  │   Solves the question by its   │\r\n"
         "  │                            │name (e.g. --turing-machine)    │\r\n"
         "  └─────────────────────────────────────────────────────────────┘\r\n"
         "Supports pipe operations.\r\n"
         "\r\n"
         "Examples:\r\n"
         "  aoc  -r 1                      │ Displays the question of Day 1\r\n"
         "  aoc  -q 2 file.txt             │ Solves the question for Day 2 "
         "with file.txt as input\r\n"
         "  aoc  -q 5 <<< \"1 2 3 4 5 6\"    │ Solves the question for Day 5 "
         "using given input\r\n"
         "  aoc  --turing-machine file.txt │ Solves the question with the "
         "name "
         "\"turing-machine\"\r\n");
    puts("Available Questions are:");
    int shown = 1;
    for (int i = 0; i < SOLUTION_SIZE; i++) {
        if (solutions[i]->run != NULL) {
            printf("%s, ", solutions[i]->cmd);
            shown++;
        }
        if (shown % 4 == 0) { printf("\r\n"); }
    }
    puts("");
}

int main(int argc, char* argv[])
{
    setup_solution_list();
    CliInput input = {0};
    if (argc < 2 || cmpargs("--help", "-h", argv[1])) {
        help();
        return AOC_OK;
    }

    char* endptr = NULL;
    if (cmpargs("--question", "-q", argv[1])) {
        if (argc < 3) { return ERROR(AOC_NO_QUESTION_PROVIDED); }
        long id = strtol(argv[2], &endptr, 10);
        if (errno == ERANGE) { return ERROR(AOC_SOLUTION_ID_PARSE); }
        if (id < 1 || id > SOLUTION_SIZE) { return ERROR(AOC_OUT_OF_BOUNDS); }
        if (solutions[id - 1]->run == NULL) {
            return ERROR(AOC_SOLUTION_NOT_COMPLETE);
        }
        enum aoc_code_t input_result = read_input(argv[3], &input);
        if (!input_result) { return solutions[id - 1]->run(&input); }
        return input_result;
    } else if (cmpargs("--read", "-r", argv[1])) {
        long id = strtol(argv[2], &endptr, 10);
        if (errno == ERANGE) { return ERROR(AOC_SOLUTION_ID_PARSE); }
        if (id < 1 || id > SOLUTION_SIZE) { return ERROR(AOC_OUT_OF_BOUNDS); }
        printf("                ┌────────────────────────┐ \r\n"
               "                │ Advent of Code Day: %ld  │ \r\n"
               "                └────────────────────────┘ \r\n",
               id);
        printf("%s", solutions[id - 1]->description);
    } else if (cmparg("--", argv[2])) {
        /* Run command by name */
        bool found = false;
        for (int i = 0; i < SOLUTION_SIZE; i++) {
            if (cmparg(solutions[i]->cmd, argv[2])) {
                found = true;
                enum aoc_code_t input_result = read_input(argv[3], &input);
                if (!input_result) { return solutions[i]->run(&input); }
                return input_result;
            }
        }
        if (!found) { return ERROR(AOC_NO_SUCH_QUESTION); }
    } else {
        return ERROR(ADC_UNKNOWN_OPTION);
    }
    return AOC_OK;
}
