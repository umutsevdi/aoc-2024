#pragma once
/*******************************************************************************
 *
 * File: include/cli.h
 * Created: 12/01/24
 * Author: Umut Sevdi
 * Description: IO Parser utils
 *
 * Project: umutsevdi/aoc-2024
 * License: MIT License
 ******************************************************************************/

#include "util.h"

/// Processed CLI Input
typedef struct {
    char* data;
    size_t size;
    size_t _cursor;///Needed for internal use
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
