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
    AOC_NO_QUESTION_PROVIDED,
    AOC_SOLUTION_ID_PARSE,
    AOC_NO_SUCH_QUESTION,
    AOC_OUT_OF_BOUNDS,
    AOC_SOLUTION_NOT_COMPLETE,
    AOC_FILE_NOT_FOUND,
    AOC_NOT_A_FILE,
    AOC_PIPE_FAILED,
    AOC_NO_INPUT,
    AOC_ERR_END
};

#define INFO(CODE, ...)                                                        \
    printf("INFO  | %17s %s#%s():%-4d - " CODE "\r\n", __now(), __FILE__,      \
           __PRETTY_FUNCTION__, __LINE__ __VA_ARGS__)

#define WARN(CODE)                                                             \
    fprintf(stderr, "WARN  | %17s %s#%s():%-4d - " #CODE "\r\n", __now(),      \
            __FILE__, __PRETTY_FUNCTION__, __LINE__)
#define ERROR(CODE)                                                            \
    (fprintf(stderr, "ERROR | %17s %s#%s():%-4d - " #CODE "\r\n", __now(),     \
             __FILE__, __PRETTY_FUNCTION__, __LINE__),                         \
     CODE)

/* Current date time in string */
const char* __now();

void swapl(long* a, long* b);

void sortl(long* arr, int n);
