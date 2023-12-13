/*
 * =====================================================================================
 *
 *       Filename:  nobuild.c
 *
 *    Description: create C code camps 
 *
 *        Version:  1.0
 *        Created:  04/13/2023 05:41:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sunglow
 *   Organization:  NA
 *
 * =====================================================================================
 */
#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define CFLAGS "-Wall", "-Werror", "-Wextra", "-pedantic"

enum arguments{
    build,
    run,
    create
};

int main(int argc, char **argv) {
    GO_REBUILD_URSELF(argc, argv);
    //CMD("./a.out");


    if (argc == 1) {
        //char *error_text = "[ERRO]: the following required arguments were not provided:\n  <command>...\n\nUsage: camp <command>...\n\nFor more information, try '--help'";
        //printf("%s\n", error_text);
      CMD("clang-format", "-i", "main.c");
      CMD("clang", CFLAGS, "main.c", "-o", "camp.out");
    } else {
        char *argument = argv[1];
        if (argument == "run") {
            CMD("./build/debug/a.out");
        } else if (argument == "build") {
          CMD("clang", CFLAGS, "-O3", "main.c", "-o", "build/release/a.out");
        }

        //} else if (argument == "create") {

        //} else {
        //    char *error_text = "";
        //    printf("%s\n");
        //    return 1;
        //}
    }

    return 0;
}
