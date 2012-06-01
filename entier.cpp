#include "entier.h"
#include <QTextStream>

Constante& Entier::GetVal()const
{
    Entier e(value);
    return e;
}

Entier::operator int()const
{
    return value;
}

Entier::operator float()const
{
    return (float)value;
}

void Entier::operator=(const Constante& c)
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        this->value = e->value;
    }
    else
    {
        throw CalcException("L'opération d'addition nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Entier::operator+(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier* res = new Entier(value+(int)*e);
        return *res;
    }
    else
    {
        throw CalcException("L'opération d'addition nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Entier::operator-(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier* res = new Entier(value-(int)*e);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de soustraction nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Entier::operator*(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier* res = new Entier(value*(int)*e);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de multiplication nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Entier::operator/(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Rationnel* res = new Rationnel(value, (int)*e);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de division nécessite que les deux opérateurs soient de même type");
    }
}

Constante& Entier::operator-()const
{
    Entier* e = new Entier(-value);
    return *e;
}

Constante& Entier::operator^(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Entier* res = new Entier((int)pow((float)value, (int)*e));
        return *res;
    }
    else if(r!=0)
    {
        Reel* res = new Reel(pow(value, (float)*r));
        return *res;
    }
    else if(f!=0)
    {
        Reel* res = new Reel(pow(pow((float)value, f->GetNum()), -f->GetDen()));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de puissance nécessite que l'exposant soit un entier, un rationnel ou un réel");
    }
}

Constante& Entier::sinus()const
{
    Reel* res = new Reel(sin((float)value));
    return *res;
}

Constante& Entier::cosinus()const
{
    Reel* res = new Reel(cos((float)value));
    return *res;
}

Constante& Entier::tangente()const
{
    Reel* res = new Reel(tan((float)value));
    return *res;
}

Constante& Entier::sinush()const
{
    Reel* res = new Reel(sinh((float)value));
    return *res;
}

Constante& Entier::cosinush()const
{
    Reel* res = new Reel(cosh((float)value));
    return *res;
}

Constante& Entier::tangenteh()const
{
    Reel* res = new Reel(tanh((float)value));
    return *res;
}

Constante& Entier::logdec()const
{
    if((int)*this>0)
    {
        Reel* res = new Reel(log10((float)value));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
}

Constante& Entier::lognep()const
{
    if((int)*this>0)
    {
        Reel* res = new Reel(log((float)value));
        return *res;
    }
    else
    {
        throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
}

Constante& Entier::inverse()const
{
    if(value!=0)
    {
        Reel* res = new Reel(1/(float)value);
        return *res;
    }
    else
        throw CalcException("L'opération d'inverse est impossible avec zéro");
}

Constante& Entier::operator%(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    if(e!=0)
    {
        Entier* res = new Entier(value%(int)*e);
        return *res;
    }
    else
    {
        throw CalcException("L'opération de modulo nécessite que les deux opérateurs soient des entiers");
    }
}

Constante& Entier::racine()const
{
    if(value>=0)
    {
        Reel* res = new Reel(sqrt((float)value));
        return *res;
    }
    else
        throw CalcException("L'opération de racine carrée nécessite une valeur positive");
}

Constante& Entier::carree()const
{
    Entier* res = new Entier((int)pow((float)value, 2));
    return *res;
}

Constante& Entier::cube()const
{
    Entier* res = new Entier((int)pow((float)value, 3));
    return *res;
}

Constante& Entier::operator!()const
{
    int e = (int)*this;
    if(e>0)
    {
        for(int i = 1; i<e; i++)
            e *= i;
        Entier* res = new Entier(e);
        return *res;
    }
    else if(e==0)
    {
        Entier* res = new Entier(e);
        return *res;
    }
    else
    {
        throw CalcException("L'opération factorielle nécessite une valeur positive");
    }
}

QString Entier::ToQString()
{
    QString res;
    QTextStream ss(&res);
    ss << value;
    return res;
}


