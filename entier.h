#ifndef INTEGER_H
#define INTEGER_H

#include "constante.h"
#include "include.h"

class Entier: public Constante
{
    int value;
public:
    Entier(int val):Constante(), value(val){}
    ~Entier(){}

    Constante& GetVal()const;

    int toInt()const;

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

    Constante& operator%(const Constante& c)const;
    Constante& operator!()const;
};

#endif // INTEGER_H
