#include "aoc.h"
#include "cli.h"
#include "util.h"

struct Rule {
    long n1;
    long n2;
};

static enum aoc_code_t parse_rules(struct Rule* rules, char* data,
                                   size_t* indices, size_t indices_len)
{
    char rulestr[6] = {0};
    for (size_t i = 0; i < indices_len; i++) {
        memcpy(rulestr, data + indices[i], 5);
        rulestr[2] = '\0';
        if (!(parse_int(rulestr, &rules[i].n1)
              && parse_int(rulestr + 3, &rules[i].n2))) {
            return ERROR(AOC_PARSE);
        }
    }
    return AOC_OK;
}

static enum aoc_code_t parse_list(char* line, size_t line_s, long* list,
                                  size_t* list_s)
{
    size_t len = 0;
    size_t previous = 0;
    for (size_t i = 0; i < line_s; i++) {
        if (line[i] == ',') {
            line[i] = '\0';
            if (!parse_int(&line[previous], &list[len])) {
                return ERROR(AOC_PARSE);
            }
            previous = i + 1;
            len++;
        }
    }
    if (previous != line_s) {
        if (!parse_int(&line[previous], &list[len])) {
            return ERROR(AOC_PARSE);
        }
        len++;
    }
    *list_s = len;
    return AOC_OK;
}

static bool is_ordered(long* list, size_t list_s, struct Rule* rules,
                       size_t rules_len)
{
    for (size_t i = 0; i < list_s; i++) {
        for (size_t j = 0; j < rules_len; j++) {
            if (rules[j].n1 == list[i]) {
                bool has = true;
                for (size_t k = 0; k < i; k++) {
                    if (rules[j].n2 == list[k]) {
                        has = false;
                        break;
                    }
                }
                if (!has) { return false; }
            }
        }
    }
    return true;
}

static bool sort_list(long* list, size_t list_s, struct Rule* rules,
                      size_t rules_len)
{
    for (size_t i = 0; i < list_s; i++) {
        for (size_t j = 0; j < rules_len; j++) {
            if (rules[j].n1 == list[i]) {
                for (size_t k = 0; k < i; k++) {
                    if (rules[j].n2 == list[k]) {
                        list[k] = rules[j].n1;
                        list[i] = rules[j].n2;
                        break;
                    }
                }
            }
        }
    }
    return true;
}

static enum aoc_code_t run(CliInput* argv)
{
    size_t indices[CAPACITY] = {0};
    size_t indices_len;
    char* data = parse_lines(argv->data, argv->len, indices, &indices_len);

    size_t emptyline = 0;
    while (strlen(&data[indices[emptyline]]) != 0 && emptyline < indices_len)
        emptyline++;
    if (emptyline >= indices_len) {
        free(data);
        return ERROR(AOC_OUT_OF_BOUNDS);
    }

    struct Rule* rules = malloc(emptyline * sizeof(struct Rule));
    enum aoc_code_t rules_err = parse_rules(rules, data, indices, emptyline);
    if (rules_err) {
        free(rules);
        free(data);
        return rules_err;
    }

    long numberlist[CAPACITY] = {0};
    size_t numberlist_s = 0;
    long result = 0;
    long result2 = 0;
    for (size_t i = emptyline + 1; i < indices_len; i++) {
        enum aoc_code_t list_err =
            parse_list(&data[indices[i]], strlen(data + indices[i]), numberlist,
                       &numberlist_s);
        if (list_err) {
            free(rules);
            free(data);
            return list_err;
        }
        if (is_ordered(numberlist, numberlist_s, rules, emptyline)) {
            result += numberlist[numberlist_s / 2];
        } else {
            // truly a horrible line
            while (!is_ordered(numberlist, numberlist_s, rules, emptyline)) {
                sort_list(numberlist, numberlist_s, rules, emptyline);
            }
            result2 += numberlist[numberlist_s / 2];
        }
    }

    INFO("Part 1: %zu", , result);
    INFO("Part 2: %zu", , result2);
    free(rules);
    free(data);
    return AOC_OK;
}
SOLUTION(5,
         {.cmd = "--print-queue",
          .description =
              "Satisfied with their search on Ceres, the squadron of schola\r\n"
              "rs suggests subsequently scanning the stationery stacks of s\r\n"
              "ub-basement 17.\r\n"
              "\r\n"
              "The North Pole printing department is busier than ever this\r\n"
              "close to Christmas, and while The Historians continue their\r\n"
              "search of this historically significant facility, an Elf ope\r\n"
              "rating a very familiar printer beckons you over.\r\n"
              "\r\n"
              "The Elf must recognize you, because they waste no time expla\r\n"
              "ining that the new sleigh launch safety manual updates won't\r\n"
              " print correctly. Failure to update the safety manuals would\r\n"
              " be dire indeed, so you offer your services.\r\n"
              "\r\n"
              "Safety protocols clearly indicate that new pages for the saf\r\n"
              "ety manuals must be printed in a very specific order. The no\r\n"
              "tation X|Y means that if both page number X and page number\r\n"
              "Y are to be produced as part of an update, page number X mus\r\n"
              "t be printed at some point before page number Y.\r\n"
              "\r\n"
              "The Elf has for you both the page ordering rules and the pag\r\n"
              "es to produce in each update (your puzzle input), but can't\r\n"
              "figure out whether each update has the pages in the right or\r\n"
              "der.\r\n"
              "\r\n"
              "For example:\r\n"
              "\r\n"
              "47|53\r\n"
              "97|13\r\n"
              "97|61\r\n"
              "97|47\r\n"
              "75|29\r\n"
              "61|13\r\n"
              "75|53\r\n"
              "29|13\r\n"
              "97|29\r\n"
              "53|29\r\n"
              "61|53\r\n"
              "97|53\r\n"
              "61|29\r\n"
              "47|13\r\n"
              "75|47\r\n"
              "97|75\r\n"
              "47|61\r\n"
              "75|61\r\n"
              "47|29\r\n"
              "75|13\r\n"
              "53|13\r\n"
              "\r\n"
              "75,47,61,53,29\r\n"
              "97,61,53,29,13\r\n"
              "75,29,13\r\n"
              "75,97,47,61,53\r\n"
              "61,13,29\r\n"
              "97,13,75,29,47\r\n"
              "\r\n"
              "The first section specifies the page ordering rules, one per\r\n"
              " line. The first rule, 47|53, means that if an update includ\r\n"
              "es both page number 47 and page number 53, then page number\r\n"
              "47 must be printed at some point before page number 53. (47\r\n"
              "doesn't necessarily need to be immediately before 53; other\r\n"
              "pages are allowed to be between them.)\r\n"
              "\r\n"
              "The second section specifies the page numbers of each update\r\n"
              ". Because most safety manuals are different, the pages neede\r\n"
              "d in the updates are different too. The first update, 75,47,\r\n"
              "61,53,29, means that the update consists of page numbers 75,\r\n"
              " 47, 61, 53, and 29.\r\n"
              "\r\n"
              "To get the printers going as soon as possible, start by iden\r\n"
              "tifying which updates are already in the right order.\r\n"
              "\r\n"
              "In the above example, the first update (75,47,61,53,29) is i\r\n"
              "n the right order:\r\n"
              "\r\n"
              "    75 is correctly first because there are rules that put e\r\n"
              "ach other page after it: 75|47, 75|61, 75|53, and 75|29.\r\n"
              "    47 is correctly second because 75 must be before it (75|\r\n"
              "47) and every other page must be after it according to 47|61\r\n"
              ", 47|53, and 47|29.\r\n"
              "    61 is correctly in the middle because 75 and 47 are befo\r\n"
              "re it (75|61 and 47|61) and 53 and 29 are after it (61|53 an\r\n"
              "d 61|29).\r\n"
              "    53 is correctly fourth because it is before page number\r\n"
              "29 (53|29).\r\n"
              "    29 is the only page left and so is correctly last.\r\n"
              "\r\n"
              "Because the first update does not include some page numbers,\r\n"
              " the ordering rules involving those missing page numbers are\r\n"
              " ignored.\r\n"
              "\r\n"
              "The second and third updates are also in the correct order a\r\n"
              "ccording to the rules. Like the first update, they also do n\r\n"
              "ot include every page number, and so only some of the orderi\r\n"
              "ng rules apply - within each update, the ordering rules that\r\n"
              " involve missing page numbers are not used.\r\n"
              "\r\n"
              "The fourth update, 75,97,47,61,53, is not in the correct ord\r\n"
              "er: it would print 75 before 97, which violates the rule 97|\r\n"
              "75.\r\n"
              "\r\n"
              "The fifth update, 61,13,29, is also not in the correct order\r\n"
              ", since it breaks the rule 29|13.\r\n"
              "\r\n"
              "The last update, 97,13,75,29,47, is not in the correct order\r\n"
              " due to breaking several rules.\r\n"
              "\r\n"
              "For some reason, the Elves also need to know the middle page\r\n"
              " number of each update being printed. Because you are curren\r\n"
              "tly only printing the correctly-ordered updates, you will ne\r\n"
              "ed to find the middle page number of each correctly-ordered\r\n"
              "update. In the above example, the correctly-ordered updates\r\n"
              "are:\r\n"
              "\r\n"
              "75,47,61,53,29\r\n"
              "97,61,53,29,13\r\n"
              "75,29,13\r\n"
              "\r\n"
              "These have middle page numbers of 61, 53, and 29 respectivel\r\n"
              "y. Adding these page numbers together gives 143.\r\n"
              "\r\n"
              "Of course, you'll need to be careful: the actual list of pag\r\n"
              "e ordering rules is bigger and more complicated than the abo\r\n"
              "ve example.\r\n"
              "\r\n"
              "Determine which updates are already in the correct order. Wh\r\n"
              "at do you get if you add up the middle page number from thos\r\n"
              "e correctly-ordered updates?\r\n"
              "\r\n"
              "--- Part Two ---\r\n"
              "\r\n"
              "While the Elves get to work printing the correctly-ordered u\r\n"
              "pdates, you have a little time to fix the rest of them.\r\n"
              "\r\n"
              "For each of the incorrectly-ordered updates, use the page or\r\n"
              "dering rules to put the page numbers in the right order. For\r\n"
              " the above example, here are the three incorrectly-ordered u\r\n"
              "pdates and their correct orderings:\r\n"
              "\r\n"
              "    75,97,47,61,53 becomes 97,75,47,61,53.\r\n"
              "    61,13,29 becomes 61,29,13.\r\n"
              "    97,13,75,29,47 becomes 97,75,47,29,13.\r\n"
              "\r\n"
              "After taking only the incorrectly-ordered updates and orderi\r\n"
              "ng them correctly, their middle page numbers are 47, 29, and\r\n"
              " 47. Adding these together produces 123.\r\n"
              "\r\n"
              "Find the updates which are not in the correct order. What do\r\n"
              " you get if you add up the middle page numbers after correct\r\n"
              "ly ordering just those updates?\r\n",
          .run = run});
