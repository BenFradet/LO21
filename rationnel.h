#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "complexe.h"
#include <QString>

class Rationnel : public Constante
{
    int num;
    int den;
public:
    Rationnel(int n, int d): Constante()
    {
        if(d!=0)
        {
            num = n;
            den = d;
        }
        else
            throw CalcException("Le dénominateur ne peut pas valoir zéro");
    }

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

    QString ToQString();
};

#endif // RATIONNEL_H
