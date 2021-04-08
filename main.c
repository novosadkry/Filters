#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define BYTE unsigned char

int main(int argc, char const *argv[])
{
    int x, y, n;
    BYTE *data = stbi_load(argv[0], &x, &y, &n, 0);

    printf("%d %d %d", x, y, n);

    stbi_image_free(data);
    return 0;
}
