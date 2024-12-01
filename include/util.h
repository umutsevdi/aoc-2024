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

/// Error codes of the program
enum aoc_code_t {
    AOC_OK,                   /// Process completed successfully.
    ADC_UNKNOWN_OPTION,       /// Given CLI option is invalid.
    AOC_NO_QUESTION_PROVIDED, /// No question provided to query.
    AOC_SOLUTION_ID_PARSE,    /// Invalid question number.
    AOC_NO_SUCH_QUESTION,     /// No such question.
    AOC_OUT_OF_BOUNDS,        /// Provided id is out of bounds
    AOC_SOLUTION_NOT_COMPLETE,/// Solution is not yet completed for the question
    AOC_FILE_NOT_FOUND,       /// No such file or directory.
    AOC_NOT_A_FILE,           /// Expected a file, found a directory.
    AOC_PIPE_FAILED,          /// Error during allocation.
    AOC_NO_INPUT,             /// No input provided

    AOC_ERR_END/// Error size, invalid error type
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

/// Current date time in string
const char* __now();

/// Swap values of two long
void swapl(long* a, long* b);

/**
 * Sort an array with n items from smallest to biggest.
 * @param arr to sort
 * @param n number of elements
 */
void sortl(long* arr, int n);
