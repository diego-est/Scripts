/* ========================================================================
 *
 *     Filename:  union
 *  Description:  finds the unions of two arrays
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <stdio.h>
#include <stdlib.h>

int count(int *, int *, int);

int main(void) {
  int a[] = {1, 3, 3, 5, 7, 0};
  int b[] = {3, 6, 7, 9};

  size_t a_size = sizeof(a) / sizeof(int);
  size_t b_size = sizeof(b) / sizeof(int);
  size_t out_size = a_size + b_size;
  int *out[out_size];

  int *a_beg = a;
  int *a_end = a + a_size;
  int *b_beg = b;
  int *b_end = b + b_size;

  for (int index = 0; a_beg != a_end; ++a_beg, index++) {
    int repeats = count(a, a_beg + 1, *a_beg);
    out[index] = repeats <= 1 ? &a[index] : NULL;
  }

  for (int index = 0; b_beg != b_end; ++b_beg, index++) {
    int repeats = count(a, a_end, *b_beg) + count(b, b_beg + 1, *b_beg);
    out[index + a_size] = repeats <= 1 ? &b[index] : NULL;
  }

  for (size_t i = 0; i < out_size; ++i)
    if (out[i] != NULL)
      printf("%d\n", *out[i]);

  return 0;
}

int count(int *first, int *last, int value) {
  int ret = 0;
  for (; first != last; ++first) {
    printf("Is %d == %d?\n", *first, value);
    if (*first == value) {
      ret++;
    }
  }
  printf("\t%d\n", ret);

  return ret;
}
