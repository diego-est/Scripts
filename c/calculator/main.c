#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc == 3) {
    const long double result = atof(argv[1]) / atof(argv[2]);
    printf("%Lf", result);
  }

  return 0;
}
