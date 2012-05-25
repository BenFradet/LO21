#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "calcexception.h"

class Constante
{
public:
    Constante(){}
    virtual Constante& GetVal()const = 0;
    virtual Constante& operator+(const Constante& c)const;
    virtual Constante& operator-(const Constante& c)const;
    virtual Constante& operator*(const Constante& c)const;
    virtual Constante& operator/(const Constante& c)const;
    virtual Constante& operator-(int)const;
    virtual Constante& operator^(const Constante& c)const;
    virtual Constante& sinus()const;
    virtual Constante& cosinus()const;
    virtual Constante& tangente()const;
    virtual Constante& sinush()const;
    virtual Constante& cosinush()const;
    virtual Constante& tangenteh()const;
    virtual Constante& logdec()const;
    virtual Constante& lognep()const;
    virtual Constante& inverse()const;
    virtual Constante& racine()const;
    virtual Constante& carree()const;
    virtual Constante& cube()const;
};

#endif // CONSTANTE_H
