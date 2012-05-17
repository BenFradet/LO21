#ifndef INTEGER_H
#define INTEGER_H

#include "constante.h"

class Entier: public Constante
{
    int value;
public:
    Entier(int val):Constante(), value(val){}
    ~Entier(){}

    Constante& GetVal()const;
};

#endif // INTEGER_H
