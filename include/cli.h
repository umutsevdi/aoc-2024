#pragma once
/*******************************************************************************
 * \file
 * File: include/cli.h
 * Created: 12/01/24
 * Author: Umut Sevdi
 * Description: IO Parser utils
 *
 * Project: umutsevdi/aoc-2024
 * License: MIT License
 ******************************************************************************/

#include "util.h"

/** Processed CLI Input */
typedef struct {
    char* data;
    size_t size;
    size_t len;
    /**Needed for internal use */
    size_t _cursor;
} CliInput;

/**
 * Compares the given argument with *two NULL terminated strings*, Short
 * and long versions
 * @param l_opt - NULL terminated long command. Example: --help
 * @param s_opt - NULL terminated short command. Example: -h
 * @param arg - arg to compare
 * 
 * @returns whether the argument matches or not
 */
bool cmpargs(const char* l_opt, const char* s_opt, const char* arg);

/**
 * Compares the given argument with a single NULL terminated string
 * @param opt - NULL terminated long command. Example: --help
 * @param arg - arg to compare
 * 
 * @returns whether the argument matches or not
 */
bool cmparg(const char* opt, const char* arg);

/**
 * If a file name is present in argument, reads input from it. If not
 * falls back to stdin.
 *
 * Writes its contents to the Input.
 *
 * @param arg - arg to open.
 * @param pipe - empty pipe object to fill.
 *
 * @returns error code.
 *      - AOC_PIPE_FAILED
 *      - AOC_FILE_NOT_FOUND
 *      - AOC_NOT_A_FILE
 */
enum aoc_code_t read_input(char* arg, CliInput* pipe);

/**
 * Creates a copy of the input string where it is separated by new lines.
 * Inserts beginning of each line as indices to the indices array,
 * while updating the indices size accordingly.
 *
 * @param input - to parse
 * @param input_s - length of the string
 * @param indices - indices of the beginning of each string
 * @param indices_s - number of indices
 *
 * @returns copy of the original string that contains NULL terminated segments.
 */
char* parse_lines(const char* input, const size_t input_s, size_t* indices,
                  size_t* indices_s);
