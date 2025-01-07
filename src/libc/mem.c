#include <mem.h>

void memcpy(const void* const src, void* const dest, unsigned int bytes)
{
    const char* const csrc = (const char* const)src;
    char* const cdest = (char* const)dest;

    for (unsigned int i = 0; i < bytes; i++)
    {
        cdest[i] = csrc[i];
    }
}