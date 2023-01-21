#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char **argv) {
  srand(time(NULL));
  int lineNumber = 0;
  unsigned long long count = 0;
  std::string line;

  //if (argc == 2) {
  //  count = atoi(argv[1]);
  //}

  char randomNumber[5];
  std::string entry = "";
  do {
    entry = "";
    randomNumber[0] = rand() % 10 + 48;
    randomNumber[1] = rand() % 10 + 48;
    randomNumber[2] = rand() % 10 + 48;
    randomNumber[3] = rand() % 10 + 48;
    randomNumber[4] = rand() % 10 + 48;
    //int digits = atoi(randomNumber);

    std::ifstream adjectives("adjectives.txt");
    int adjectivesLineCount =
        std::count(std::istreambuf_iterator<char>(adjectives),
                   std::istreambuf_iterator<char>(), '\n');
    adjectives.seekg(0);
    int adjectivesRandom = rand() % adjectivesLineCount;

    while (std::getline(adjectives, line)) {
      if (lineNumber == adjectivesRandom) {
        //std::cout << line;
        entry = line;
        lineNumber = 0;
        break;
      }
      lineNumber++;
    }

    std::ifstream nouns("nouns.txt");
    int nounsLineCount =
        std::count(std::istreambuf_iterator<char>(nouns),
                   std::istreambuf_iterator<char>(), '\n');
    nouns.seekg(0);
    int nounsRandom = rand() % nounsLineCount;

    while (std::getline(nouns, line)) {
      if (lineNumber == nounsRandom) {
        //std::cout << line;
        entry = entry + line;
        lineNumber = 0;
        break;
      }
      lineNumber++;
    }
    entry = entry + randomNumber;
    //std::cout << digits << "\n";
    std::cout << count << ": " << entry << "\n";
    count++;
    //entry = "ShrubbyBus69007";
  }while(entry != "ShrubbyBus69007" );
  std::cout << entry << " found after " << count << " entries." << std::endl;
  return 0;
}
