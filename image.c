#include "image.h"

#include "stblib.h"
#include "filter.h"

Byte *process_image_rgb(Pixel_RGB *data, int w, int h)
{
    Pixel_RGB *out = malloc(w * h * sizeof(Pixel_RGB));
    f_threshold_rgb(data, out, w, h, 0.5f);

    return (Byte*)out;
}

Byte *process_image(Byte *data, int w, int h, int channels)
{
    Byte* out;

    switch (channels)
    {
    case STBI_rgb:
        out = process_image_rgb((Pixel_RGB*)data, w, h);
        break;
    }

    return out;
}