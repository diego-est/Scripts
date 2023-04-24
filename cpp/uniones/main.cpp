/* =====================================================================================
 *
 *       Filename:  main.cpp
 *    Description:
 *        Version:  0.1.0
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> a = {1, 3, 5, 7, 0};
  std::vector<int> b = {3, 6, 7, 9};

  std::vector<int> out;

  for (int number : a)
    if (std::count(out.begin(), out.end(), number) == 0)
      out.push_back(number);

  for (int number : b)
    if (std::count(out.begin(), out.end(), number) == 0)
      out.push_back(number);

  for (int number : out)
    std::cout << number << std::endl;

  return 0;
}
