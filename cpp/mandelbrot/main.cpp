#include <bits/stdc++.h>
#include <bitmap_image.hpp>
#include <fstream>
#include <cmath>

int main() {
    const int canvasSize = 2000;
    const int maxIteration = 255;
    float arrayX[canvasSize];
    float arrayY[canvasSize];

    bitmap_image fractal(canvasSize, canvasSize);
    fractal.clear();

    const float factor = (2.24 / canvasSize);
    for(int i = 0; i < canvasSize; i++) {
        arrayX[i] = (factor * i) - 1.77;
        arrayY[i] = (factor * i) - 1.12;
    }

    for(float &xCoordinate : arrayX) {
        for(float &yCoordinate : arrayY) {
            float x = 0.0;
            float y = 0.0;
            float xSquared = 0.0;
            float ySquared = 0.0;
            int iteration = 0;

            while( (xSquared + ySquared <= 4) && (iteration < maxIteration) ) {
                y = 2 * x * y + yCoord;
                x = xSquared - ySquared + xCoord;
                xSquared = pow(x, 2);
                ySquared = pow(y, 2);
                iteration++;
            }

            const int xPixel = &xCoord - arrayX;
            const int yPixel = &yCoord - arrayY;
            fractal.set_pixel(xPixel, yPixel, iteration, iteration, iteration);
        }
    }

    fractal.save_image("mandelbrot.bmp");
    return 0;
}
