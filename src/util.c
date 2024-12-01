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

inline void swapl(long* a, long* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

inline void sortl(long* arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapl(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
}
