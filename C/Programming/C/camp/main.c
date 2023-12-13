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
#include <mystuff/macros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void camp_create(char *);

int main(int argc, char **argv) {

  if (argc == 1) {
    char *error_text = "[ERRO]: the following required arguments were not "
                       "provided:\n  <command>...\n\nUsage: camp "
                       "<command>...\n\nFor more information, try '--help'";
    printf("%s\n", error_text);
    return 1;
  } else {
    char *argument = argv[1];
    if (!strcmp(argument, "run")) {
      // TODO ("search and run binary.");
    } else if (!strcmp(argument, "build")) {
      // TODO ("compile binary.");

    } else if (!strcmp(argument, "create")) {
      if (argc == 3) {
        camp_create(argv[2]);
      }
    } else {

      char *error_text = "";
      printf("%s\n", error_text);
      return 1;
    }
  }

  return 0;
}

void camp_create(char *camp_name) {
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

  // clang-format off
  const char *heading = "/* ========================================================================\n"
                        " *\n"
                        " *     Filename:  \n"
                        " *  Description:  \n"
                        " *      Version:  0.0.1\n"
                        " *\n"
                        " * ======================================================================== */\n";

  const char *main_text = "#include <stdlib.h>\n"
                          "#include <stdio.h>\n"
                          "\n"
                          "int main(void) {\n"
                          "  printf(\"Hello, world!\\n\");\n"
                          "  return 0;\n"
                          "}\n";

  const char *nobuild_text =
      "#define NOBUILD_IMPLEMENTATION\n"
      "#include <nobuild/nobuild.h>\n"
      "#include <string.h>"
      "\n"
      "#define CFLAGS \"-Wall\", \"-Werror\", \"-Wextra\", \"-pedantic\"\n"
      "\n"
      "int main(int argc, char** argv) {\n"
      "  GO_REBUILD_URSELF(argc, argv);\n"
      "\n"
      "  if (argc == 1) {\n"
      "    CMD(\"clang-format\", \"-i\", \"src/main.c\");\n"
      "    CMD(\"clang\", CFLAGS, \"-Og\", \"-ggdb\", \"src/main.c\", \"-o\", \"build/debug/a.out\");\n"
      "  } else {\n"
      "      char *argument = argv[1];\n"
      "      if (strcmp(argument, \"run\") == 0) {\n"
      "        CMD(\"./build/debug/a.out\");\n"
      "      } else if (strcmp(argument, \"build\") == 0) {\n"
      "        CMD(\"clang\", CFLAGS, \"-O3\", \"src/main.c\", \"-o\", \"build/release/a.out\");\n"
      "      }\n"
      "  }\n"
      "\n"
      "  return 0;\n"
      "}\n";
  // clang-format on

  const char *gitignore_text = "/build";

  struct stat st = {0};
  if (stat(camp_name, &st) == -1) {
    mkdir(camp_name, 0700);
    // INFO("Succesfully created camp:");
    printf("\t%s\n", camp_name);
  }

  char *_main = "/main.c";
  char *nobuild = "/nobuild.c";
  char *gitignore = "/.gitignore";
  char *src = "/src";
  char *build = "/build";
  char *debug = "/debug";
  char *release = "/release";
  char *camp_nobuild;
  char *camp_gitignore;
  char *camp_src;
  char *camp_src_main;
  char *camp_build;
  char *camp_build_debug;
  char *camp_build_release;
  size_t name_len = strlen(camp_name);
  camp_nobuild = malloc(name_len + 1 + 10);
  camp_gitignore = malloc(name_len + 1 + 11);
  camp_src = malloc(name_len + 1 + 4);
  camp_src_main = malloc(name_len + 1 + 7);
  camp_build = malloc(name_len + 1 + 7);
  camp_build_debug = malloc(strlen(camp_name) + 1 + 5 + 5);
  camp_build_release = malloc(strlen(camp_name) + 1 + 5 + 7);

  strcpy(camp_nobuild, camp_name);
  strcat(camp_nobuild, nobuild);
  strcpy(camp_gitignore, camp_name);
  strcat(camp_gitignore, gitignore);
  strcpy(camp_src, camp_name);
  strcat(camp_src, src);
  strcpy(camp_build, camp_name);
  strcat(camp_build, build);

  strcpy(camp_src_main, camp_src);
  strcat(camp_src_main, _main);

  strcpy(camp_build_debug, camp_build);
  strcat(camp_build_debug, debug);

  strcpy(camp_build_release, camp_build);
  strcat(camp_build_release, release);

  mkdir(camp_src, 0700);
  mkdir(camp_build, 0700);
  mkdir(camp_build_debug, 0700);
  mkdir(camp_build_release, 0700);
  // INFO("Succesfully created service directories . . .");

  FILE *fmain;
  fmain = fopen(camp_src_main, "w+");
  fprintf(fmain, "%s", heading);
  fprintf(fmain, "%s", main_text);
  fclose(fmain);

  FILE *fnobuild;
  fnobuild = fopen(camp_nobuild, "w+");
  fprintf(fnobuild, "%s", heading);
  fprintf(fnobuild, "%s", nobuild_text);
  fclose(fnobuild);

  FILE *fgitignore;
  fgitignore = fopen(camp_gitignore, "w+");
  fprintf(fnobuild, "%s", gitignore_text);
  fclose(fgitignore);
  // INFO("Succesfully initialized program files . . .");

  free(camp_nobuild);
  free(camp_gitignore);
  free(camp_src);
  free(camp_src_main);
  free(camp_build);
  free(camp_build_release);
  free(camp_build_debug);

  // INFO("Done!");
}
