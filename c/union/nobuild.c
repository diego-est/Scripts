/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#define NOBUILD_IMPLEMENTATION
#include <nobuild/nobuild.h>
#include <string.h>
#define CFLAGS "-Wall", "-Werror", "-Wextra", "-pedantic"

int main(int argc, char** argv) {
  GO_REBUILD_URSELF(argc, argv);

  if (argc == 1) {
    CMD("clang-format", "-i", "src/main.c");
    CMD("clang", CFLAGS, "-Og", "-ggdb", "src/main.c", "-o", "build/debug/a.out");
  } else {
      char *argument = argv[1];
      if (strcmp(argument, "run") == 0) {
        CMD("clang-format", "-i", "src/main.c");
        CMD("clang", CFLAGS, "-Og", "-ggdb", "src/main.c", "-o", "build/debug/a.out");
        CMD("./build/debug/a.out");
      } else if (strcmp(argument, "build") == 0) {
        CMD("clang", CFLAGS, "-O3", "src/main.c", "-o", "build/release/a.out");
      }
  }

  return 0;
}
