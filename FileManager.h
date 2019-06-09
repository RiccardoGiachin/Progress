//
// Created by giack on 22/10/18.
//

#ifndef PRIMO_FILEMANAGER_H
#define PRIMO_FILEMANAGER_H


#include "Subject.h"
#include "ResourceFile.h"
#include <list>
#include <string>

class FileManager : public Subject {
public:
    FileManager();

    virtual ~FileManager();

    void caricaFiles();

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify(int bitPercentuale, int filesPercentuale, std::string fileName, int bitAttuale) override;

    int getFileCaricati() const;

    const std::list<Observer *> &getObservers() const;

    const std::list<ResourceFile *> &getFiles() const;

    int getBitCaricati() const;

    void storeRisorse(ResourceFile *f);

private:

    std::list<Observer *> observers;
    std::list<ResourceFile *> files;
    int fileCaricati;
    int bitCaricati;

};


#endif //PRIMO_FILEMANAGER_H
