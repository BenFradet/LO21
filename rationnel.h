#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "include.h"
#include <QString>
#include <QStringList>

class Entier;
class Reel;

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

    Rationnel(QString s)        // crée un rationnel a partir d'un QString
    {
        QStringList liste = s.split("/");

        if (liste[1].toInt() != 0)

        {

        num = liste[0].toInt();
        den = liste[1].toInt();
        }
        else
            throw CalcException("Le dénominateur ne peut pas valoir zéro");

    }

    int GetDen()const{return den;}
    int GetNum()const{return num;}
    Constante& GetVal()const;
    void SetDen(int d){den = d;}
    void SetNum(int n){num = n;}

    operator int()const;
    operator float()const;
    operator Entier()const;
    operator Rationnel()const;
    operator Reel()const;

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

    QString ToQString();  //  crée un QString à partir d'un rationnel
};

#endif // RATIONNEL_H
