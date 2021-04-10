#ifndef TIMING_H
#define TIMING_H

#define TIMING_MEASURE(x) \
    timing_start();       \
    x;                    \
    timing_end();         \

void timing_start();
void timing_end();
long timing_get();

#endif