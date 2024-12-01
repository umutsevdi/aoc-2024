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
