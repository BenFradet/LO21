#ifndef REEL_H
#define REEL_H

#include "constante.h"
#include "complexe.h"
#include "rationnel.h"

class Reel: public Constante
{
    //int ent;
    //int dec;
    float value;
public:
    Reel(float val):Constante(), value(val){}
    ~Reel(){}

    Constante& GetVal()const;
    float toFloat()const;

    Constante& operator+(const Constante& c);
    Constante& operator-(const Constante& c);
    Constante& operator*(const Constante& c);
    Constante& operator/(const Constante& c);
};

#endif // REEL_H
