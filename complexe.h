#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "include.h"

class Complexe: public Constante
{
    Constante& pRe;
    Constante& pIm;
public:
    Complexe(Constante& r, Constante& i): Constante(), pRe(r), pIm(i){}
    ~Complexe(){}

    Constante& GetRe()const{return pRe;}
    Constante& GetIm()const{return pIm;}
    Constante& GetVal()const;

    void SetRe(Constante& r){pRe = r;}
    void SetIm(Constante& i){pIm = i;}

    Constante& operator+(const Constante& c);
    Constante& operator-(const Constante& c);
    Constante& operator*(const Constante& c);
    Constante& operator/(const Constante& c);
};

#endif // COMPLEXE_H
