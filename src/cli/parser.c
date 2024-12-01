#include "cli.h"
#include "util.h"
#include <sys/stat.h>
#include <unistd.h>

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

enum aoc_code_t read_input(char* arg, CliInput* pipe)
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
    pipe->data = tmp;
    pipe->size = sizeof(buffer);
    size_t buffer_len = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer_len = strnlen(buffer, sizeof(buffer));
        if (pipe->cursor + buffer_len > pipe->size) {
            tmp = realloc(pipe->data, pipe->size * 2);
            if (tmp == NULL) {
                if (file != stdin) { fclose(file); }
                free(pipe->data);
                return ERROR(AOC_PIPE_FAILED);
            }
            pipe->data = tmp;
            pipe->size *= 2;
        };
        memcpy(pipe->data + pipe->cursor, buffer, buffer_len);
        pipe->cursor += buffer_len;
        pipe->data[pipe->cursor] = '\0';
    }
    if (strnlen(pipe->data, pipe->size) == 0) {
        if (file != stdin) { fclose(file); }
        return ERROR(AOC_NO_INPUT);
    }
    if (file != stdin) { fclose(file); }
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
