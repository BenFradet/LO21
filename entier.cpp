#include "entier.h"

Constante& Entier::GetVal()const
{
    Entier e(value);
    return e;
}

int Entier::toInt()const
{
    return value;
}

Constante& Entier::operator+(const Constante& c)
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value+e->toInt());
        return res;
    }
    else;//erreur
}

Constante& Entier::operator-(const Constante& c)
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value-e->toInt());
        return res;
    }
    else;//erreur
}

Constante& Entier::operator*(const Constante& c)
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value*e->toInt());
        return res;
    }
    else;//erreur
}

Constante& Entier::operator/(const Constante& c)
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value/e->toInt());
        return res;
    }
    else;//erreur
}




