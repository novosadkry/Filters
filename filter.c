#include "filter.h"
#include <stdlib.h>

void f_threshold_rgb(Pixel_RGB *in, Pixel_RGB *out, int w, int h)
{
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            int i = x + w * y;
            out[i] = in[i];
        }
    }
}
