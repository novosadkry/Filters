#include "main.h"

const char* in_file ;
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
        printf("Invalid arguments!");
        return 1;
    }

    int w, h, n;
    Byte *in_data = stbi_load(in_file, &w, &h, &n, STBI_rgb);

    printf("Loading image from '%s'...\n", in_file);

    if (in_data)
    {
        printf("Success! ");
        printf("W: %d H: %d N: %d\n", w, h, n);

        printf("Processing input file...\n");
        Byte *out_data = process_image(in_data, w, h, n);

        if (!stbi_write_png(out_file, w, h, n, out_data, w * n))
        {
            printf("Something broke when writing to output file!");
            stbi_image_free(out_data);
            stbi_image_free(in_data);

            return 1;
        }

        printf("Success! Result saved to '%s'", out_file);
        stbi_image_free(out_data);
        stbi_image_free(in_data);
        return 0;
    }

    printf("Failure! (Invalid image data)\n");
    return 1;
}