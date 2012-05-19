#ifndef CONSTANTE_H
#define CONSTANTE_H

class Constante
{
public:
    Constante(){}
    virtual Constante& GetVal()const = 0;
    virtual Constante& operator+(const Constante& c) = 0;
    virtual Constante& operator-(const Constante& c) = 0;
    virtual Constante& operator*(const Constante& c) = 0;
    virtual Constante& operator/(const Constante& c) = 0;
};

#endif // CONSTANTE_H
