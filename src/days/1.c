
#include "aoc.h"
#include "cli.h"
#include "util.h"
#include <errno.h>

/**
 * Parse the CLI input into list of Long numbers
 * @param input - to parse
 * @param tokenlist - long numbers to insert into
 * @param tokenlist_s - length of the token array
 * @param tokenlist_len - actual length of the tokens list
 *
 * @returns AOC_OUT_OF_BOUNDS | AOC_SOLUTION_ID_PARSE | AOC_OK
 */
static enum aoc_code_t parse_args(const CliInput* input, long* tokenlist,
                                  size_t tokenlist_s, size_t* tokenlist_len)
{
    char* token_head = strdup(input->data);
    char* token = token_head;
    char* saveptr;
    token = strtok_r(token, "\r\n \t", &saveptr);
    while (token != NULL) {
        if (strlen(token) > 0) {
            if (*tokenlist_len >= tokenlist_s) {
                free(token_head);
                return ERROR(AOC_OUT_OF_BOUNDS);
            }
            char* endptr = NULL;
            tokenlist[*tokenlist_len] = strtol(token, &endptr, 10);
            if (errno == ERANGE) {
                free(token_head);
                return ERROR(AOC_SOLUTION_ID_PARSE);
            }
            (*tokenlist_len)++;
        }
        token = strtok_r(NULL, "\r\n \t", &saveptr);
    }
    free(token_head);
    return AOC_OK;
}

static void run_part1(long* left, long* right, size_t tokens_len)
{
    long result = 0;
    for (size_t i = 0; i < tokens_len; i++) {
        result += labs(left[i] - right[i]);
    }
    INFO("Part 1: %zu", , result);
}

static void run_part2(long* left, long* right, size_t tokens_len)
{
    size_t result = 0;
    for (size_t i = 0; i < tokens_len; i++) {
        size_t occurrence = 0;
        for (size_t j = 0; j < tokens_len; j++) {
            if (left[i] == right[j]) { occurrence++; }
        }
        result += occurrence * left[i];
    }
    INFO("Part 2: %zu", , result);
}

static enum aoc_code_t run(CliInput* argv)
{
    long tokens[CAPACITY] = {0};
    size_t tokens_len = 0;
    enum aoc_code_t code = parse_args(argv, tokens, CAPACITY, &tokens_len);
    long* left = malloc(tokens_len / 2 * sizeof(long));
    long* right = malloc(tokens_len / 2 * sizeof(long));
    if (code) { return code; }
    for (size_t i = 0; i < tokens_len; i++) {
        if (i % 2 == 0) {
            left[i / 2] = tokens[i];
        } else {
            right[i / 2] = tokens[i];
        }
    }
    sortl(right, tokens_len / 2);
    sortl(left, tokens_len / 2);
    run_part1(left, right, tokens_len / 2);
    run_part2(left, right, tokens_len / 2);
    free(left), free(right);
    return AOC_OK;
}

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
