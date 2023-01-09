#include <bits/stdc++.h>
#include <bitmap_image.hpp>
#include <fstream>
#include <cmath>

int main() {
    const int canvasSize = 2000;

    bitmap_image fractal(canvasSize, canvasSize);
    fractal.clear();

    for(int i = 0; i < canvasSize; i++) {
        for(int j = 0; j < canvasSize; j++) {
            float x0 = ( (2.24 / canvasSize) * i) - 1.77;
            float y0 = ( (2.24 / canvasSize) * j) - 1.12;
            float x = 0.0;
            float y = 0.0;
            int iteration = 0;
            const int maxIteration = 255;

            while( (x*x + y*y <= 2*2) && (iteration < maxIteration)) {
                const float xtemp = x*x - y*y + x0;
                y = 2 * x * y + y0;
                x = xtemp;
                iteration++;
            }

            fractal.set_pixel(i, j, iteration, iteration, iteration);
            //std::cout << iteration << " ";
        }
        //std::cout << std::endl;
    }

    fractal.save_image("mandelbrot.bmp");
    return 0;
}
