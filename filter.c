#include "filter.h"
#include <stdlib.h>
#include <math.h>

float SOBEL_KERNEL[2][9] =
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

void f_grayscale_rgb(Image_RGB *in, Image_RGB *out)
{
    for (int x = 0; x < in->w; x++)
    {
        for (int y = 0; y < in->w; y++)
        {
            Pixel_RGB p;
            image_get_pixel_rgb(in, x, y, &p);

            float result = roundf(pixel_rgb_luminance(p) * 255);
            image_set_pixel_rgb(out, x, y, (Pixel_RGB) { result, result, result });
        }
    }
}

void f_threshold_rgb(Image_RGB *in, Image_RGB *out, float value)
{
    for (int x = 0; x < in->w; x++)
    {
        for (int y = 0; y < in->w; y++)
        {
            Pixel_RGB p;
            image_get_pixel_rgb(in, x, y, &p);

            if (pixel_rgb_avg(p) > value)
                image_set_pixel_rgb(out, x, y, (Pixel_RGB) { 255, 255, 255 });
        }
    }
}

void f_sobel_rgb(Image_RGB *in, Image_RGB *out)
{
    for (int x = 0; x < in->w; x++)
    {
        for (int y = 0; y < in->h; y++)
        {
            float sumX = 0, sumY = 0;

            for (int u = -1; u <= 1; u++)
            {
                for (int v = -1; v <= 1; v++)
                {
                    Pixel_RGB p;

                    if (!image_get_pixel_rgb(in, x + u, y + v, &p))
                        continue;

                    float avg = pixel_rgb_avg(p);
                    int kernel_index = (u + 1) + (v + 1) * 3;

                    sumX += SOBEL_KERNEL[0][kernel_index] * avg;
                    sumY += SOBEL_KERNEL[1][kernel_index] * avg;
                }
            }

            float result = fabs(sumX + sumY) / 2.0f;
            result = fmax(0.0, fmin(result, 1.0f));
            result = roundf(result * 255);

            image_set_pixel_rgb(out, x, y, (Pixel_RGB) { result, result, result });
        }
    }
}
