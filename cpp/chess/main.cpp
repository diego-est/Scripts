/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Chess
 *
 *        Version:  1.0
 *        Created:  02/19/2023 12:39:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <ncurses.h>
#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>

class Piece {
 public:
  int color;
  char icon;
};

int current = -1;
int parity() {
  current++;
  return 1 + (current % 2);
}

int main() {
  initscr();
  curs_set(0);

  std::pair<int, int> screenMax;
  getmaxyx(stdscr, screenMax.first, screenMax.second);

  int tableSize = 10;
  WINDOW *win = newwin(tableSize, tableSize,
                       fma(tableSize >> 1, -1, screenMax.first >> 1),
                       fma(tableSize >> 1, -1, screenMax.second >> 1));

  if (has_colors() == false) {
    delwin(win);
    endwin();
    std::cout << "Your terminal does not support colors.\n";
    exit(1);
  }
  refresh();

  enum Color { WHITE_PAIR = 1, BLACK_PAIR };

  start_color();
  init_pair(WHITE_PAIR, COLOR_WHITE, COLOR_BLACK);
  init_pair(BLACK_PAIR, COLOR_BLACK, COLOR_WHITE);

  attron(COLOR_PAIR(WHITE_PAIR));
  box(win, 0, 0);
  attroff(COLOR_PAIR(WHITE_PAIR));
  wrefresh(win);

  int myArray[tableSize - 2];
  std::generate_n(myArray, tableSize - 2, parity);
  for (int column = 1; column < tableSize - 1; column++) {
    for (int row = 1; row < tableSize - 1; row++) {
      wattron(win, COLOR_PAIR(myArray[row]));
      mvwprintw(win, row, column, ".");
      wattroff(win, COLOR_PAIR(myArray[row]));
    }
    std::rotate(myArray, myArray + tableSize - 2, myArray + tableSize - 1);
    std::cout << "\n";
  }
  wrefresh(win);
  getch();
}
