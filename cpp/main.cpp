#include <stdlib.h>
#include "stb_image_write.h"

int main() {
    int w = 200;
    int h = 200;
    char image[h*w];
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            image[i*h + j] = rand() % 256;
        }
    }
    stbi_write_bmp("test.bmp", w, h, 1, image);
    return 0;
}
