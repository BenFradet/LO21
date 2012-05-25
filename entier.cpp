#include "entier.h"
#include <QTextStream>

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

Constante& Entier::sinush()const
{
    Reel res(sinh((float)value));
    return res;
}

Constante& Entier::cosinush()const
{
    Reel res(cosh((float)value));
    return res;
}

Constante& Entier::tangenteh()const
{
    Reel res(tanh((float)value));
    return res;
}

Constante& Entier::logdec()const
{
    if(this->toInt()>0)
    {
        Reel res(log10((float)value));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::lognep()const
{
    if(this->toInt()>0)
    {
        Reel res(log((float)value));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Entier::inverse()const
{
    Reel res(1/(float)value);
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

Constante& Entier::racine()const
{
    Reel res(sqrt((float)value));
    return res;
}

Constante& Entier::carree()const
{
    Entier res((int)pow((float)value, 2));
    return res;
}

Constante& Entier::cube()const
{
    Entier res((int)pow((float)value, 3));
    return res;
}

Constante& Entier::operator!()const
{
    int e = this->toInt();
    if(e>0)
    {
        for(int i = 1; i<e; i++)
            e *= i;
        Entier res(e);
        return res;
    }
    else if(e==0)
    {
        Entier res(e);
        return res;
    }
    else
    {
        Expression res("Erreur");
        return res;
    }
}

QString Entier::ToQString()
{
    QString res;
    QTextStream ss(&res);
    ss << value;
    return res;
}


