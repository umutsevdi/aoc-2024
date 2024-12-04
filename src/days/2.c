
#include "aoc.h"
#include "util.h"

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
            if (!parse_int(token, &tokens[*token_len])) {
                return ERROR(AOC_SOLUTION_ID_PARSE);
            }
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

SOLUTION(2,
         {.cmd = "--red-nosed-reports",
          .description =
              "Fortunately, the first location The Historians want to searc\r\n"
              "h isn't a long walk from the Chief Historian's office.\r\n"
              "\r\n"
              "While the Red-Nosed Reindeer nuclear fusion/fission plant ap\r\n"
              "pears to contain no sign of the Chief Historian, the enginee\r\n"
              "rs there run up to you as soon as they see you. Apparently,\r\n"
              "they still talk about the time Rudolph was saved through mol\r\n"
              "ecular synthesis from a single electron.\r\n"
              "\r\n"
              "They're quick to add that - since you're already here - they\r\n"
              "'d really appreciate your help analyzing some unusual data f\r\n"
              "rom the Red-Nosed reactor. You turn to check if The Historia\r\n"
              "ns are waiting for you, but they seem to have already divide\r\n"
              "d into groups that are currently searching every corner of t\r\n"
              "he facility. You offer to help with the unusual data.\r\n"
              "\r\n"
              "The unusual data (your puzzle input) consists of many report\r\n"
              "s, one report per line. Each report is a list of numbers cal\r\n"
              "led levels that are separated by spaces. For example:\r\n"
              "\r\n"
              "7 6 4 2 1\r\n"
              "1 2 7 8 9\r\n"
              "9 7 6 2 1\r\n"
              "1 3 2 4 5\r\n"
              "8 6 4 4 1\r\n"
              "1 3 6 7 9\r\n"
              "\r\n"
              "This example data contains six reports each containing five\r\n"
              "levels.\r\n"
              "\r\n"
              "The engineers are trying to figure out which reports are saf\r\n"
              "e. The Red-Nosed reactor safety systems can only tolerate le\r\n"
              "vels that are either gradually increasing or gradually decre\r\n"
              "asing. So, a report only counts as safe if both of the follo\r\n"
              "wing are true:\r\n"
              "\r\n"
              "    The levels are either all increasing or all decreasing.\r\n"
              "    Any two adjacent levels differ by at least one and at mo\r\n"
              "st three.\r\n"
              "\r\n"
              "In the example above, the reports can be found safe or unsaf\r\n"
              "e by checking those rules:\r\n"
              "\r\n"
              "    7 6 4 2 1: Safe because the levels are all decreasing by\r\n"
              " 1 or 2.\r\n"
              "    1 2 7 8 9: Unsafe because 2 7 is an increase of 5.\r\n"
              "    9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.\r\n"
              "    1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is d\r\n"
              "ecreasing.\r\n"
              "    8 6 4 4 1: Unsafe because 4 4 is neither an increase or\r\n"
              "a decrease.\r\n"
              "    1 3 6 7 9: Safe because the levels are all increasing by\r\n"
              " 1, 2, or 3.\r\n"
              "\r\n"
              "So, in this example, 2 reports are safe.\r\n"
              "\r\n"
              "Analyze the unusual data from the engineers. How many report\r\n"
              "s are safe?\r\n"
              "\r\n"
              "--- Part Two ---\r\n"
              "\r\n"
              "The engineers are surprised by the low number of safe report\r\n"
              "s until they realize they forgot to tell you about the Probl\r\n"
              "em Dampener.\r\n"
              "\r\n"
              "The Problem Dampener is a reactor-mounted module that lets t\r\n"
              "he reactor safety systems tolerate a single bad level in wha\r\n"
              "t would otherwise be a safe report. It's like the bad level\r\n"
              "never happened!\r\n"
              "\r\n"
              "Now, the same rules apply as before, except if removing a si\r\n"
              "ngle level from an unsafe report would make it safe, the rep\r\n"
              "ort instead counts as safe.\r\n"
              "\r\n"
              "More of the above example's reports are now safe:\r\n"
              "\r\n"
              "    7 6 4 2 1: Safe without removing any level.\r\n"
              "    1 2 7 8 9: Unsafe regardless of which level is removed.\r\n"
              "    9 7 6 2 1: Unsafe regardless of which level is removed.\r\n"
              "    1 3 2 4 5: Safe by removing the second level, 3.\r\n"
              "    8 6 4 4 1: Safe by removing the third level, 4.\r\n"
              "    1 3 6 7 9: Safe without removing any level.\r\n"
              "\r\n"
              "Thanks to the Problem Dampener, 4 reports are actually safe!\r\n"
              "\r\n"
              "Update your analysis by handling situations where the Proble\r\n"
              "m Dampener can remove a single level from unsafe reports. Ho\r\n"
              "w many reports are now safe?\r\n",
          .run = run});
