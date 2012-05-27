#include "reel.h"
#include <QTextStream>

Constante& Reel::GetVal()const
{
    Reel r(value);
    return r;
}

Reel::operator float()const
{
    return value;
}

Constante& Reel::operator+(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res((float)*r + value);
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator-(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value - (float)*r);
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator*(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value * (float)*r);
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator/(const Constante& c)const
{
    const Reel* r = dynamic_cast<const Reel*>(&c);
    if(r!=0)
    {
        Reel res(value / (float)*r);
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::operator-(int)const
{
    Reel r(-value);
    return r;
}

Constante& Reel::operator^(const Constante& c)const
{
    const Entier* e = dynamic_cast<const Entier*>(&c);
    const Reel* r = dynamic_cast<const Reel*>(&c);
    const Rationnel* f = dynamic_cast<const Rationnel*>(&c);

    if(e!=0)
    {
        Reel res(pow(value, (int)*e));
        return res;
    }
    else if(r!=0)
    {
        Reel res(pow(value, (float)*r));
        return res;
    }
    else if(f!=0)
    {
        Reel res(pow(pow(value, f->GetNum()), -f->GetDen()));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::sinus()const
{
    Reel res(sin(value));
    return res;
}

Constante& Reel::cosinus()const
{
    Reel res(cos(value));
    return res;
}

Constante& Reel::tangente()const
{
    Reel res(tan(value));
    return res;
}

Constante& Reel::sinush()const
{
    Reel res(sinh(value));
    return res;
}

Constante& Reel::cosinush()const
{
    Reel res(cosh(value));
    return res;
}

Constante& Reel::tangenteh()const
{
    Reel res(tanh(value));
    return res;
}

Constante& Reel::logdec()const
{
    if(value>0)
    {
        Reel res(log10(value));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::lognep()const
{
    if(value>0)
    {
        Reel res(log(value));
        return res;
    }
    else
    {
        Expression e("Erreur");
        return e;
    }
}

Constante& Reel::inverse()const
{
    Reel res(1/value);
    return res;
}

Constante& Reel::racine()const
{
    Reel res(sqrt(value));
    return res;
}

Constante& Reel::carree()const
{
    Reel res(pow(value,2));
    return res;
}

Constante& Reel::cube()const
{
    Reel res(pow(value,3));
    return res;
}

QString Reel::ToQString()
{
        QString str;
        QTextStream tx(&str);
        tx << value;
        return str;
    }
