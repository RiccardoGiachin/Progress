//
// Created by giack on 20/10/18.
//

#ifndef PROGRESSBAR_EXCEPTION_H
#define PROGRESSBAR_EXCEPTION_H
#include <stdexcept>

class NegativeOrNullBytesException : public std::out_of_range {
public:
    NegativeOrNullBytesException(const std::string &m = "") : out_of_range(m.c_str()) {
    }
};


class NegativeOrNullFilesException : public std::out_of_range {
public:
    NegativeOrNullFilesException(const std::string &n = "") : out_of_range(n.c_str()) {

    }
};
#endif //PROGRESSBAR_EXCEPTION_H
