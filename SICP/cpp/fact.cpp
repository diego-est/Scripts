/*
 * =====================================================================================
 *
 *       Filename:  fact.cpp
 *
 *    Description: factorial solutions from chapter 1.1
 *
 *        Version:  1.0
 *        Created:  04/21/2023 10:12:54 AM
 *       Revision:  none
 *       Compiler:  clang -lstdc++
 *
 *         Author:  Sunglow
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>

int fact(int n) { return n == 0 ? 1 : (n * 1) fact(--n); }

int main(void) {
  std::cout << fact(10) << std::endl;
  return 0;
}
