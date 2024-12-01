
#include "aoc.h"
#include "cli.h"
#include "util.h"
#include <errno.h>
#define CAPACITY 4096
static enum aoc_code_t run(CliInput* argv);
SOLUTION(
    1,
    {.cmd = "--historian-hysteria",
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

static enum aoc_code_t parse_args(const CliInput* input, long* tokens,
                                  size_t token_max_size, size_t* token_len)
{
    char* token_head = strdup(input->data);
    char* token = token_head;
    char* saveptr;
    token = strtok_r(token, "\r\n \t", &saveptr);
    while (token != NULL) {
        if (strlen(token) > 0) {
            if (*token_len >= token_max_size) {
                free(token_head);
                return ERROR(AOC_OUT_OF_BOUNDS);
            }
            char* endptr = NULL;
            tokens[*token_len] = strtol(token, &endptr, 10);
            if (errno == ERANGE) {
                free(token_head);
                return ERROR(AOC_SOLUTION_ID_PARSE);
            }
            (*token_len)++;
        }
        token = strtok_r(NULL, "\r\n \t", &saveptr);
    }
    free(token_head);
    return AOC_OK;
}

static enum aoc_code_t run_part1(long* tokens, size_t tokens_len)
{

    long* left = malloc(tokens_len / 2 * sizeof(long));
    long* right = malloc(tokens_len / 2 * sizeof(long));

    for (size_t i = 0; i < tokens_len; i++) {
        if (i % 2 == 0) {
            left[i / 2] = tokens[i];
        } else {
            right[i / 2] = tokens[i];
        }
    }
    sortl(right, tokens_len / 2);
    sortl(left, tokens_len / 2);

    long result = 0;
    for (size_t i = 0; i < tokens_len / 2; i++) {
        result += labs(left[i] - right[i]);
    }
    INFO("Part 1: %zu", , result);
    free(left);
    free(right);
    return AOC_OK;
}

static enum aoc_code_t run_part2(long* tokens, size_t tokens_len)
{
    long* left = malloc(tokens_len / 2 * sizeof(long));
    long* right = malloc(tokens_len / 2 * sizeof(long));
    for (size_t i = 0; i < tokens_len; i++) {
        if (i % 2 == 0) {
            left[i / 2] = tokens[i];
        } else {
            right[i / 2] = tokens[i];
        }
    }
    sortl(right, tokens_len / 2);

    /* an array that contains how many times given value occurred. 
    * Only fills the first instances. For example:
    *   occurrence array of 1 3 3 3 2 5 would be 
    *                       0 2 0 0 0 0
    *   Excludes first case so, you must add +1 later
    */
    long* occurrence_table = calloc(tokens_len / 2, sizeof(long));
    /* A table that stores where items on the right was seen for the first time.
     * For the previous array of 1 3 3 3 2 5
     * The array would be
     * 0 1 4 5
     * Use the following indirect address to resolve occurrence table
     *
     */
    size_t unique_index_table[CAPACITY] = {0};
    size_t unique_index_table_len = 1;
    for (size_t i = 1; i < tokens_len / 2; i++) {
        if (right[i] == right[unique_index_table[unique_index_table_len - 1]]) {
            occurrence_table[unique_index_table[unique_index_table_len - 1]]++;
        } else {
            unique_index_table[unique_index_table_len] = i;
            unique_index_table_len++;
        }
    }
    size_t result = 0;

    for (size_t i = 0; i < unique_index_table_len; i++) {
        for (size_t j = 0; j < tokens_len / 2; j++) {

            if (right[unique_index_table[i]] == left[j]) {
                result +=
                    left[j] * (occurrence_table[unique_index_table[i]] + 1);
            }
        }
    }
    INFO("Part 2: %zu", , result);
    free(left);
    free(right);
    free(occurrence_table);
    return AOC_OK;
}

static enum aoc_code_t run(CliInput* argv)
{
    long tokens[CAPACITY] = {0};
    size_t tokens_len = 0;
    parse_args(argv, tokens, CAPACITY, &tokens_len);

    run_part1(tokens, tokens_len);
    run_part2(tokens, tokens_len);
    return AOC_OK;
}
