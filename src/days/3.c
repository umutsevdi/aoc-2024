#include "aoc.h"
#include "cli.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>

/**
 * Parses the mul command and returns it's result,
 * pushes the index where it fails.
 * @param str - to parse
 * @param idx - the cursor index
 */
static size_t parse_mul(char* str, size_t* idx)
{
    size_t internal_idx = *idx + 3;
    if (str[internal_idx] == '(') {
        internal_idx++;
        char arg[9] = {0};
        memcpy(arg, str + internal_idx, 9);
        size_t kama = 0;
        size_t bracket_end = 0;
        for (size_t i = 0; i < 9; i++) {
            if (arg[i] == ',') {
                kama = i;
            } else if (arg[i] == ')') {
                bracket_end = i;
                break;
            }
        }
        // if kama and bracket are in valid positions
        if (kama != 0 && bracket_end != 0) {
            arg[kama] = '\0';
            arg[bracket_end] = '\0';
            long first, second;
            if (!parse_int(arg, &first) || first > 999
                || !parse_int(&arg[kama + 1], &second) || second > 999) {
                *idx = internal_idx - 1;
                return 0;
            }
            return first * second;
        } else {
            *idx = internal_idx - 1;
        }
    }
    return 0;
}

static enum aoc_code_t run(CliInput* argv)
{
    long result_p1 = 0;
    long result_p2 = 0;
    size_t idx = 0;
    char* txt = argv->data;
    bool enabled = true;
    while (idx < argv->len) {
        if (cmparg("don't()", &txt[idx])) {
            enabled = false;
        } else if (cmparg("do()", &txt[idx])) {
            enabled = true;
        } else if (cmparg("mul", &txt[idx])) {
            long mul = parse_mul(txt, &idx);
            if (enabled) { result_p2 += mul; }
            result_p1 += mul;
        }
        idx++;
    }
    INFO("Part 1: %zu", , result_p1);
    INFO("Part 2: %zu", , result_p2);
    return AOC_OK;
}

SOLUTION(
    3, {.cmd = "--mull-it-over",
        .description =
            "\"Our computers are having issues, so I have no idea if we ha\r\n"
            "ve any Chief Historians in stock! You're welcome to check th\r\n"
            "e warehouse, though,\" says the mildly flustered shopkeeper a\r\n"
            "t the North Pole Toboggan Rental Shop. The Historians head o\r\n"
            "ut to take a look.\r\n"
            "\r\n"
            "The shopkeeper turns to you. \"Any chance you can see why our\r\n"
            " computers are having issues again?\"\r\n"
            "\r\n"
            "The computer appears to be trying to run a program, but its\r\n"
            "memory (your puzzle input) is corrupted. All of the instruct\r\n"
            "ions have been jumbled up!\r\n"
            "\r\n"
            "It seems like the goal of the program is just to multiply so\r\n"
            "me numbers. It does that with instructions like mul(X,Y), wh\r\n"
            "ere X and Y are each 1-3 digit numbers. For instance, mul(44\r\n"
            ",46) multiplies 44 by 46 to get a result of 2024. Similarly,\r\n"
            " mul(123,4) would multiply 123 by 4.\r\n"
            "\r\n"
            "However, because the program's memory has been corrupted, th\r\n"
            "ere are also many invalid characters that should be ignored,\r\n"
            " even if they look like part of a mul instruction. Sequences\r\n"
            " like mul(4*, mul(6,9!, ?(12,34), or mul ( 2 , 4 ) do nothin\r\n"
            "g.\r\n"
            "\r\n"
            "For example, consider the following section of corrupted mem\r\n"
            "ory:\r\n"
            "\r\n"
            "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,\r\n"
            "8)mul(8,5))\r\n"
            "\r\n"
            "Only the four highlighted sections are real mul instructions\r\n"
            ". Adding up the result of each instruction produces 161 (2*4\r\n"
            " + 5*5 + 11*8 + 8*5).\r\n"
            "\r\n"
            "Scan the corrupted memory for uncorrupted mul instructions.\r\n"
            "What do you get if you add up all of the results of the mult\r\n"
            "iplications?\r\n"
            "\r\n"
            "--- Part Two ---\r\n"
            "\r\n"
            "As you scan through the corrupted memory, you notice that so\r\n"
            "me of the conditional statements are also still intact. If y\r\n"
            "ou handle some of the uncorrupted conditional statements in\r\n"
            "the program, you might be able to get an even more accurate\r\n"
            "result.\r\n"
            "\r\n"
            "There are two new instructions you'll need to handle:\r\n"
            "\r\n"
            "    The do() instruction enables future mul instructions.\r\n"
            "    The don't() instruction disables future mul instructions\r\n"
            ".\r\n"
            "\r\n"
            "Only the most recent do() or don't() instruction applies. At\r\n"
            " the beginning of the program, mul instructions are enabled.\r\n"
            "\r\n"
            "For example:\r\n"
            "\r\n"
            "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)und\r\n"
            "o()?mul(8,5))\r\n"
            "\r\n"
            "This corrupted memory is similar to the example from before,\r\n"
            " but this time the mul(5,5) and mul(11,8) instructions are d\r\n"
            "isabled because there is a don't() instruction before them.\r\n"
            "The other mul instructions function normally, including the\r\n"
            "one at the end that gets re-enabled by a do() instruction.\r\n"
            "\r\n"
            "This time, the sum of the results is 48 (2*4 + 8*5).\r\n"
            "\r\n"
            "Handle the new instructions; what do you get if you add up a\r\n"
            "ll of the results of just the enabled multiplications?\r\n",
        .run = run});
