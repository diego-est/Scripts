#include <bits/stdc++.h>

#include <algorithm>
#include <bitmap_image.hpp>
#include <cmath>
#include <fstream>
#include <vector>

int main() {
  const int canvasSize = 2000;
  const int maxIteration = 20000;
  bitmap_image fractal(canvasSize, canvasSize);
  fractal.clear();

  constexpr double xFactor = 2.47 / canvasSize;
  constexpr double yFactor = 1.12 / canvasSize;
  constexpr long double colorFactor = 255.0 / canvasSize;
  constexpr int arraySize = std::pow(canvasSize, 2);

  static const auto arrayCoordinates = [] {
    std::array<std::complex<double>, arraySize> generatorArray{};
    for (int i = 0; i < arraySize; i++) {
      std::complex<double> vectorCoordinate =
          std::complex<double>(fma(i / canvasSize, xFactor, -2.00),
                               fma(i % canvasSize, yFactor, -0.56));
      generatorArray[i] = vectorCoordinate;
    }
    return generatorArray;
  }();

#pragma omp parallel for shared(arrayCoordinates)
  for (const std::complex<double>& coordinate : arrayCoordinates) {
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

    // const double z = sqrt(xSquared + ySquared);
    // iteration = static_cast<unsigned int>(
    //    1000.0 * log2(1.75 + iteration - log2(log2(z))) / log2(maxIteration));
    const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;

    fractal.set_pixel(index % canvasSize, index / canvasSize,
                      iteration * colorFactor,
                      std::min(iteration, 200) * colorFactor,
                      std::min(iteration, 20) * colorFactor);
    //                  jet_colormap[iteration]);
  }

  std::cout << colorFactor;
  fractal.save_image("mandelbrot.bmp");
  return 0;
}
