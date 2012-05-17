#ifndef REEL_H
#define REEL_H

#include "constante.h"

class Reel: public Constante
{
    //int ent;
    //int dec;
    float value;
public:
    Reel(float val):Constante(), value(val){}
    ~Reel(){}

    Constante& GetVal()const;
};

#endif // REEL_H
