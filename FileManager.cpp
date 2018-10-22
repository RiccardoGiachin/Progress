//
// Created by giack on 22/10/18.
//

#include "FileManager.h"
#include <iostream>
#include "FileManager.h"
#include "Exception.h"

FileManager::FileManager() : fileLoaded(0), bytesLoaded(0) {

}

FileManager::~FileManager() {

}

void FileManager::loadFiles() {
    int count = 0;
    int totBytes = 0;
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        count++;
        totBytes += (*itr)->getBytes();
    }
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        fileLoaded++;
        std::string name = (*itr)->getFileName();
        int bytesPercentage = (bytesLoaded * 100) / totBytes;
        int filesPercentage = (fileLoaded * 100) / count;
        notify();
    }
}

void FileManager::subscribe(Observer *o) {
    observers.push_back(o);

}

void FileManager::unsubscribe(Observer *o) {
    observers.remove(o);
}

void FileManager::notify(std::string fileName) {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        try {
            (*itr)->update(fileName);
        } catch (NegativeOrNullBytesException &m) {
            std::cout << m.what();
        }
        catch (NegativeOrNullFilesException &n) {
            std::cout << n.what();
        }
    }
}

int FileManager::getFileLoaded() const {
    return fileLoaded;
}

const std::list<Observer *> &FileManager::getObservers() const {
    return observers;
}

void FileManager::storeFiles(ResourceFile *f) throw(NegativeOrNullBytesException) {
    if (f->getBytes() <= 0) {
        throw NegativeOrNullBytesException("Errore nel numero di bytes di alcuni files");
    }
    files.push_back(f);

}

int FileManager::getBytesLoaded() const {
    return bytesLoaded;
}

const std::list<ResourceFile *> &FileManager::getFiles() const {
    return files;
}