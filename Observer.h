//
// Created by giack on 20/10/18.
//

#ifndef PROGRESSBAR_OBSERVER_H
#define PROGRESSBAR_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update()=0;

    virtual void attach()=0;

    virtual void detach()=0;

};

#endif //PROGRESSBAR_OBSERVER_H
