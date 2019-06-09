//
// Created by giack on 22/10/18.
//

#include "FileManager.h"
#include "ResourceFile.h"
#include <iostream>

FileManager::FileManager() : fileCaricati(0), bitCaricati(0) {

}

FileManager::~FileManager() {

}

void FileManager::caricaFiles() {
    int count = 0;
    int totBit = 0;
    int bitAttuale = 0;
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        count++;
        totBit += (*itr)->getBit();
    }
    for (auto itr = std::begin(files); itr != std::end(files); itr++) {
        bitCaricati += (*itr)->getBit();
        bitAttuale = (*itr)->getBit();
        fileCaricati++;
        std::string name = (*itr)->getFileName();
        int bitPercentuale = (bitCaricati * 100) / totBit;
        int filesPercentuale = (fileCaricati * 100) / count;
        notify(bitPercentuale, filesPercentuale, name, bitAttuale);
    }
}

void FileManager::subscribe(Observer *o) {
    observers.push_back(o);
}

void FileManager::unsubscribe(Observer *o) {
    observers.remove(o);
}

void FileManager::notify(int bitPercentuale, int filesPercentuale, std::string fileName, int bitAttuale) {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update(bitPercentuale, filesPercentuale, fileName, bitAttuale);
    }
}

int FileManager::getFileCaricati() const {
    return fileCaricati;
}

const std::list<Observer *> &FileManager::getObservers() const {
    return observers;
}

const std::list<ResourceFile *> &FileManager::getFiles() const {
    return files;
}

int FileManager::getBitCaricati() const {
    return bitCaricati;
}

void FileManager::storeRisorse(ResourceFile *f) {
    files.push_back(f);
}