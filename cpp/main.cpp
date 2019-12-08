#include "stb_image_write.h"

typedef struct { float real; float img; } complex;

complex add(complex a, complex b)
{
    complex r;
    r.real = a.real + b.real;
    r.img = a.img + b.img;
    return r;
}

complex mul(complex a, complex b)
{
    complex r;
    r.real = (a.real * b.real) - (a.img * b.img);
    r.img = (a.real * b.img) + (a.img * b.real);
    return r;
}

float squared_norm(complex a)
{
    return a.real * a.real + a.img * a.img;
}

float re_start = -2.25;
float re_end = 0.75;
float re_step = re_end - re_start;
float im_start = -1.5;
float im_end = 1.5;
float im_step = im_end - im_start;

unsigned char iterate(complex c)
{
    unsigned char max_iterations = 226;
    unsigned char current_iteration = 0;
    complex z;
    z.real = 0; z.img = 0;
    while (current_iteration < max_iterations && squared_norm(z) < 4)
    {
        z = add(mul(z, z), c);
        ++current_iteration;
    }
    return current_iteration;
}

void mandelbrot_monochrome(int width, int height)
{
    unsigned char image[height][width];
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {

            complex c;
            c.real = re_start + ((float) i/width) * re_step;
            c.img = im_start + ((float) j/height) * im_step;
            image[i][j] = iterate(c);
        }
    }
    stbi_write_bmp("temp.bmp", width, height, 1, image);
}

int main() {
    int w = 500;
    int h = 500;
    mandelbrot_monochrome(w, h);
    return 0;
}
