#include <assert.h>
#include <iostream>
#include <numeric>
#include <utility>

int main() {
  std::pair<int, int> firstFraction;
  std::pair<int, int> secondFraction;

  std::cout
      << "This program adds two fractions!\n"
         "Enter the numerator and the denominator of the first fraction: ";
  std::cin >> firstFraction.first >> firstFraction.second;
  assert(firstFraction.second != 0 && "Denominator must not be zero.");

  std::cout
      << "Enter the numerator and the denominator of the second fraction: ";
  std::cin >> secondFraction.first >> secondFraction.second;
  assert(secondFraction.second != 0 && "Denominator must not be  zero.");

  std::pair<int, int> fraction;
  fraction.first = firstFraction.first  * secondFraction.second +
                   firstFraction.second * secondFraction.first;
  fraction.second = firstFraction.second * secondFraction.second;

  int gcd = std::gcd(fraction.first, fraction.second);
  fraction.first /= gcd;
  fraction.second /= gcd;

  std::cout << "The sum of " << firstFraction.first << "/"
            << firstFraction.second << " and " << secondFraction.first << "/"
            << secondFraction.second << " is " << fraction.first << "/"
            << fraction.second << ".\n";
  return 0;
}
