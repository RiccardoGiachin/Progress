//
// Created by giack on 20/10/18.
//

#ifndef PRIMO_SUBJECT_H
#define PRIMO_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o)=0;

    virtual void unsubscribe(Observer *o)=0;

    virtual void notify(int bitPercentuale, int filesPercentuale, std::string fileName, int bitAttuale)=0;

};

#endif //PRIMO_SUBJECT_H
