#include "complexe.h"

Constante& Complexe::GetVal()const
{
    Complexe c(pRe, pIm);
    return c;
}

Constante& Complexe::operator+(const Constante& c)
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Complexe res(pRe + co->GetRe(), pIm + co->GetIm());
        return res;
    }
    else;//erreur
}

Constante& Complexe::operator-(const Constante& c)
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Complexe res(pRe - co->GetRe(), pIm - co->GetIm());
        return res;
    }
    else;//erreur
}

Constante& Complexe::operator*(const Constante& c)
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        Complexe res(pRe*co->GetRe()-pIm*co->GetIm(), pRe*co->GetIm()+pIm*co->GetRe());
        return res;
    }
    else;//erreur
}

Constante& Complexe::operator/(const Constante& c)
{
    const Complexe* co = dynamic_cast<const Complexe*>(&c);
    if(co!=0)
    {
        return Entier(0);
        //??
    }
    else;//erreur
}

