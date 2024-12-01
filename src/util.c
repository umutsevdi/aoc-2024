#include "util.h"
#include <time.h>

static struct tm* _tm;

const char* __now()
{
    static time_t _now = {0};
    time(&_now);
    _tm = localtime(&_now);
    static char string[20];
    snprintf(string, 20, "%02d/%02d/%02d %02d:%02d:%02d", _tm->tm_mday,
             _tm->tm_mon + 1, (_tm->tm_year + 1900) % 100, _tm->tm_hour,
             _tm->tm_min, _tm->tm_sec);
    return string;
}

bool cmparg(const char* l_opt, const char* s_opt, const char* arg)
{
    if (l_opt == NULL || s_opt == NULL || arg == NULL) { return false; }
    int l_opt_len = strlen(l_opt);
    int s_opt_len = strlen(s_opt);
    return strncmp(s_opt, arg, s_opt_len) == 0
           || strncmp(l_opt, arg, l_opt_len) == 0;
}

bool cmparg_s(const char* opt, const char* arg)
{
    if (opt == NULL || arg == NULL) { return false; }
    return strncmp(opt, arg, strlen(opt)) == 0;
}

int read_input(char* arg, PipeInfo* pipe)
{
    // if there is an arg use it instead of pipe
    if (arg != NULL && strlen(arg) != 0) { return 0; }
    char buffer[4096] = {0};
    char* tmp = NULL;
    tmp = calloc(sizeof(buffer), sizeof(char));
    if (tmp == NULL) { return ERROR(AOC_PIPE_FAILED); }
    pipe->in = tmp;
    pipe->size = sizeof(buffer);
    size_t buffer_len = 0;
    while (fgets(buffer, sizeof(buffer), stdin)) {
        buffer_len = strnlen(buffer, sizeof(buffer));
        if (pipe->cursor + buffer_len > pipe->size) {
            tmp = realloc(pipe->in, pipe->size * 2);
            if (tmp == NULL) {
                free(pipe->in);
                return ERROR(AOC_PIPE_FAILED);
            }
            pipe->in = tmp;
            pipe->size *= 2;
        };
        memcpy(pipe->in + pipe->cursor, buffer, buffer_len);
        pipe->cursor += buffer_len;
        pipe->in[pipe->cursor] = '\0';
    }
    if (strnlen(pipe->in, pipe->size) == 0) { return ERROR(AOC_NO_INPUT); }
    return 1;
}
