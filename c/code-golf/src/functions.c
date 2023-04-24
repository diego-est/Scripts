/*
 * =====================================================================================
 *
 *       Filename:  functions.c
 *
 *    Description:  code golf solutions 
 *
 *        Version:  1.0
 *        Created:  04/19/2023 09:42:21 PM
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Sunglow
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

void abundant(void) {
  for (int i = 0; i <= 200; ++i) {
    int accumulator = 0;
    
    for (int j = 1; j < i; ++j) {
      if (i % j == 0)
        accumulator += j;
    }
    if (accumulator > i)
      printf("%d\n", i);
  }
}

void abundant_long(void) {
  for (int i = 0; i <= 1000; ++i) {
    int accumulator = 0;
    
    for (int j = 1; j < i; ++j) {
      if (i % j == 0)
        accumulator += j;
    }
    if (accumulator > i)
      printf("%d\n", i);
  }
}

int collatz_calculator(const int n, int iteration) {
  ++iteration;
  if (n == 1) {
    return iteration;
  } else if (n % 2 == 0) {
    iteration = collatz_calculator(n / 2, iteration);
  } else {
    iteration = collatz_calculator(n*3 + 1, iteration);
  }
  return iteration;
}
void collatz(void) {
  for (int i = 1; i <= 1000; ++i) 
    printf("%d\n", collatz_calculator(i,0)-1);
}

/*
void divisors(void) {
  for (int i = 0; i <= 100; ++i) {
    int arr[i/2];
    for (int j = 1; j < i/2; ++j) {
    }
  }
}
*/
