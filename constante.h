#ifndef CONSTANTE_H
#define CONSTANTE_H

class Constante
{
public:
    Constante(){}
    virtual Constante& GetVal()const = 0;
    virtual Constante& operator+(const Constante& c)const = 0;
    virtual Constante& operator-(const Constante& c)const = 0;
    virtual Constante& operator*(const Constante& c)const = 0;
    virtual Constante& operator/(const Constante& c)const = 0;
    virtual Constante& operator-(int)const = 0;
    virtual Constante& operator^(const Constante& c)const = 0;
    virtual Constante& sinus()const = 0;
    virtual Constante& cosinus()const = 0;
    virtual Constante& tangente()const = 0;
    virtual Constante& sinush()const = 0;
    virtual Constante& cosinush()const = 0;
    virtual Constante& tangenteh()const = 0;
};

#endif // CONSTANTE_H
