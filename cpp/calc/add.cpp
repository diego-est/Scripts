#include <iostream>
#include <string>

int main(int argc, const char **argv) {
  if (argc == 3) {
    const long double add1 = std::stold(argv[1]);
    const long double add2 = std::stold(argv[2]);
    std::cout << add1 + add2 << std::endl;
  } else {
    std::cout << "add: Please provide two decimal-number arguments."
              << std::endl;
    return 1;
  }

  return 0;
}
