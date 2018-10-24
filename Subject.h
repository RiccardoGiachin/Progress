//
// Created by giack on 20/10/18.
//

#ifndef PROGRESSBAR_SUBJECT_H
#define PROGRESSBAR_SUBJECT_H
#include "Observer.h"
#include <string>
class Subject {
public:
    virtual void subscribe(Observer *o)=0;

    virtual void unsubscribe(Observer *o)=0;

    virtual void notify(int bytesPercentage, int filesPercentage, std::string fileName)=0;
};
#endif //PROGRESSBAR_SUBJECT_H
