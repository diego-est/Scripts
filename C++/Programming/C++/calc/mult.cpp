#include <iostream>
#include <string>

int main(int argc, const char **argv) {
  if (argc == 3) {
    const long double mult1 = std::stold(argv[1]);
    const long double mult2 = std::stold(argv[2]);
    std::cout << mult1 * mult2 << std::endl;
  } else {
    std::cout << "mult: Please provide two decimal-number arguments."
              << std::endl;
    return 1;
  }

  return 0;
}
