//
// Created by giack on 20/10/18.
//

#ifndef PRIMO_DISPLAY_H
#define PRIMO_DISPLAY_H

class Display {
public:
    virtual ~Display() {}

    virtual void draw()=0;
};

#endif //PRIMO_DISPLAY_H
