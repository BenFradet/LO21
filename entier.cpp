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

Constante& Entier::operator+(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value+e->toInt());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::operator-(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value-e->toInt());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::operator*(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value*e->toInt());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::operator/(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value/e->toInt());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::operator-(int)const
{
    Entier e(-value);
    return e;
}

Constante& Entier::operator^(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Entier res((int)pow((float)value, e->toInt()));
        return res;
    }
    else if(r!=0)
    {
        Reel res(pow(value, r->toFloat()));
        return res;
    }
    else if(f!=0)
    {
        Reel res(pow(pow((float)value, f->GetNum()), -f->GetDen()));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::sinus()const
{
    Reel res(sin((float)value));
    return res;
}

Constante& Entier::cosinus()const
{
    Reel res(cos((float)value));
    return res;
}

Constante& Entier::tangente()const
{
    Reel res(tan((float)value));
    return res;
}

Constante& Entier::operator%(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier res(value%e->toInt());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}





