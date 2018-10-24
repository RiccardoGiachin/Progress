//
// Created by giack on 22/10/18.
//

#ifndef PROGRESSBAR_FILEMANAGER_H
#define PROGRESSBAR_FILEMANAGER_H


#include "Subject.h"
#include "ResourceFile.h"
#include "Exception.h"
#include <list>
#include <string>


class FileManager : public Subject {
public:
FileManager();

virtual ~FileManager();

void loadFiles();

virtual void subscribe(Observer *o) override;

virtual void unsubscribe(Observer *o) override;

virtual void notify(int bytesPercentage, int filesPercentage, std::string fileName) override;

int getFileLoaded() const;

void storeFiles(ResourceFile *f) throw(NegativeOrNullBytesException);

const std::list<Observer *> &getObservers() const;

int getBytesLoaded() const;

const std::list<ResourceFile *> &getFiles() const;

private:

std::list<Observer *> observers;
int fileLoaded;
int bytesLoaded;
std::list<ResourceFile *> files;
};



#endif //PROGRESSBAR_FILEMANAGER_H
