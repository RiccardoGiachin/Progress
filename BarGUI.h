//
// Created by giack on 22/10/18.
//

#ifndef PRIMO_GUIBAR_H
#define PRIMO_GUIBAR_H

#include <string.h>
#include <ncurses.h>
#include "Observer.h"
#include "Display.h"
#include "FileManager.h"
#include "Exception.h"


class BarGUI : public Observer {
public:

    BarGUI(FileManager *f);

    virtual ~BarGUI();

    virtual void draw();

    virtual void update(int bUp, int fUp, std::string fileName)
    throw(NegativeOrNullBytesException, NegativeOrNullFilesException) override;

    virtual void attach() override;

    virtual void detach() override;

    int getBUpl() const;

    void setBUpl(int bUpl);

    int getFUpl() const;

    void setFUpl(int fUpl);

    void setCurrentName(const std::string &currentName);

    const std::string &getCurrentName() const;

private:
    int bUpl, fUpl;
    std::string currentName;
    FileManager *subject;
};


#endif //PRIMO_GUIBAR_H
