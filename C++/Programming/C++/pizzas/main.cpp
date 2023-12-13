/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: pizzas
 *
 *        Version:  1.0
 *        Created:  02/22/2023 07:13:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  float diameter, people;
  const float sliceArea = 14.125;

  std::cout << "This program calculates the number of pizzas you'll need to "
               "order for a party.\n";
  std::cout << "Enter the number of people attending the party: ";
  std::cin >> people;
  std::cout << "Enter the diameter of the pizza in inches: ";
  std::cin >> diameter;
  float totalArea = (M_PI * pow(diameter / 2, 2)) / sliceArea;
  float totalPizzas = (people * 4) / totalArea;
  std::cout << "You will need to order " << ceil(totalPizzas) << " pizzas.\n";
}
