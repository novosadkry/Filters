#ifndef IMAGE_H
#define IMAGE_H

typedef unsigned char Byte;

typedef struct
{
    Byte r, g, b;
} Pixel_RGB;

float pixel_rgb_avg(Pixel_RGB p);
float pixel_rgb_luminance(Pixel_RGB p);

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

void image_swap_buffers(Image* b1, Image* b2);

void image_process(Image* img);
void image_process_rgb(Image_RGB* img);

int image_write_png(const char* file, Image* img);

Image image_load(const char* file, int channels);
void image_free(Image* img);

int image_set_pixel_rgb(Image_RGB* img, int x, int y, Pixel_RGB value);
int image_get_pixel_rgb(Image_RGB* img, int x, int y, Pixel_RGB* out);

#endif