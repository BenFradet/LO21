#include "reel.h"
#include <QTextStream>

Constante& Reel::GetVal()const
{
    Reel r(value);
    return r;
}

Reel::operator int()const
{
    return (int)value;
}

Reel::operator float()const
{
    return value;
}

Reel::operator Entier()const
{
    return Entier((int)value);
}

Reel::operator Rationnel()const
{
    float f = value;
    int e = (int)f, i = 0;
    while(f!=(float)e)
    {
        f*=10;
        e = (int)f;
        i++;
    }
    return Rationnel(e, (int)pow((float)10, i));
}

Reel::operator Reel()const
{
    return *this;
}

Reel::operator Complexe()const
{
    Reel* r = new Reel(value);
    Reel* zero = new Reel(0);
    return Complexe(r, zero);
}

Constante& Reel::operator+(const Constante& c)const
{
    try {
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel* res = new Reel((float)*r + value);
        return *res;
    }
    else
    {
        throw CalcException("L'opération d'addition nécessite que les deux opérateurs soient de même type");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::operator-(const Constante& c)const
{
    try {
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel* res = new Reel(value - (float)*r);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de soustraction nécessite que les deux opérateurs soient de même type");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::operator*(const Constante& c)const
{
   try {
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel* res = new Reel(value * (float)*r);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de multiplication nécessite que les deux opérateurs soient de même type");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::operator/(const Constante& c)const
{
    try {
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel* res = new Reel(value / (float)*r);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de division nécessite que les deux opérateurs soient de même type");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::operator-()const
{
    Reel* r = new Reel(-value);
    return *r;
}

Constante& Reel::operator^(const Constante& c)const
{
    try {
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Reel *res = new Reel(pow(value, (int)*e));
        return *res;
    }
    else if(r!=0)
    {
        Reel* res = new Reel(pow(value, (float)*r));
        return *res;
    }
    else if(f!=0)
    {
        Reel* res = new Reel(pow(pow(value, f->GetNum()), -f->GetDen()));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de puissance nécessite que l'exposant soit un entier, un rationnel ou un réel");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::sinus()const
{
    Reel* res = new Reel(sin(value));
    return *res;
}

Constante& Reel::cosinus()const
{
    Reel* res = new Reel(cos(value));
    return *res;
}

Constante& Reel::tangente()const
{
    Reel* res = new Reel(tan(value));
    return *res;
}

Constante& Reel::sinush()const
{
    Reel* res = new Reel(sinh(value));
    return *res;
}

Constante& Reel::cosinush()const
{
    Reel* res = new Reel(cosh(value));
    return *res;
}

Constante& Reel::tangenteh()const
{
    Reel* res = new Reel(tanh(value));
    return *res;
}

Constante& Reel::logdec()const
{
    try {
    if(value>0)
    {
        Reel* res = new Reel(log10(value));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::lognep()const
{
    try {
    if(value>0)
    {
        Reel* res = new Reel(log(value));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::inverse()const
{
    try {
    if(value!=0)
    {
        Reel* res = new Reel(1/value);
        return *res;
    }
    else
        throw CalcException("L'opération d'inverse est impossible avec zéro");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::racine()const
{
    try {
    if(value>=0)
    {
        Reel* res = new Reel(sqrt(value));
        return *res;
    }
    else
        throw CalcException("L'opération de racine carrée nécessite une valeur positive");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante& Reel::carree()const
{
    Reel* res = new Reel(pow(value,2));
    return *res;
}

Constante& Reel::cube()const
{
    Reel* res = new Reel(pow(value,3));
    return *res;
}

Reel::operator QString()
{
    QString str;
    QTextStream tx(&str);
    tx << value;
    return str;
}
