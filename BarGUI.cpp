//
// Created by giack on 22/10/18.
//

#include <iostream>
#include "BarGUI.h"
#include "Exception.h"


BarGUI::BarGUI(FileManager *f) : subject(f), bUpl(0), fUpl(0), currentName("NoFile") {
}

BarGUI::~BarGUI() {
    detach();
}


void BarGUI::draw() {
    //uso la classe derivata per il display...

}

void BarGUI::update(int bUp, int fUp,
                    std::string fileName) throw(NegativeOrNullBytesException, NegativeOrNullFilesException) {
    if (bUp <= 0) {
        throw NegativeOrNullBytesException(
                "Errore impossibile aggiornare bytesUploaded : quantità di bytes nulla o negativa");
    }
    if (fUp <= 0) {
        throw NegativeOrNullFilesException(
                "Errore impossibile aggiornare fileUploaded : quantità files nulla o negativa");
    }
    bUpl = bUp;
    fUpl = fUp;
    currentName = fileName;
    draw();
}

void BarGUI::attach() {
    subject->subscribe(this);
}

void BarGUI::detach() {
    subject->unsubscribe(this);
}

int BarGUI::getBUpl() const {
    return bUpl;
}

void BarGUI::setBUpl(int bUpl) {
    BarGUI::bUpl = bUpl;
}

int BarGUI::getFUpl() const {
    return fUpl;
}

void BarGUI::setFUpl(int fUpl) {
    BarGUI::fUpl = fUpl;
}

void BarGUI::setCurrentName(const std::string &currentName) {
    BarGUI::currentName = currentName;
}

const std::string &BarGUI::getCurrentName() const {
    return currentName;
}






