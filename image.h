#ifndef IMAGE_H
#define IMAGE_H

typedef unsigned char Byte;

typedef struct
{
    Byte r, g, b;
} Pixel_RGB;

typedef struct
{
    int w, h, channels;
    Byte* data;
} Image;

typedef struct
{
    int w, h, channels;
    Pixel_RGB* data;
} Image_RGB;

void image_process(Image* img);
void image_process_rgb(Image_RGB* img);

int image_write_png(const char* file, Image* img);

Image image_load(const char* file, int channels);
void image_free(Image* img);

void image_set_pixel_rgb(Image_RGB* img, int x, int y, Pixel_RGB value);
Pixel_RGB image_get_pixel_rgb(Image_RGB* img, int x, int y);

#endif