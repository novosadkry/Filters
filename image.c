#include "image.h"

#include "stblib.h"
#include "filter.h"

void image_process_rgb(Image_RGB* img)
{
    Image_RGB tmp = *img;
    tmp.data = calloc(img->w * img->h, sizeof(Pixel_RGB));

    f_threshold_rgb(img, &tmp, 0.5f);

    free(img->data);
    img->data = tmp.data;
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

void image_set_pixel_rgb(Image_RGB* img, int x, int y, Pixel_RGB value)
{
    if (x < img->w && y < img->h)
    {
        int i = x + img->w * y;
        img->data[i] = value;
    }
}

Pixel_RGB image_get_pixel_rgb(Image_RGB* img, int x, int y)
{
    if (x < img->w && y < img->h)
    {
        int i = x + img->w * y;
        return img->data[i];
    }

    return (Pixel_RGB) { 0, 0, 0 };
}

void image_free(Image* img)
{
    stbi_image_free(img->data);
    img->w = img->h = 0;
    img->channels = 0;
}