#ifndef REEL_H
#define REEL_H

#include "include.h"
#include <QString>

class Entier;
class Rationnel;

class Reel: public Constante
{
    //int ent;
    //int dec;
    float value;
public:
    Reel(float val):Constante(), value(val){}
    ~Reel(){}

    Reel(QString s)  // crée un rationnel a partir d'un QString
    {
       value = s.toFloat();
    }

    Constante& GetVal()const;

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

    QString ToQString(); // crée QString à partir d'un réel
};

#endif // REEL_H
