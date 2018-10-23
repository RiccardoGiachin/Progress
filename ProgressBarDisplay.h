//
// Created by giack on 22/10/18.
//

#ifndef PROGRESSBAR_PROGRESSBARDISPLAY_H
#define PROGRESSBAR_PROGRESSBARDISPLAY_H
#include <list>
#include "BarGUI.h"
#include "FileManager.h"
#include "ResourceFile.h"

class ProgressBarDisplay : public BarGUI, public Display {
public:
    virtual ~ProgressBarDisplay();

    ProgressBarDisplay(FileManager *s);

    virtual void draw() override;


private:
    WINDOW *progressbar;
};


#endif //PROGRESSBAR_PROGRESSBARDISPLAY_H
