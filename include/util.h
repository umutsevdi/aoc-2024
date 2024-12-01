#pragma once
/*******************************************************************************
 *
 * File: include/util.h
 * Created: 12/01/24
 * Author: Umut Sevdi
 * Description: Utility library
 *
 * Project: umutsevdi/aoc-2024
 * License: MIT License
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Error codes of the program
 */
enum aoc_code_t {
    AOC_OK,
    ADC_UNKNOWN_OPTION,
    AOC_SOLUTION_ID_PARSE,
    AOC_NO_SUCH_QUESTION,
    AOC_OUT_OF_BOUNDS,
    AOC_SOLUTION_NOT_COMPLETE,
    AOC_PIPE_FAILED,
    AOC_NO_INPUT,

    AOC_ERR_END
};

/**
 *
 */
typedef struct {
    char* in;
    size_t size;
    size_t cursor;
} PipeInfo;

/**
 * Reads the arg. If there is no argument, fills the pipe.
 * @param arg - arg to select.
 * @param pipe - empty pipe object to fill in case of an empty arg.
 *
 * @returns Selected buffer.
 *      - 0 : arg
 *      - 1 : pipe
 *      - AOC_PIPE_FAILED : on allocation errors
 */
int read_input(char* arg, PipeInfo* pipe);

#define INFO(CODE, ...)                                                        \
    printf("INFO  | %17s %s#%s():%-4d - " CODE "\r\n", __now(), __FILE__,      \
           __PRETTY_FUNCTION__, __LINE__ __VA_ARGS__)

#define WARN(CODE)                                                             \
    fprintf(stderr, "WARN  | %17s %s#%s():%-4d - " CODE "\r\n", __now(),       \
            __FILE__, __PRETTY_FUNCTION__, __LINE__)
#define ERROR(CODE)                                                            \
    (fprintf(stderr, "ERROR | %17s %s#%s():%-4d - " #CODE "\r\n", __now(),     \
             __FILE__, __PRETTY_FUNCTION__, __LINE__),                         \
     CODE)

/* Current date time in string */
const char* __now();

/**
 * Compares the given argument with *two NULL terminated strings*, Short
 * and long versions
 * @param l_opt - NULL terminated long command. Example: --help
 * @param s_opt - NULL terminated short command. Example: -h
 * @param arg - arg to compare
 * 
 * @returns whether the argument matches or not
 */
bool cmparg(const char* l_opt, const char* s_opt, const char* arg);

/**
 * Compares the given argument with a single NULL terminated string
 * @param opt - NULL terminated long command. Example: --help
 * @param arg - arg to compare
 * 
 * @returns whether the argument matches or not
 */
bool cmparg_s(const char* opt, const char* arg);
