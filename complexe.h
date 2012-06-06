#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "include.h"
#include "constantefactory.h"
#include <QString>
#include <QStringList>

class Complexe: public Constante
{
    Constante* pRe;
    Constante* pIm;
public:
    Complexe(Constante* r, Constante* i): Constante(), pRe(r), pIm(i){}
    ~Complexe(){}

    Complexe(QString &s, QString mode);

    Constante* GetRe()const{return pRe;}
    Constante* GetIm()const{return pIm;}
    Constante& GetVal()const;

    operator int()const;
    operator float()const;
    operator Entier()const;
    operator Rationnel()const;
    operator Reel()const;
    operator Complexe()const;

    void SetRe(Constante* r){pRe = r;}
    void SetIm(Constante* i){pIm = i;}

    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-()const;
    Constante& carree()const;
    Constante& cube()const;

    QString ToQString(); // crée un QString à partir d'un complexe
};

#endif // COMPLEXE_H
