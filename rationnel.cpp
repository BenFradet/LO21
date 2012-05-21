#include "rationnel.h"

Constante& Rationnel::GetVal()const
{
    Rationnel r(num, den);
    return r;
}

Constante& Rationnel::operator+(const Constante& c)const//ADAPTER A FAIRE
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetDen() + r->GetNum()*den, den*r->GetDen());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Rationnel::operator-(const Constante& c)const
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetDen() - r->GetNum()*den, den*r->GetDen());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Rationnel::operator*(const Constante& c)const
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetNum(), den*r->GetDen());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Rationnel::operator/(const Constante& c)const
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetDen(), den*r->GetNum());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Rationnel::operator-(int)const
{
    Rationnel r(-num, den);
    return r;
}

Constante& Rationnel::operator^(const Constante& c)const//pas sûr
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Rationnel res((int)pow((float)num, e->toInt()), (int)pow((float)den, e->toInt()));
        return res;
    }
    else if(r!=0)
    {
        Reel res(pow((float)num/den, r->toFloat()));
        return res;
    }
    else if(f!=0)
    {
        Reel res(pow(pow((float)num/den, f->GetNum()), -f->GetDen()));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Rationnel::sinus()const
{
    Reel res(sin((float)num/den));
    return res;
}

Constante& Rationnel::cosinus()const
{
    Reel res(cos((float)num/den));
    return res;
}

Constante& Rationnel::tangente()const
{
    Reel res(tan((float)num/den));
    return res;
}
