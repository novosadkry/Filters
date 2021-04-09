#include "main.h"

const char* in_file;
const char* out_file;

int assign_args(int argc, char const **argv)
{
    if (argc < 3)
        return 0;

    in_file = argv[1];
    out_file = argv[2];

    return 1;
}

int main(int argc, char const **argv)
{
    if (!assign_args(argc, argv))
    {
        printf("Invalid arguments!\n");
        return 1;
    }

    Image img = image_load(in_file, STBI_rgb);
    printf("Loading image from '%s'...\n", in_file);

    if (img.data)
    {
        printf("Success! W: %d H: %d N: %d\n", img.w, img.h, img.channels);

        printf("Processing input file...\n");
        image_process(&img);

        if (!image_write_png(out_file, &img))
        {
            printf("Something broke when writing to output file!\n");
            image_free(&img);

            return 1;
        }

        printf("Success! Result saved to '%s'\n", out_file);
        image_free(&img);
        return 0;
    }

    printf("Failure! (Invalid image data)\n");
    return 1;
}