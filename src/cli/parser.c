#include "cli.h"
#include "util.h"
#include <sys/stat.h>
#include <unistd.h>

/**
 * Select a file descriptor based on argument.
 * @param arg - to pick.
 * @returns a file descriptor or NULL
 *  - FILE* if file is valid and readable
 *  - NULL if AOC_FILE_NOT_FOUND | AOC_NOT_A_FILE
 *  - If no input is provided: stdin
 */
static FILE* pickfd(char* arg)
{
    FILE* file;
    if (arg != NULL && strlen(arg) != 0) {
        struct stat stat_buf;
        if (access(arg, F_OK) != 0) {
            return ERROR(AOC_FILE_NOT_FOUND), NULL;
        } else if (stat(arg, &stat_buf) != 0 || !S_ISREG(stat_buf.st_mode)) {
            return ERROR(AOC_NOT_A_FILE), NULL;
        }
        file = fopen(arg, "r");
        return file;
    }
    return stdin;
}

enum aoc_code_t read_input(char* arg, CliInput* input)
{
    FILE* file = pickfd(arg);
    if (!file) { return ERROR(AOC_NO_INPUT); }

    char buffer[4096] = {0};
    char* tmp = NULL;
    tmp = calloc(sizeof(buffer), sizeof(char));
    if (tmp == NULL) {
        if (file != stdin) { fclose(file); }
        return ERROR(AOC_PIPE_FAILED);
    }
    input->data = tmp;
    input->size = sizeof(buffer);
    size_t buffer_len = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer_len = strnlen(buffer, sizeof(buffer));
        if (input->_cursor + buffer_len > input->size) {
            tmp = realloc(input->data, input->size * 2);
            if (tmp == NULL) {
                if (file != stdin) { fclose(file); }
                free(input->data);
                return ERROR(AOC_PIPE_FAILED);
            }
            input->data = tmp;
            input->size *= 2;
        };
        memcpy(input->data + input->_cursor, buffer, buffer_len);
        input->_cursor += buffer_len;
        input->data[input->_cursor] = '\0';
    }
    if (strnlen(input->data, input->size) == 0) {
        if (file != stdin) { fclose(file); }
        return ERROR(AOC_NO_INPUT);
    }
    if (file != stdin) { fclose(file); }
    input->len = strnlen(input->data, input->size);
    return AOC_OK;
}

bool cmpargs(const char* l_opt, const char* s_opt, const char* arg)
{
    if (l_opt == NULL || s_opt == NULL || arg == NULL) { return false; }
    int l_opt_len = strlen(l_opt);
    int s_opt_len = strlen(s_opt);
    return strncmp(s_opt, arg, s_opt_len) == 0
           || strncmp(l_opt, arg, l_opt_len) == 0;
}

bool cmparg(const char* opt, const char* arg)
{
    if (opt == NULL || arg == NULL) { return false; }
    return strncmp(opt, arg, strlen(opt)) == 0;
}

char* parse_lines(const char* input, const size_t input_s, size_t* indices,
                  size_t* indices_s)
{
    char* token_head = strdup(input);
    char* token = token_head + 1;
    size_t size = 0;
    indices[0] = 0;
    while (*token != 0 && token < token_head + input_s) {
        if (*token == '\n') {
            if (*(token - 1) == '\r') { *(token - 1) = '\0'; }
            *token = '\0';
            size++;
            indices[size] = token - token_head + 1;
        }
        token++;
    }
    *indices_s = size;
    return token_head;
}
