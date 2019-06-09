//
// Created by giack on 20/10/18.
//


#include "ResourceFile.h"
#include <iostream>



ResourceFile::ResourceFile(std::string name, int b) : fileName(name), bit(b) {
}

const std::string &ResourceFile::getFileName() const {
    return fileName;
}

int ResourceFile::getBit() const {
    return bit;
}