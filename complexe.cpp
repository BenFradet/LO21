#include "complexe.h"

Constante& Complexe::GetVal()const
{
    Complexe c(pRe, pIm);
    return c;
}

Constante& Complexe::operator+(const Constante& c)const
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Complexe res(pRe + co->GetRe(), pIm + co->GetIm());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Complexe::operator-(const Constante& c)const
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Complexe res(pRe - co->GetRe(), pIm - co->GetIm());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Complexe::operator*(const Constante& c)const
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Complexe res(pRe*co->GetRe()-pIm*co->GetIm(), pRe*co->GetIm()+pIm*co->GetRe());
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Complexe::operator/(const Constante& c)const
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Entier e(0);
        return e;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Complexe::operator-(int)const
{
    Complexe c(pRe - Entier(2)*pRe, pIm-Entier(2)*pIm);//trouver une meilleure solution
    return c;
}

Constante& Complexe::carree()const
{
    Entier e(0);//à implémenter
    return e;
}

Constante& Complexe::cube()const
{
    Entier e(0);//à implémenter
    return e;
}
