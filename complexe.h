#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "include.h"
#include <QString>

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

    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-(int)const;
    Constante& carree()const;
    Constante& cube()const;

    QString ToQString();
};

#endif // COMPLEXE_H
