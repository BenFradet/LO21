#include "reel.h"

Constante& Reel::GetVal()const
{
    Reel r(value);
    return r;
}

float Reel::toFloat()const
{
    return value;
}

Constante& Reel::operator+(const Constante& c)
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(r->toFloat() + value);
        return res;
    }
    else;//erreur
}

Constante& Reel::operator-(const Constante& c)
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value - r->toFloat());
        return res;
    }
    else;//erreur
}

Constante& Reel::operator*(const Constante& c)
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value * r->toFloat());
        return res;
    }
    else;//erreur
}

Constante& Reel::operator/(const Constante& c)
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value / r->toFloat());
        return res;
    }
    else;//erreur
}
