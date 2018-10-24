//
// Created by giack on 22/10/18.
//

#include "ProgressBarDisplay.h"
#include <ncurses.h>
#include <string>
#include "ProgressBarDisplay.h"


ProgressBarDisplay::ProgressBarDisplay(FileManager *s) : BarGUI::BarGUI(s) {
    //initializing the loading window...
    initscr();
    curs_set(0);
    noecho();
    progressbar = newwin(8, 112, 15, 20);

    setBUpl(0);
    setFUpl(0);
    setCurrentName("NoFile");

};

ProgressBarDisplay::~ProgressBarDisplay() {
    detach();
}

void ProgressBarDisplay::draw() {

    box(progressbar, ACS_VLINE, ACS_DIAMOND);
    mvwprintw(progressbar, 1, 3, "Waiting....");

    //simulating a waiting queue from the desktop.

    wtimeout(progressbar, 500);
    wattron(progressbar, A_STANDOUT);
    if (BarGUI::getBUpl() < 101) {
        for (int i = 0; i < BarGUI::getBUpl(); i++) {
            mvwprintw(progressbar, 3, i + 6, "", 97);
            waddch(progressbar, 97 | A_ALTCHARSET);
        }

        wattroff(progressbar, A_STANDOUT);
        mvwprintw(progressbar, 5, 6, "Bytes percentage %d %%", BarGUI::getBUpl());
        mvwprintw(progressbar, 6, 6, "File percentage  %d %%", BarGUI::getFUpl());

        // displaying the files here:

        mvwprintw(progressbar, 5, 80, "Current File: %s", BarGUI::getCurrentName().c_str());
        wrefresh(progressbar);
        wgetch(progressbar);

    }
    refresh();

    if (BarGUI::getBUpl() == 100) {
        mvwprintw(progressbar, 6, 40, "LOADING COMPLETE!!!");
        mvprintw(25, 57, "Press any key to continue");
        wrefresh(progressbar);
        getch();
        endwin();
    }


}