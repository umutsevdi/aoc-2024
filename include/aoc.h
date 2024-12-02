#pragma once
/*******************************************************************************
 * \file
 * File: include/aoc.h
 * Created: 12/01/24
 * Author: Umut Sevdi
 * Description: Advent of Code 2024 Solutions
 *
 * Project: umutsevdi/aoc-2024
 * License: MIT License
 ******************************************************************************/
#include "cli.h"

/** An interface for any Advent of Code problem */
typedef struct {
    /** Command to execute the given advent of code */
    char* cmd;
    /** Description of the problem */
    const char* description;
    /** Function to execute, NULL if unfinished */
    enum aoc_code_t (*run)(CliInput* input);
} Solution;

#define SOLUTION_SIZE 25

/** Shared solution array */
extern Solution* solutions[SOLUTION_SIZE];

/** Define a solution for given day. */
#define SOLUTION(DAY, ...)                                                     \
    Solution DAY_##DAY##_impl = (Solution)__VA_ARGS__;                         \
    Solution* AOC_DAY_##DAY = &DAY_##DAY##_impl

/** Links the remaining solutions. */
void setup_solution_list();
