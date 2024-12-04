#pragma once
/*******************************************************************************
 * \file
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
#define CAPACITY 4096

/** Error codes of the program */
enum aoc_code_t {
    /** Process completed successfully. */ AOC_OK,
    /** Given CLI option is invalid.*/ ADC_UNKNOWN_OPTION,
    /** No question provided to query.*/ AOC_NO_QUESTION_PROVIDED,
    /** Invalid question number.*/ AOC_SOLUTION_ID_PARSE,
    /** No such question.*/ AOC_NO_SUCH_QUESTION,
    /** Provided id is out of bounds*/ AOC_OUT_OF_BOUNDS,
    /** Solution is not yet completed  */ AOC_SOLUTION_UNFINISHED,
    /** No such file or directory.*/ AOC_FILE_NOT_FOUND,
    /** Expected a file, found a directory.*/ AOC_NOT_A_FILE,
    /** Error during allocation.*/ AOC_PIPE_FAILED,
    /** No input provided*/ AOC_NO_INPUT,
    /** Error size, invalid error type*/ AOC_ERR_END,
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

/** Current date time in string */
const char* __now();

/** Swap values of two long */
void swapl(long* a, long* b);

/**
 * Sort an array with n items from smallest to biggest.
 * @param arr to sort
 * @param n number of elements
 */
void sortl(long* arr, int n);

/** Parses an int return false on failure */
bool parse_int(char* string, long* value);
