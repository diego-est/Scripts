/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Fast Inverse Square Root
 *
 *        Version:  1.0
 *        Created:  02/18/2023 08:47:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sunglow
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <bit>
#include <cstdint>
#include <limits>
#include <iostream>

constexpr float Q_rsqrt(float number) noexcept {
  static_assert(std::numeric_limits<float>::is_iec559);
  const float y = std::bit_cast<float>(
      0x5f3759df - (std::bit_cast<std::uint32_t>(number) >> 1));
  return y * (1.5f - (number * 0.5f * y * y));
}

int main() { std::cout << Q_rsqrt(1); }
