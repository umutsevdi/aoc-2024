
#include "aoc.h"
#include "cli.h"
#include "util.h"

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
            if (!parse_int(token, &tokenlist[*tokenlist_len])) {
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

SOLUTION(1,
         {.cmd = "--historian-hysteria",
          .description =
              "The Chief Historian is always present for the big Christmas\r\n"
              "sleigh launch, but nobody has seen him in months! Last anyon\r\n"
              "e heard, he was visiting locations that are historically sig\r\n"
              "nificant to the North Pole; a group of Senior Historians has\r\n"
              " asked you to accompany them as they check the places they t\r\n"
              "hink he was most likely to visit.\r\n"
              "\r\n"
              "As each location is checked, they will mark it on their list\r\n"
              " with a star. They figure the Chief Historian must be in one\r\n"
              " of the first fifty places they'll look, so in order to save\r\n"
              " Christmas, you need to help them get fifty stars on their l\r\n"
              "ist before Santa takes off on December 25th.\r\n"
              "\r\n"
              "Collect stars by solving puzzles. Two puzzles will be made a\r\n"
              "vailable on each day in the Advent calendar; the second puzz\r\n"
              "le is unlocked when you complete the first. Each puzzle gran\r\n"
              "ts one star. Good luck!\r\n"
              "\r\n"
              "You haven't even left yet and the group of Elvish Senior His\r\n"
              "torians has already hit a problem: their list of locations t\r\n"
              "o check is currently empty. Eventually, someone decides that\r\n"
              " the best place to check first would be the Chief Historian'\r\n"
              "s office.\r\n"
              "\r\n"
              "Upon pouring into the office, everyone confirms that the Chi\r\n"
              "ef Historian is indeed nowhere to be found. Instead, the Elv\r\n"
              "es discover an assortment of notes and lists of historically\r\n"
              " significant locations! This seems to be the planning the Ch\r\n"
              "ief Historian was doing before he left. Perhaps these notes\r\n"
              "can be used to determine which locations to search?\r\n"
              "\r\n"
              "Throughout the Chief's office, the historically significant\r\n"
              "locations are listed not by name but by a unique number call\r\n"
              "ed the location ID. To make sure they don't miss anything, T\r\n"
              "he Historians split into two groups, each searching the offi\r\n"
              "ce and trying to create their own complete list of location\r\n"
              "IDs.\r\n"
              "\r\n"
              "There's just one problem: by holding the two lists up side b\r\n"
              "y side (your puzzle input), it quickly becomes clear that th\r\n"
              "e lists aren't very similar. Maybe you can help The Historia\r\n"
              "ns reconcile their lists?\r\n"
              "\r\n"
              "For example:\r\n"
              "\r\n"
              "3   4\r\n"
              "4   3\r\n"
              "2   5\r\n"
              "1   3\r\n"
              "3   9\r\n"
              "3   3\r\n"
              "\r\n"
              "Maybe the lists are only off by a small amount! To find out,\r\n"
              " pair up the numbers and measure how far apart they are. Pai\r\n"
              "r up the smallest number in the left list with the smallest\r\n"
              "number in the right list, then the second-smallest left numb\r\n"
              "er with the second-smallest right number, and so on.\r\n"
              "\r\n"
              "Within each pair, figure out how far apart the two numbers a\r\n"
              "re; you'll need to add up all of those distances. For exampl\r\n"
              "e, if you pair up a 3 from the left list with a 7 from the r\r\n"
              "ight list, the distance apart is 4; if you pair up a 9 with\r\n"
              "a 3, the distance apart is 6.\r\n"
              "\r\n"
              "In the example list above, the pairs and distances would be\r\n"
              "as follows:\r\n"
              "\r\n"
              "    The smallest number in the left list is 1, and the small\r\n"
              "est number in the right list is 3. The distance between them\r\n"
              " is 2.\r\n"
              "    The second-smallest number in the left list is 2, and th\r\n"
              "e second-smallest number in the right list is another 3. The\r\n"
              " distance between them is 1.\r\n"
              "    The third-smallest number in both lists is 3, so the dis\r\n"
              "tance between them is 0.\r\n"
              "    The next numbers to pair up are 3 and 4, a distance of 1\r\n"
              ".\r\n"
              "    The fifth-smallest numbers in each list are 3 and 5, a d\r\n"
              "istance of 2.\r\n"
              "    Finally, the largest number in the left list is 4, while\r\n"
              " the largest number in the right list is 9; these are a dist\r\n"
              "ance 5 apart.\r\n"
              "\r\n"
              "To find the total distance between the left list and the rig\r\n"
              "ht list, add up the distances between all of the pairs you f\r\n"
              "ound. In the example above, this is 2 + 1 + 0 + 1 + 2 + 5, a\r\n"
              " total distance of 11!\r\n"
              "\r\n"
              "Your actual left and right lists contain many location IDs.\r\n"
              "What is the total distance between your lists?\r\n"
              "\r\n"
              "--- Part Two ---\r\n"
              "\r\n"
              "Your analysis only confirmed what everyone feared: the two l\r\n"
              "ists of location IDs are indeed very different.\r\n"
              "\r\n"
              "Or are they?\r\n"
              "\r\n"
              "The Historians can't agree on which group made the mistakes\r\n"
              "or how to read most of the Chief's handwriting, but in the c\r\n"
              "ommotion you notice an interesting detail: a lot of location\r\n"
              " IDs appear in both lists! Maybe the other numbers aren't lo\r\n"
              "cation IDs at all but rather misinterpreted handwriting.\r\n"
              "\r\n"
              "This time, you'll need to figure out exactly how often each\r\n"
              "number from the left list appears in the right list. Calcula\r\n"
              "te a total similarity score by adding up each number in the\r\n"
              "left list after multiplying it by the number of times that n\r\n"
              "umber appears in the right list.\r\n"
              "\r\n"
              "Here are the same example lists again:\r\n"
              "\r\n"
              "3   4\r\n"
              "4   3\r\n"
              "2   5\r\n"
              "1   3\r\n"
              "3   9\r\n"
              "3   3\r\n"
              "\r\n"
              "For these example lists, here is the process of finding the\r\n"
              "similarity score:\r\n"
              "\r\n"
              "    The first number in the left list is 3. It appears in th\r\n"
              "e right list three times, so the similarity score increases\r\n"
              "by 3 * 3 = 9.\r\n"
              "    The second number in the left list is 4. It appears in t\r\n"
              "he right list once, so the similarity score increases by 4 *\r\n"
              " 1 = 4.\r\n"
              "    The third number in the left list is 2. It does not appe\r\n"
              "ar in the right list, so the similarity score does not incre\r\n"
              "ase (2 * 0 = 0).\r\n"
              "    The fourth number, 1, also does not appear in the right\r\n"
              "list.\r\n"
              "    The fifth number, 3, appears in the right list three tim\r\n"
              "es; the similarity score increases by 9.\r\n"
              "    The last number, 3, appears in the right list three time\r\n"
              "s; the similarity score again increases by 9.\r\n"
              "\r\n"
              "So, for these example lists, the similarity score at the end\r\n"
              " of this process is 31 (9 + 4 + 0 + 0 + 9 + 9).\r\n"
              "\r\n"
              "Once again consider your left and right lists. What is their\r\n"
              " similarity score?\r\n",
          .run = run});
