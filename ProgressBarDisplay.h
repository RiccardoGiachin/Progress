//
// Created by giack on 22/10/18.
//

#ifndef PROGRESSBAR_GUIPROGRESSBAR_H
#define PROGRESSBAR_GUIPROGRESSBAR_H

#include <list>
#include "BarGUI.h"
#include "FileManager.h"
#include "ResourceFile.h"

class GUIProgressBar : public BarGUI, public Display {
public:
    virtual ~GUIProgressBar();

    GUIProgressBar(FileManager *s);

    virtual void draw() override;


private:
    WINDOW *progressbar;
};


#endif //PROGRESSBAR_GUIPROGRESSBAR_H
