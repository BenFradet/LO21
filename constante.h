#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "calcexception.h"
#include <QString>

class Entier;
class Rationnel;
class Reel;

class Constante
{
public:
    Constante(){}

    virtual Constante& GetVal()const = 0;

    virtual operator int()const = 0;
    virtual operator float()const = 0;
    virtual operator Entier()const = 0;
    virtual operator Rationnel()const = 0;
    virtual operator Reel()const = 0;

    virtual void operator=(const Constante& c);
    virtual Constante& operator+(const Constante& c)const;
    virtual Constante& operator-(const Constante& c)const;
    virtual Constante& operator*(const Constante& c)const;
    virtual Constante& operator/(const Constante& c)const;
    virtual Constante& operator-()const;
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

    virtual QString ToQString() = 0;
};

#endif // CONSTANTE_H
