#include "aoc.h"
#include "cli.h"
#include "util.h"

static inline int is_linear(char** lines, size_t rows, size_t cols, size_t i,
                            size_t j)
{
    int result_v = 0, result_h = 0;
    if (i < rows - 3) {
        if (lines[i + 1][j] == 'M' && lines[i + 2][j] == 'A'
            && lines[i + 3][j] == 'S') {
            result_v++;
        }
    }
    if (i >= 3) {
        if (lines[i - 1][j] == 'M' && lines[i - 2][j] == 'A'
            && lines[i - 3][j] == 'S') {
            result_v++;
        }
    }

    if (j < cols - 3) {
        if (lines[i][j + 1] == 'M' && lines[i][j + 2] == 'A'
            && lines[i][j + 3] == 'S') {
            result_h++;
        }
    }
    if (j >= 3) {
        if (lines[i][j - 1] == 'M' && lines[i][j - 2] == 'A'
            && lines[i][j - 3] == 'S') {
            result_h++;
        }
    }
    return result_h + result_v;
}
static

    inline int
    is_diagonal(char** lines, size_t rows, size_t cols, size_t i, size_t j)
{
    int result = 0;
    if (i >= 3 && j >= 3) {
        if (lines[i - 1][j - 1] == 'M' && lines[i - 2][j - 2] == 'A'
            && lines[i - 3][j - 3] == 'S') {
            result++;
        }
    }
    if (i < rows - 3 && j < cols - 3) {
        if (lines[i + 1][j + 1] == 'M' && lines[i + 2][j + 2] == 'A'
            && lines[i + 3][j + 3] == 'S') {
            result++;
        }
    }
    if (i >= 3 && j < cols - 3) {
        if (lines[i - 1][j + 1] == 'M' && lines[i - 2][j + 2] == 'A'
            && lines[i - 3][j + 3] == 'S') {
            result++;
        }
    }
    if (i < rows - 3 && j >= 3) {
        if (lines[i + 1][j - 1] == 'M' && lines[i + 2][j - 2] == 'A'
            && lines[i + 3][j - 3] == 'S') {
            result++;
        }
    }
    return result;
}

static long run_part1(char** lines, size_t rows, size_t cols)
{
    int result = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (lines[i][j] == 'X') {
                result += +is_linear(lines, rows, cols, i, j)
                          + is_diagonal(lines, rows, cols, i, j);
            }
        }
    }
    return result;
}

static long run_part2(char** lines, size_t rows, size_t cols)
{
    int part2_count = 0;
    for (size_t i = 1; i < rows - 1; i++) {
        for (size_t j = 1; j < cols - 1; j++) {
            if (lines[i][j] == 'A') {
                part2_count +=
                    ((lines[i - 1][j - 1] == 'S' && lines[i + 1][j + 1] == 'M')
                     || (lines[i - 1][j - 1] == 'M'
                         && lines[i + 1][j + 1] == 'S'))
                    && ((lines[i - 1][j + 1] == 'S'
                         && lines[i + 1][j - 1] == 'M')
                        || (lines[i - 1][j + 1] == 'M'
                            && lines[i + 1][j - 1] == 'S'));
            }
        }
    }
    return part2_count;
}

static enum aoc_code_t run(CliInput* argv)
{
    size_t indices[CAPACITY] = {0};
    size_t indices_len;
    char* data = parse_lines(argv->data, argv->len, indices, &indices_len);
    char** lines = malloc(indices_len * sizeof(char*));
    for (size_t i = 0; i < indices_len; i++) {
        lines[i] = &data[indices[i]];
    }

    size_t cols = strnlen(lines[0], indices[1] - indices[0]);
    INFO("Part 1: %zu", , run_part1(lines, indices_len, cols));
    INFO("Part 2: %zu", , run_part2(lines, indices_len, cols));
    free(lines);
    free(data);
    return AOC_OK;
}

SOLUTION(
    4, {.cmd = "--ceres-search",
        .description =
            "\"Looks like the Chief's not here. Next!\" One of The Historia\r\n"
            "ns pulls out a device and pushes the only button on it. Afte\r\n"
            "r a brief flash, you recognize the interior of the Ceres mon\r\n"
            "itoring station!\r\n"
            "\r\n"
            "As the search for the Chief continues, a small Elf who lives\r\n"
            " on the station tugs on your shirt; she'd like to know if yo\r\n"
            "u could help her with her word search (your puzzle input). S\r\n"
            "he only has to find one word: XMAS.\r\n"
            "\r\n"
            "This word search allows words to be horizontal, vertical, di\r\n"
            "agonal, written backwards, or even overlapping other words.\r\n"
            "It's a little unusual, though, as you don't merely need to f\r\n"
            "ind one instance of XMAS - you need to find all of them. Her\r\n"
            "e are a few ways XMAS might appear, where irrelevant charact\r\n"
            "ers have been replaced with .:\r\n"
            "\r\n"
            "..X...\r\n"
            ".SAMX.\r\n"
            ".A..A.\r\n"
            "XMAS.S\r\n"
            ".X....\r\n"
            "\r\n"
            "The actual word search will be full of letters instead. For\r\n"
            "example:\r\n"
            "\r\n"
            "MMMSXXMASM\r\n"
            "MSAMXMSMSA\r\n"
            "AMXSXMAAMM\r\n"
            "MSAMASMSMX\r\n"
            "XMASAMXAMM\r\n"
            "XXAMMXXAMA\r\n"
            "SMSMSASXSS\r\n"
            "SAXAMASAAA\r\n"
            "MAMMMXMMMM\r\n"
            "MXMXAXMASX\r\n"
            "\r\n"
            "In this word search, XMAS occurs a total of 18 times; here's\r\n"
            " the same word search again, but where letters not involved\r\n"
            "in any XMAS have been replaced with .:\r\n"
            "\r\n"
            "....XXMAS.\r\n"
            ".SAMXMS...\r\n"
            "...S..A...\r\n"
            "..A.A.MS.X\r\n"
            "XMASAMX.MM\r\n"
            "X.....XA.A\r\n"
            "S.S.S.S.SS\r\n"
            ".A.A.A.A.A\r\n"
            "..M.M.M.MM\r\n"
            ".X.X.XMASX\r\n"
            "\r\n"
            "Take a look at the little Elf's word search. How many times\r\n"
            "does XMAS appear?\r\n"
            "\r\n"
            "--- Part Two ---\r\n"
            "\r\n"
            "The Elf looks quizzically at you. Did you misunderstand the\r\n"
            "assignment?\r\n"
            "\r\n"
            "Looking for the instructions, you flip over the word search\r\n"
            "to find that this isn't actually an XMAS puzzle; it's an X-M\r\n"
            "AS puzzle in which you're supposed to find two MAS in the sh\r\n"
            "ape of an X. One way to achieve that is like this:\r\n"
            "\r\n"
            "M.S\r\n"
            ".A.\r\n"
            "M.S\r\n"
            "\r\n"
            "Irrelevant characters have again been replaced with . in the\r\n"
            " above diagram. Within the X, each MAS can be written forwar\r\n"
            "ds or backwards.\r\n"
            "\r\n"
            "Here's the same example from before, but this time all of th\r\n"
            "e X-MASes have been kept instead:\r\n"
            "\r\n"
            ".M.S......\r\n"
            "..A..MSMS.\r\n"
            ".M.S.MAA..\r\n"
            "..A.ASMSM.\r\n"
            ".M.S.M....\r\n"
            "..........\r\n"
            "S.S.S.S.S.\r\n"
            ".A.A.A.A..\r\n"
            "M.M.M.M.M.\r\n"
            "..........\r\n"
            "\r\n"
            "In this example, an X-MAS appears 9 times.\r\n"
            "\r\n"
            "Flip the word search from the instructions back over to the\r\n"
            "word search side and try again. How many times does an X-MAS\r\n"
            " appear?\r\n",
        .run = run});
