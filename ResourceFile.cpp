//
// Created by giack on 20/10/18.
//

#include <iostream>
#include "ResourceFile.h"


ResourceFile::ResourceFile(std::string name, int b) : FileName(name), bytes(b) {
}

const std::string &ResourceFile::getFileName() const {
    return FileName;
}


int ResourceFile::getBytes() const {
    return bytes;
}


