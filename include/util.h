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

#define WARN(CODE)                                                             \
    fprintf(stderr, "WARN  | %17s %s#%s():%-4d - " #CODE "\r\n", __now(), __FILE__,    \
            __PRETTY_FUNCTION__, __LINE__)
#define INFO(CODE)                                                             \
    (printf("INFO  | %17s %s#%s():%-4d - " #CODE "\r\n", __now(), __FILE__,            \
            __PRETTY_FUNCTION__, __LINE__),                                    \
     CODE)

#define ERROR(CODE)                                                            \
    (fprintf(stderr, "ERROR | %17s %s#%s():%-4d - " #CODE "\r\n", __now(), __FILE__,   \
             __PRETTY_FUNCTION__, __LINE__),                                   \
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
