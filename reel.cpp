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

Constante& Reel::operator+(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(r->toFloat() + value);
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator-(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value - r->toFloat());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator*(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value * r->toFloat());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator/(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value / r->toFloat());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator-(int)const
{
    Reel r(-value);
    return r;
}

Constante& Reel::operator^(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Reel res(pow(value, e->toInt()));
        return res;
    }
    else if(r!=0)
    {
        Reel res(pow(value, r->toFloat()));
        return res;
    }
    else if(f!=0)
    {
        Reel res(pow(pow(value, f->GetNum()), -f->GetDen()));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}
