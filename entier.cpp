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
        throw CalcException("L'op�ration d'addition n�cessite que les deux op�rateurs soient de m�me type");
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
        throw CalcException("L'op�ration d'addition n�cessite que les deux op�rateurs soient de m�me type");
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
        throw CalcException("L'op�ration de soustraction n�cessite que les deux op�rateurs soient de m�me type");
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
        throw CalcException("L'op�ration de multiplication n�cessite que les deux op�rateurs soient de m�me type");
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
        throw CalcException("L'op�ration de division n�cessite que les deux op�rateurs soient de m�me type");
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
        throw CalcException("L'op�ration de puissance n�cessite que l'exposant soit un entier, un rationnel ou un r�el");
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
        throw CalcException("L'op�ration de logarithme n�cessite que l'op�rateur soit positif");
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
        throw CalcException("L'op�ration de logarithme n�cessite que l'op�rateur soit positif");
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
        throw CalcException("L'op�ration d'inverse est impossible avec z�ro");
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
        throw CalcException("L'op�ration de modulo n�cessite que les deux op�rateurs soient des entiers");
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
        throw CalcException("L'op�ration de racine carr�e n�cessite une valeur positive");
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
        throw CalcException("L'op�ration factorielle n�cessite une valeur positive");
    }
}

QString Entier::ToQString()
{
    QString res;
    QTextStream ss(&res);
    ss << value;
    return res;
}


