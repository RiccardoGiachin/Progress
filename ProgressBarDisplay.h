//
// Created by giack on 22/10/18.
//

#ifndef PROGRESSBAR_GUIPROGRESSBAR_H
#define PROGRESSBAR_GUIPROGRESSBAR_H


#include <list>
#include <ncurses.h>
#include "BarGUI.h"
#include "Display.h"
#include "FileManager.h"
#include "ResourceFile.h"

class ProgressBarDisplay : public BarGUI, public Display {
public:
    virtual ~ProgressBarDisplay();

    ProgressBarDisplay(FileManager *s);

    virtual void disegna() override;

private:

    WINDOW *progressbar;
    WINDOW *progressbarOut;
    WINDOW *progressbarRisorse;

};



#endif //PROGRESSBAR_GUIPROGRESSBAR_H
