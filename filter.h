#ifndef FILTER_H
#define FILTER_H

#include "image.h"

void f_grayscale_rgb(Image_RGB *in, Image_RGB *out);
void f_threshold_rgb(Image_RGB *in, Image_RGB *out, float value);
void f_sobel_rgb(Image_RGB *in, Image_RGB *out);

#endif