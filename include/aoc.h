#pragma once
/*******************************************************************************
 *
 * File: include/aoc.h
 * Created: 12/01/24
 * Author: Umut Sevdi
 * Description: Advent of Code 2024 Solutions
 *
 * Project: umutsevdi/aoc-2024
 * License: MIT License
 ******************************************************************************/
/**
 * An interface for any Advent of Code problem
 */
typedef struct aoc_solution_t {
    /* Command to execute the given advent of code */
    char* cmd;
    /* Description of the problem */
    const char* description;
    /* Function to execute, NULL if the question is not finished yet */
    enum aoc_code_t (*run)(char* input);
} Solution;

#define SOLUTION_SIZE 25
/* Shared solution array */
extern Solution* solutions[SOLUTION_SIZE];

#define SOLUTION(DAY, ...)                                                     \
    Solution DAY_##DAY##_impl = (Solution)__VA_ARGS__;                         \
    struct aoc_solution_t* AOC_DAY_##DAY = &DAY_##DAY##_impl

void setup_solution_list();
