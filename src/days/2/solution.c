
#include "aoc.h"
#include "cli.h"
#include "util.h"
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 4096
static enum aoc_code_t run(CliInput* argv);
SOLUTION(
    2,
    {.cmd = "--red-nosed-reports",
     .description =
         "The Chief Historian is always present for the big Christmas\r\n"
         "sleigh launch, but nobody has seen him in months! Last anyone\r\n"
         "heard, he was visiting locations that are historically\r\n"
         "significant to the North Pole; a group of Senior Historians has\r\n"
         "asked you to accompany them as they check the places they think\r\n"
         "he was most likely to visit.\r\n"
         "\r\n"
         "As each location is checked, they will mark it on their list\r\n"
         "with a star. They figure the Chief Historian must be in one\r\n"
         "of the first fifty places they'll look, so in order to save\r\n"
         "Christmas, you need to help them get fifty stars on their list\r\n"
         "before Santa takes off on December 25th.\r\n"
         "\r\n"
         "Collect stars by solving puzzles. Two puzzles will be made\r\n"
         "available on each day in the Advent calendar; the second\r\n"
         "puzzle is unlocked when you complete the first. Each puzzle\r\n"
         "grants one star. Good luck!\r\n"
         "\r\n"
         "You haven't even left yet and the group of Elvish Senior\r\n"
         "Historians has already hit a problem: their list of locations\r\n"
         "to check is currently empty. Eventually, someone decides that\r\n"
         "the best place to check first would be the Chief\r\n"
         "Historian's office.\r\n"
         "\r\n"
         "Upon pouring into the office, everyone confirms that the\r\n"
         "Chief Historian is indeed nowhere to be found. Instead, the\r\n"
         "Elves discover an assortment of notes and lists of historically\r\n"
         "significant locations! This seems to be the planning the \r\n"
         "Chief Historian was doing before he left. Perhaps these\r\n"
         "notes can be used to determine which locations to search?\r\n"
         "\r\n"
         "Throughout the Chief's office, the historically significant\r\n"
         "locations are listed not by name but by a unique number called\r\n"
         "the location ID. To make sure they don't miss anything,\r\n"
         "The Historians split into two groups, each searching the office \r\n"
         "and trying to create their own complete list of location IDs.\r\n"
         "\r\n"
         "There's just one problem: by holding the two lists up side\r\n"
         "by side (your puzzle input), it quickly becomes clear that \r\n"
         "the lists aren't very similar. Maybe you can help The\r\n"
         "Historians reconcile their lists?\r\n",
     .run = run});

static char* parse_lines(const CliInput* input, size_t* indexes,
                         size_t* indexes_s)
{
    char* token_head = strdup(input->data);
    char* token = token_head + 1;
    (*indexes_s) = 0;
    indexes[0] = 0;
    while (*token != 0) {
        if (*token == '\n') {
            if (*(token - 1) == '\r') { *(token - 1) = '\0'; }
            *token = '\0';
            (*indexes_s)++;
            indexes[*indexes_s] = token - token_head + 1;
        }
        token++;
    }
    return token_head;
}

static enum aoc_code_t parse_numbers(char* line, long* tokens,
                                     size_t token_max_size, size_t* token_len)
{
    char* token = line;
    char* saveptr;
    token = strtok_r(token, " \t", &saveptr);
    while (token != NULL) {
        if (strlen(token) > 0) {
            if (*token_len >= token_max_size) {
                return ERROR(AOC_OUT_OF_BOUNDS);
            }
            char* endptr = NULL;
            tokens[*token_len] = strtol(token, &endptr, 10);
            if (errno == ERANGE) { return ERROR(AOC_SOLUTION_ID_PARSE); }
            (*token_len)++;
        }
        token = strtok_r(NULL, "\r\n \t", &saveptr);
    }
    return AOC_OK;
}

static bool is_ordered(long* numberlist, size_t numberlist_s)
{
    assert(numberlist_s >= 2);
    bool is_decreasing = numberlist[0] > numberlist[1];
    for (size_t i = 1; i < numberlist_s; i++) {
        long dif = numberlist[i] - numberlist[i - 1];
        if ((is_decreasing && dif >= 0) || (!is_decreasing && dif <= 0)) {
            return false;
        }
        dif = labs(dif);
        if (dif > 3 || dif < 1) { return false; }
    }
    return true;
}

static bool is_order_fixable(long* numberlist, size_t numberlist_s)
{
    long* new_list = malloc((numberlist_s - 1) * sizeof(long));
    for (size_t i = 0; i < numberlist_s; i++) {
        size_t k = 0;
        for (size_t j = 0; j < numberlist_s; j++) {
            if (j != i) { new_list[k++] = numberlist[j]; }
        }
        if (is_ordered(new_list, numberlist_s - 1)) {
            free(new_list);
            return true;
        }
    }
    free(new_list);
    return false;
}

static enum aoc_code_t run_part(char* lines, size_t* indexes, size_t indexes_s)
{
    long ordered_count = 0;
    long ordered_count_with_fix = 0;
    long numbers[CAPACITY] = {0};

    for (size_t i = 0; i < indexes_s; i++) {
        size_t numbers_len = 0;
        enum aoc_code_t result =
            parse_numbers(lines + indexes[i], numbers, CAPACITY, &numbers_len);
        if (result) { return result; }

        if (numbers_len > 0) {
            if (is_ordered(numbers, numbers_len)) {
                ordered_count++;
            } else if (is_order_fixable(numbers, numbers_len)) {
                ordered_count_with_fix++;
            }
        }
    }

    INFO("Part 1: %zu", , ordered_count);
    INFO("Part 2: %zu", , ordered_count + ordered_count_with_fix);
    return AOC_OK;
}

static enum aoc_code_t run(CliInput* argv)
{
    size_t tokens[CAPACITY] = {0};
    size_t tokens_len = 0;
    char* lines = parse_lines(argv, tokens, &tokens_len);
    run_part(lines, tokens, tokens_len);
    free(lines);
    return AOC_OK;
}
