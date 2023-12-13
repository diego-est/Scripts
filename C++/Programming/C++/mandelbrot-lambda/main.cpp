#include <bits/stdc++.h>

#include <algorithm>
#include <bitmap_image.hpp>
#include <cmath>
#include <fstream>
#include <vector>

int main() {
  const int canvasSize = 10000;
  const int maxIteration = 255;
  bitmap_image fractal(canvasSize, canvasSize);
  fractal.clear();

  constexpr double xFactor = (2.47 / canvasSize);
  constexpr double yFactor = (1.12 / canvasSize);
  std::vector<std::complex<double>> arrayCoordinates;
  for (int i = 0; i < canvasSize; i++) {
    for (int j = 0; j < canvasSize; j++) {
      std::complex<double> vectorCoordinate =
          std::complex<double>(fma(j, xFactor, -2.0), fma(i, yFactor, -0.56));
      arrayCoordinates.push_back(vectorCoordinate);
      // std::complex<double>(fma(j, xFactor, -2.0), fma(i, yFactor, -0.56))
    }
  }

  int index = 0;
  //#pragma omp parallel for
  for (std::complex<double> coordinate : arrayCoordinates) {
    double x = 0.0;
    double y = 0.0;
    double xSquared = 0.0;
    double ySquared = 0.0;
    int iteration = 0;

    while (std::islessequal((xSquared + ySquared), 4) &&
           (iteration < maxIteration)) {
      y = 2 * fma(x, y, coordinate.imag());
      x = xSquared - ySquared + coordinate.real();
      xSquared = x * x;
      ySquared = y * y;
      iteration++;
    }

    const int xPixel = index % canvasSize;
    const int yPixel = index / canvasSize;
    index++;
    fractal.set_pixel(xPixel, yPixel, iteration, iteration, iteration);
  }

  //fractal.save_image("mandelbrot.bmp");
  return 0;
}
