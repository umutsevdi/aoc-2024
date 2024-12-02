
#include "aoc.h"
#include "util.h"
#include <errno.h>

/**
 * Receives a line and parses them into series of long numbers.
 * @param line - to parse
 * @param tokens - long numbers to insert into
 * @param token_max_size - length of the token array
 * @param token_len - actual length of the tokens list
 *
 * @returns AOC_OUT_OF_BOUNDS | AOC_SOLUTION_ID_PARSE | AOC_OK
 *
 */
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

/** Returns whether given number array fulfills the rule provided by the
 * question. */
static bool is_ordered(long* numberlist, size_t numberlist_s)
{
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

/** Returns whether the array can be fixed by removing a number */
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

static enum aoc_code_t run_parts(char* lines, size_t* indices, size_t indices_s)
{
    long ordered_count = 0;
    long fixable_count = 0;
    long numbers[CAPACITY] = {0};
    for (size_t i = 0; i < indices_s; i++) {
        size_t numbers_len = 0;
        enum aoc_code_t result =
            parse_numbers(lines + indices[i], numbers, CAPACITY, &numbers_len);
        if (result) { return result; }
        if (numbers_len > 0) {
            if (is_ordered(numbers, numbers_len)) {
                ordered_count++;
            } else if (is_order_fixable(numbers, numbers_len)) {
                fixable_count++;
            }
        }
    }

    INFO("Part 1: %zu", , ordered_count);
    INFO("Part 2: %zu", , ordered_count + fixable_count);
    return AOC_OK;
}

static enum aoc_code_t run(CliInput* argv)
{
    size_t tokens[CAPACITY] = {0};
    size_t tokens_len = 0;
    char* lines = parse_lines(argv->data, argv->len, tokens, &tokens_len);
    enum aoc_code_t result = run_parts(lines, tokens, tokens_len);
    free(lines);
    return result;
}

SOLUTION(
    2,
    {.cmd = "--red-nosed-reports",
     .description =
         "Fortunately, the first location The Historians want to search\r\n"
         "isn't a long walk from the Chief Historian's office.\r\n"
         "\r\n"
         "While the Red-Nosed Reindeer nuclear fusion/fission plant appears\r\n"
         "to contain no sign of the Chief Historian, the engineers there "
         "run\r\n"
         "up to you as soon as they see you. Apparently, they still talk\r\n"
         "about the time Rudolph was saved through molecular synthesis from\r\n"
         "a single electron.\r\n"
         "\r\n"
         "They're quick to add that - since you're already here - they'd "
         "really\r\n"
         "appreciate your help analyzing some unusual data from the "
         "Red-Nosed\r\n"
         "reactor. You turn to check if The Historians are waiting for you,\r\n"
         "but they seem to have already divided into groups that are\r\n"
         "currently searching every corner of the facility. You offer to\r\n"
         "help with the unusual data.\r\n"
         "\r\n"
         "The engineers are trying to figure out which reports are safe.\r\n"
         "The Red-Nosed reactor safety systems can only tolerate levels \r\n"
         "that are either gradually increasing or gradually decreasing. \r\n"
         "So, a report only counts as safe if both of the following are "
         "true:\r\n"
         "\r\n"
         "- The levels are either all increasing or all decreasing.\r\n"
         "- Any two adjacent levels differ by at least one and at most "
         "three.\r\n"
         "\r\n"
         "Part Two \r\n"
         "The engineers are surprised by the low number of safe reports\r\n"
         "until they realize they forgot to tell you about the Problem "
         "Dampener.\r\n"
         "\r\n"
         "The Problem Dampener is a reactor-mounted module that lets the\r\n"
         "reactor safety systems tolerate a single bad level in what would\r\n"
         "otherwise be a safe report. It's like the bad level never "
         "happened!\r\n"
         "\r\n"
         "Now, the same rules apply as before, except if removing a single\r\n"
         "level from an unsafe report would make it safe, the report "
         "instead\r\n"
         "counts as safe.\r\n",
     .run = run});
