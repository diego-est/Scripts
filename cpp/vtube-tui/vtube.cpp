#include <iostream>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <vector>
#include <map>
#include <tuple>

#define ACTIVE_WINDOW   1
#define INACTIVE_WINDOW 2
#define OPEN_WINDOW     3
namespace fs = std::filesystem;

fs::path tempXml    = "/tmp/tmp.xml";
fs::path config     = "/home/void/.config/vtube-cli/urls";
fs::path xmlDir     = "/home/void/.cache/vtube-cli";
fs::path vtDir      = "/home/void/.cache/vtube-cli";
fs::path urlFile    = "/home/void/.cache/vtube-cli/urls";
fs::path searchFile = "/home/void/.cache/vtube-cli/search";
fs::path confg      = "/home/void/Scripts/c/vtube-tui/conf.yaml";

/* help window stuff */

void updateWindow(WINDOW* update, std::map<WINDOW*, std::string>& name)
{
box(update, 0, 0);
mvwprintw(update, 0, 1, name[update].c_str());
wrefresh(update);
}

int main(int argc, char** argv)
{
    initscr();
    noecho();
    cbreak();
    if(!has_colors())
    {
        endwin;
        std::cout << "Your terminal does not support color.\n";
        exit(1);
    } else
    {
        start_color();
    }
    init_pair(ACTIVE_WINDOW, COLOR_CYAN, COLOR_BLACK);
    init_pair(INACTIVE_WINDOW, COLOR_WHITE, COLOR_BLACK);
    init_pair(OPEN_WINDOW, COLOR_YELLOW, COLOR_BLACK);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int ySearch, xSearch, yHelp, xHelp, yLibrary, xLibrary, yChannels, xChannels, yMenu, xMenu, yPlayer, xPlayer;
    ySearch     = 3;
    xSearch     = xMax - 12;
    yHelp       = 3;
    xHelp       = xMax - xSearch - 1;
    yMenu       = yMax - 8;
    xMenu       = (xMax * 2) / 3;
    yLibrary    = yMenu / 3;
    xLibrary    = xMax / 3;
    yChannels   = ((yMenu * 2) / 3) + 1;
    xChannels   = xMax / 3;
    yPlayer     = 5;
    xPlayer     = xMax;

    WINDOW * search     = newwin(ySearch,   xSearch,    0, 0);
    WINDOW * help       = newwin(yHelp,     xHelp,      0, xSearch);
    WINDOW * library    = newwin(yLibrary,  xLibrary,   ySearch, 0);
    WINDOW * channels   = newwin(yChannels, xChannels,  yLibrary + 3, 0);
    WINDOW * menu       = newwin(yMenu,     xMenu,      ySearch, xLibrary);
    WINDOW * player     = newwin(yPlayer,   xPlayer,    yMax-5, 0);

    keypad(search,   TRUE);
    keypad(library,  TRUE);
    keypad(channels, TRUE);
    keypad(player,   TRUE);
    keypad(menu,     TRUE);

    std::map<WINDOW*, std::string> windowName;
    windowName[search]      = "Search";
    windowName[library]     = "Library";
    windowName[channels]    = "Channels";
    windowName[menu]        = "Menu";
    windowName[player]      = "Player";
    windowName[help]        = "Help";

    mvwprintw(help, 1, 1, "Type ?");

    wattron(menu, COLOR_PAIR(ACTIVE_WINDOW));
    wmove(menu, 1, 1);

    int screensIndex, parity, mode;
    mode = 1;
    std::vector<WINDOW*> screens[4];
    screens[0].push_back(search);
    screens[0].push_back(menu);
    screens[1].push_back(library);
    screens[1].push_back(menu);
    screens[2].push_back(channels);
    screens[2].push_back(menu);
    screens[3].push_back(player);
    screens[3].push_back(menu);
    parity = 1;
    screensIndex = 2;
    auto currentScreen = screens[screensIndex].begin();
    currentScreen = next(currentScreen, parity);

    for(auto const& [key, val] : windowName)
        updateWindow(key, windowName);
    refresh();

    while(1)
    {

    YAML::Node userConfig = YAML::LoadFile(confg.string());
    YAML::Node dataNode = userConfig["vtubers"];
    
    {
    int count = 1;
    for(YAML::const_iterator it = dataNode.begin();
            (it != dataNode.end()) && (count < yLibrary - 1); ++it, count++)
    {
        std::string name = it->first.as<std::string>();
        name.resize(xLibrary -2);
        mvwprintw(library, count, 1, name.c_str());
    }
    }
    
    {
    int count = 1;
    for(YAML::const_iterator it = dataNode.begin();
            (it != dataNode.end()) && (count < yChannels); ++it, count++)
    {
        YAML::Node node = it->first;
        std::string name = dataNode[node]["url"].as<std::string>();
        name.resize(xChannels - 2);
        mvwprintw(channels, count, 1, name.c_str());
    }
    }

    for(auto const& [key, val] : windowName)
        updateWindow(key, windowName);
    refresh();

        int choice = wgetch(*currentScreen);

        if(mode == 1)
        {
            //hover mode
            switch(choice)
            {
                case KEY_UP:
                    wattroff    (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);

                    screensIndex--;
                    if(screensIndex == -1)
                        screensIndex = 0;
                    currentScreen = screens[screensIndex].begin();

                    wattron     (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);
                    break;

                case KEY_DOWN:
                    wattroff    (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);

                    screensIndex++;
                    if(screensIndex == 4)
                        screensIndex = 3;
                    currentScreen = screens[screensIndex].begin();

                    wattron     (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);
                    break;

                case KEY_LEFT:
                    wattroff    (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);

                    currentScreen = screens[screensIndex].begin();

                    wattron     (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);
                    break;

                case KEY_RIGHT:
                    wattroff    (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);

                    currentScreen = prev(screens[screensIndex].end(), 1);

                    wattron     (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
                    updateWindow(*currentScreen, windowName);
                    wrefresh    (*currentScreen);
                    break;

                case 10:
                    mode = 2;
                    break;

                case 113:
                    exit(0);
                    break;

                default:
                    break;
            }
        }
        else if(mode == 2)
        {
            wattroff    (*currentScreen, COLOR_PAIR(ACTIVE_WINDOW));
            wattron     (*currentScreen, COLOR_PAIR(OPEN_WINDOW));
            updateWindow(*currentScreen, windowName);
            wrefresh    (*currentScreen);
            refresh();
            // panel mode
            switch(choice)
            {
                case 27: // ESC
                    mode = 1;
                    break;
                case 113: // q
                    mode = 1;
                    break;
                case KEY_UP:
                    break;
                default:
                    break;

            }
        }
        
    }

    return 0;
}
