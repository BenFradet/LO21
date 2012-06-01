#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "include.h"
#include <QString>
#include <QStringList>

class Complexe: public Constante
{
    Constante& pRe;
    Constante& pIm;
public:
    Complexe(Constante& r, Constante& i): Constante(), pRe(r), pIm(i){}
    ~Complexe(){}

/*    Complexe(QString &s)  // crée un rationnel a partir d'un QString (a voir plus compliqué)
    {
        QStringList liste = s.split("$");
        pRe = Entier(liste[0].toInt());
        pIm = Entier(liste[1].toInt());
    }*/

    Constante& GetRe()const{return pRe;}
    Constante& GetIm()const{return pIm;}
    Constante& GetVal()const;

    void SetRe(Constante& r){pRe = r;}
    void SetIm(Constante& i){pIm = i;}

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
