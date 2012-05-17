#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "rationnel.h"

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
};

#endif // COMPLEXE_H
