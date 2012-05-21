#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "complexe.h"

class Rationnel : public Constante
{
    int num;
    int den;
public:
    Rationnel(int n, int d):Constante(), num(n), den(d){}
    ~Rationnel(){}

    int GetDen()const{return den;}
    int GetNum()const{return num;}
    Constante& GetVal()const;
    void SetDen(int d){den = d;}
    void SetNum(int n){num = n;}

    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-(int)const;
    Constante& operator^(const Constante& c)const;
    Constante& sinus()const;
    Constante& cosinus()const;
    Constante& tangente()const;
};

#endif // RATIONNEL_H
