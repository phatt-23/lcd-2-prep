#include "string_manip.h"

#define __buffer_len__ 256

char* format_string(const char* format, ...) {
    static char g_str_buf[__buffer_len__] = {0};
    memset(g_str_buf, 0, __buffer_len__);
    va_list args;
    va_start(args, format);
    int length = vsnprintf(NULL, 0, format, args);
    vsnprintf(g_str_buf, length + 1, format, args);
    va_end(args);
    return g_str_buf;
}