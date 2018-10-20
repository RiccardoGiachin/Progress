//
// Created by giack on 20/10/18.
//

#ifndef PROGRESSBAR_DISPLAY_H
#define PROGRESSBAR_DISPLAY_H
class Display {
public:
    virtual ~Display() {}

    virtual void draw()=0;
};
#endif //PROGRESSBAR_DISPLAY_H
