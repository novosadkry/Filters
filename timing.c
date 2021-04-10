#include "timing.h"
#include <time.h>

static clock_t g_start;
static clock_t g_diff;

void timing_start()
{
    g_start = clock();
}

void timing_end()
{
    g_diff = clock() - g_start;
}

long timing_get()
{
    return g_diff * 1000 / CLOCKS_PER_SEC;
}
