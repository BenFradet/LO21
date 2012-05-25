#ifndef REEL_H
#define REEL_H

#include "constante.h"
#include "complexe.h"
#include "rationnel.h"
#include <QString>

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

    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-(int)const;
    Constante& operator^(const Constante& c)const;
    Constante& sinus()const;
    Constante& cosinus()const;
    Constante& tangente()const;
    Constante& sinush()const;
    Constante& cosinush()const;
    Constante& tangenteh()const;
    Constante& logdec()const;
    Constante& lognep()const;
    Constante& inverse()const;
    Constante& racine()const;
    Constante& carree()const;
    Constante& cube()const;

    QString ToQString();
};

#endif // REEL_H
