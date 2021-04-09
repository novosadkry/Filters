#ifndef FILTER_H
#define FILTER_H

#include "image.h"

void f_threshold_rgb(Pixel_RGB *in, Pixel_RGB *out, int w, int h, float value);
void f_sobel_rgb(Pixel_RGB *in, Pixel_RGB *out, int w, int h);

#endif