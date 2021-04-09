#include "filter.h"
#include <stdlib.h>

float sobel_kernel[2][9] =
{
    {
         1,  0, -1,
         2,  0, -2,
         1,  0, -1
    },
    {
         1,  2,  1,
         0,  0,  0,
        -1, -2, -1
    }
};

void f_threshold_rgb(Pixel_RGB *in, Pixel_RGB *out, int w, int h, float value)
{
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            int i = x + w * y;
            Pixel_RGB p = in[i];

            float sum = (p.r + p.g + p.b) / (3 * 255.0f);

            if (sum > value)
                out[i] = (Pixel_RGB) { 255, 255, 255 };
            else
                out[i] = (Pixel_RGB) { 0, 0, 0 };
        }
    }
}

void f_sobel_rgb(Pixel_RGB *in, Pixel_RGB *out, int w, int h)
{
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {

        }
    }
}
