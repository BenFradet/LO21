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
};

#endif // CONSTANTE_H
