#include "rationnel.h"

Constante& Rationnel::GetVal()const
{
    Rationnel r(num, den);
    return r;
}

Constante& Rationnel::operator+(const Constante& c)//ADAPTER A FAIRE
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetDen() + r->GetNum()*den, den*r->GetDen());
        return res;
    }
    else;//erreur
}

Constante& Rationnel::operator-(const Constante& c)
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetDen() - r->GetNum()*den, den*r->GetDen());
        return res;
    }
    else;//erreur
}

Constante& Rationnel::operator*(const Constante& c)
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetNum(), den*r->GetDen());
        return res;
    }
    else;//erreur
}

Constante& Rationnel::operator/(const Constante& c)
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel res(num*r->GetDen(), den*r->GetNum());
        return res;
    }
    else;//erreur
}
