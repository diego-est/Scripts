#include <iostream>
int main() {
  int f[2] = {0, 1};
  for (int i = 0; i < 31; i++) {
    std::cout << f[0] << "\n";
    f[0] = f[0] + f[1];
    f[1] = f[0] - f[1];
  }
}
