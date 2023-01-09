#include <iostream>
#include <ncurses.h>
#include <string>

int main(int argc, char** argv)
{
    initscr();
    noecho();
    cbreak();

    // get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create a window for menu
    WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    // allows the use of arrow keys
    keypad(menuwin, true);

    std::string choices[3] = {"Walk", "Jog", "Run"};
    int arrlen = sizeof(choices) / sizeof(choices[0]);
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        int choice = wgetch(menuwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = arrlen-1;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == arrlen)
                    highlight = 0;
                break;
            default:
                break;
        }
    if(choice == 10)
        break;
    }

    printw("Your choice was: %s", choices[highlight].c_str());

    getch();
    endwin();

    return 0;
}
