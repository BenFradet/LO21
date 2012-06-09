#include "rationnel.h"
#include <QTextStream>

Constante& Rationnel::GetVal()const
{
    Rationnel r(num, den);
    return r;
}

Rationnel::operator int()const
{
    return num/den;
}

Rationnel::operator float()const
{
    return (float)num/den;
}

Rationnel::operator Entier()const
{
    return Entier(num/den);
}

Rationnel::operator Rationnel()const
{
    return *this;
}

Rationnel::operator Reel()const
{
    return Reel((float)num/den);
}

Rationnel::operator Complexe()const
{
    Rationnel* r = new Rationnel(num, den);
    Rationnel* zero = new Rationnel(0, 1);
    return Complexe(r, zero);
}

Constante& Rationnel::operator+(const Constante& c)const//ADAPTER A FAIRE
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel* res = new Rationnel(num*r->GetDen() + r->GetNum()*den, den*r->GetDen());
        return *res;
    }
    else
    {
        throw CalcException("L'opération d'addition nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Rationnel::operator-(const Constante& c)const
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel* res = new Rationnel(num*r->GetDen() - r->GetNum()*den, den*r->GetDen());
        return *res;
    }
    else
    {
        throw CalcException("L'opération de soustraction nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Rationnel::operator*(const Constante& c)const
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel* res = new Rationnel(num*r->GetNum(), den*r->GetDen());
        return *res;
    }
    else
    {
        throw CalcException("L'opération de multiplication nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Rationnel::operator/(const Constante& c)const
{
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel* res = new Rationnel(num*r->GetDen(), den*r->GetNum());
        return *res;
    }
    else
    {
        throw CalcException("L'opération de division nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Rationnel::operator-()const
{
    Rationnel* r = new Rationnel(-num, den);
    return *r;
}

Constante& Rationnel::operator^(const Constante& c)const//pas sûr
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Rationnel* res = new Rationnel((int)pow((float)num, (int)*e), (int)pow((float)den, (int)*e));
        return *res;
    }
    else if(r!=0)
    {
        Reel* res = new Reel(pow((float)num/den, (float)*r));
        return *res;
    }
    else if(f!=0)
    {
        Reel* res = new Reel(pow(pow((float)num/den, f->GetNum()), -f->GetDen()));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de puissance nécessite que l'exposant soit un entier, un rationnel ou un réel");
    }
}

Constante& Rationnel::sinus()const
{
    Reel* res = new Reel(sin((float)num/den));
    return *res;
}

Constante& Rationnel::cosinus()const
{
    Reel* res = new Reel(cos((float)num/den));
    return *res;
}

Constante& Rationnel::tangente()const
{
    Reel* res = new Reel(tan((float)num/den));
    return *res;
}

Constante& Rationnel::sinush()const
{
    Reel* res = new Reel(sinh((float)num/den));
    return *res;
}

Constante& Rationnel::cosinush()const
{
    Reel* res = new Reel(cosh((float)num/den));
    return *res;
}

Constante& Rationnel::tangenteh()const
{
    Reel* res = new Reel(tanh((float)num/den));
    return *res;
}

Constante& Rationnel::logdec()const
{
    if((num>0 && den>0) || (num<=0 && den<=0))
    {
        Reel* res = new Reel(log10((float)num/den));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
}

Constante& Rationnel::lognep()const
{
    if((num>0 && den>0) || (num<=0 && den<=0))
    {
        Reel* res = new Reel(log((float)num/den));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
}

Constante& Rationnel::inverse()const
{
    if(num!=0)
    {
        Rationnel* res = new Rationnel(den, num);
        return *res;
    }
    else
        throw CalcException("L'opération d'inverse est impossible avec zéro");
}

Constante& Rationnel::racine()const
{
    if((num>0 && den>0) || (num<=0 && den<=0))
    {
        Reel* res = new Reel(sqrt((float)num/den));
        return *res;
    }
    else
        throw CalcException("L'opération de racine carrée nécessite une valeur positive");
}

Constante& Rationnel::carree()const
{
    Rationnel* res = new Rationnel((int)pow((float)num,2), (int)pow((float)den,2));
    return *res;
}

Constante& Rationnel::cube()const
{
    Rationnel* res = new Rationnel((int)pow((float)num,3), (int)pow((float)den,3));
    return *res;
}

Rationnel::operator QString()
{
    QString str;
    QTextStream tx(&str);
    tx << num << '/' << den ;
    return str;
}
