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

    Constante& operator+(const Constante& c);
    Constante& operator-(const Constante& c);
    Constante& operator*(const Constante& c);
    Constante& operator/(const Constante& c);
};

#endif // INTEGER_H
