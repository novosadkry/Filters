#ifndef IMAGE_H
#define IMAGE_H

typedef unsigned char Byte;

typedef struct
{
    Byte r, g, b;
} Pixel_RGB;

Byte *process_image(Byte *data, int w, int h, int channels);
Byte *process_image_rgb(Pixel_RGB *data, int w, int h);

#endif