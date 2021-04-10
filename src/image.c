#include "image.h"

#include "stblib.h"
#include "filter.h"

void image_swap_buffers(Image* b1, Image* b2)
{
    Byte* tmp = b1->data;
    b1->data = b2->data;
    b2->data = tmp;
}

void image_process_rgb(Image_RGB* img)
{
    Image_RGB tmp = *img;
    tmp.data = calloc(img->w * img->h, sizeof(Pixel_RGB));

    f_sobel_rgb(img, &tmp);
    image_swap_buffers((Image*)img, (Image*)&tmp);

    free(tmp.data);
}

void image_process(Image* img)
{
    switch (img->channels)
    {
    case STBI_rgb:
        image_process_rgb((Image_RGB*)img);
        break;
    }
}

int image_write_png(const char* file, Image* img)
{
    return stbi_write_png(
        file,
        img->w,
        img->h,
        img->channels,
        img->data,
        img->w * img->channels
    );
}

Image image_load(const char* file, int channels)
{
    Image img;
    img.data = stbi_load(
        file,
        &img.w,
        &img.h,
        &img.channels,
        channels
    );

    return img;
}

int image_set_pixel_rgb(Image_RGB* img, int x, int y, Pixel_RGB value)
{
    if ((x > 0 && x < img->w) && (y > 0 && y < img->h))
    {
        int i = x + img->w * y;
        img->data[i] = value;

        return 1;
    }

    return 0;
}

int image_get_pixel_rgb(Image_RGB* img, int x, int y, Pixel_RGB* out)
{
    if ((x > 0 && x < img->w) && (y > 0 && y < img->h))
    {
        int i = x + img->w * y;
        *out = img->data[i];

        return 1;
    }

    return 0;
}

float pixel_rgb_avg(Pixel_RGB p)
{
    return (p.r + p.g + p.b) / (3 * 255.0f);
}

float pixel_rgb_luminance(Pixel_RGB p)
{
    return (0.2126f * p.r + 0.7152f * p.g + 0.0722f * p.b) / 255.0f;
}

void image_free(Image* img)
{
    stbi_image_free(img->data);
    img->w = img->h = 0;
    img->channels = 0;
}