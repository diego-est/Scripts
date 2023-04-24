#include <iostream>

int count(const int *first, const int *last, int value) {
  int ret = 0;
  for (; first != last; ++first)
    if (*first == value) ret++;
  return ret;
}

int main(void) {
  int a[] = {1, 3, 3, 5, 7, 0};
  int b[] = {3, 6, 7, 9};

  size_t a_size = sizeof(a) / sizeof(int);
  size_t b_size = sizeof(b) / sizeof(int);
  size_t out_size = a_size + b_size;
  int *out[out_size];

  int **out_beg = out;
  int **out_end = out + out_size;

  int *a_beg = a;
  int *a_end = a + a_size;
  int *b_beg = b;
  int *b_end = b + b_size;

  for (int index = 0; a_beg != a_end; ++a_beg, index++) {
    int repeats = count(*out_beg, *out_end, *a_beg);
    out[index] = repeats == 0 ? &a[index] : NULL;
  }

  for (int index = 0; b_beg != b_end; ++b_beg, index++) {
    int repeats = count(*out_beg, *out_end, *b_beg);
    out[index + a_size] = repeats == 0 ? &b[index] : NULL;
  }

  for (size_t i = 0; i < out_size; ++i)
    if (out[i] != NULL) std::cout << *out[i] << std::endl;

  return 0;
}
