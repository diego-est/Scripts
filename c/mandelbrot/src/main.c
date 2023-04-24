/* ========================================================================
 *
 *     Filename:  main.c
 *  Description:  mandelbrot set renderer written in C
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define return_defer(value)                                                    \
  do {                                                                         \
    result = (value);                                                          \
    goto defer;                                                                \
  } while (0)
#define WIDTH 100
#define HEIGHT 100

// declare canvas struct and typedef so it can be passed to functions
struct Canvas {
  uint32_t pixels[HEIGHT * WIDTH];
  size_t width;
  size_t height;
};
typedef struct Canvas Canvas;

// function prototypes
int save_to_ppm(Canvas canvas, const char *file_path);
void fill(Canvas *canvas, uint32_t color);
void set_pixel(Canvas *canvas, size_t i, uint32_t color);
long double lerp(long double, long double, long double);

int main(void) {
  struct Canvas canvas;
  canvas.width = WIDTH;
  canvas.height = HEIGHT;

  for (int i = 0; i < WIDTH * HEIGHT; ++i) {
  // lerp between these values for the reals and imaginaries
  // -2.00 <-> 0.47 = 2.47
  // -1.12 <-> 1.12 = 2.24
    const long double percent = i / (long double)(WIDTH * HEIGHT);
    const long double real = lerp(-2.0, 0.24, percent);
    const long double imag = lerp(-1.12, 1.12, percent);

    printf("%Lf: %Lf\n", percent, imag);

    long double x = 0.0;
    long double y = 0.0;
    long double x_squared = 0.0;
    long double y_squared = 0.0;
    uint8_t iteration = 0;
    while (x_squared + y_squared <= 4 && iteration <= 254) {
      y = 2 * x * y + imag;
      x = x_squared - y_squared + real;
      x_squared = x * x;
      y_squared = y * y;
      iteration++;
    }
    const uint8_t colors[4] = {0xFF, iteration, iteration, iteration};
    const uint32_t color = *(uint32_t *)colors;

    set_pixel(&canvas, i, color);
  }
  save_to_ppm(canvas, "output.ppm");
  return 0;
}

void fill(Canvas *canvas, uint32_t color) {
  for (size_t i = 0; i < canvas->width * canvas->height; ++i)
    canvas->pixels[i] = color;
}

int save_to_ppm(Canvas canvas, const char *file_path) {
  int result = 0;
  FILE *f = NULL;

  {
    f = fopen(file_path, "wb");
    if (f == NULL)
      return_defer(errno);

    fprintf(f, "P6\n%zu %zu 255\n", canvas.width, canvas.height);
    if (ferror(f))
      return_defer(errno);

    for (size_t i = 0; i < canvas.width * canvas.height; ++i) {
      // pixels 0xAABBGGRR
      const uint32_t pixel = canvas.pixels[i];
      const uint8_t bytes[3] = {(pixel >> (8 * 1)) & 0xFF,
                                (pixel >> (8 * 2)) & 0xFF,
                                (pixel >> (8 * 3)) & 0xFF};
      fwrite(bytes, sizeof(bytes), 1, f);
      if (ferror(f))
        return_defer(errno);
    }
  }

defer:
  if (f)
    fclose(f);
  return result;
}

void set_pixel(Canvas *canvas, size_t i, uint32_t color) {
  canvas->pixels[i] = color;
}

long double lerp(long double a, long double b, long double t) {
  return a + t * (b - a);
}
