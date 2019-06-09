//
// Created by giack on 20/10/18.
//

#ifndef PROGRESSBAR_RESOURCEFILE_H
#define PROGRESSBAR_RESOURCEFILE_H

#include <string>

class ResourceFile {
public:
    ResourceFile(std::string name, int b);

    const std::string &getFileName() const;

    int getBit() const;

private:
    std::string fileName;
    int bit;

};


#endif //PROGRESSBAR_RESOURCEFILE_H
