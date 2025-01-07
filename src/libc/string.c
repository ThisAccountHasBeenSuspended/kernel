#include <string.h>

unsigned int strlen(const char* const str)
{
    unsigned int ret = 0;
    for (; str[ret] != '\0'; ret++);
    return ret;
}