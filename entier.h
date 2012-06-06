#ifndef INTEGER_H
#define INTEGER_H

#include "include.h"

class Reel;
class Rationnel;

class Entier: public Constante
{
    int value;
public:
    Entier(int val):Constante(), value(val){}
    ~Entier(){}

    Entier(QString s) // crée un entier a partir d'un QString
    {
        value = s.toInt();
    }

    Constante& GetVal()const;

    operator int()const;
    operator float()const;
    operator Reel()const;
    operator Rationnel()const;
    operator Entier()const;
    operator Complexe()const;

    void operator=(const Constante& c);
    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-()const;
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

    operator QString();  // crée un QString à partir d'un entier

    Constante& operator%(const Constante& c)const;
    Constante& operator!()const;
};

#endif // INTEGER_H
