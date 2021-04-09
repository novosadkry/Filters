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

void f_threshold_rgb(Image_RGB *in, Image_RGB *out, float value)
{
    for (int x = 0; x < in->w; x++)
    {
        for (int y = 0; y < in->w; y++)
        {
            Pixel_RGB p = image_get_pixel_rgb(in, x, y);
            float sum = (p.r + p.g + p.b) / (3 * 255.0f);

            if (sum > value)
                image_set_pixel_rgb(out, x, y, (Pixel_RGB) { 255, 255, 255 });
            else
                image_set_pixel_rgb(out, x, y, (Pixel_RGB) { 0, 0, 0 });
        }
    }
}

void f_sobel_rgb(Image_RGB *in, Image_RGB *out)
{
    for (int x = 0; x < in->w; x++)
    {
        for (int y = 0; y < in->h; y++)
        {

        }
    }
}
