#include "constante.h"

Constante::operator int()const
{
    throw CalcException("On ne peut pas convertir ce type en int");
}

Constante::operator float()const
{
    throw CalcException("On ne peut pas convertir ce type en float");
}

void Constante::operator =(const Constante& c)
{
    throw CalcException("On ne peut pas affecter");
}

Constante& Constante::operator+(const Constante& c)const
{
    throw CalcException("On ne peut pas ajouter deux expressions");
}

Constante& Constante::operator-(const Constante& c)const
{
    throw CalcException("On ne peut pas soustraire deux expressions");
}

Constante& Constante::operator*(const Constante& c)const
{
    throw CalcException("On ne peut pas multiplier deux expressions");
}

Constante& Constante::operator/(const Constante& c)const
{
    throw CalcException("On ne peut pas diviser deux expressions");
}

Constante& Constante::operator-()const
{
    throw CalcException("On ne peut pas inverser le signe d'une expression");
}

Constante& Constante::operator^(const Constante& c)const
{
    throw CalcException("On ne peut pas élever à la puissance deux expressions ou deux complexes");
}

Constante& Constante::sinus()const
{
    throw CalcException("On ne peut pas appliquer le sinus à une expression ou à un complexe");
}

Constante& Constante::cosinus()const
{
    throw CalcException("On ne peut pas appliquer le cosinus à une expression ou à un complexe");
}

Constante& Constante::tangente()const
{
    throw CalcException("On ne peut pas appliquer la tangente à une expression ou à un complexe");
}

Constante& Constante::sinush()const
{
    throw CalcException("On ne peut pas appliquer le sinus hyperbolique à une expression ou à un complexe");
}

Constante& Constante::cosinush()const
{
    throw CalcException("On ne peut pas appliquer le cosinus hyperbolique à une expression ou à un complexe");
}

Constante& Constante::tangenteh()const
{
    throw CalcException("On ne peut pas appliquer la tangente hyperbolique à une expression ou à un complexe");
}

Constante& Constante::logdec()const
{
    throw CalcException("On ne peut pas appliquer le logarithme décimal à une expression ou à un complexe");
}

Constante& Constante::lognep()const
{
    throw CalcException("On ne peut pas appliquer le logarithme népérien à une expression ou à un complexe");
}

Constante& Constante::inverse()const
{
    throw CalcException("On ne peut pas appliquer l'inverse à une expression ou à un complexe");
}

Constante& Constante::racine()const
{
    throw CalcException("On ne peut pas appliquer la racine carrée à une expression ou à un complexe");
}

Constante& Constante::carree()const
{
    throw CalcException("On ne peut pas appliquer le carré à une expression");
}

Constante& Constante::cube()const
{
    throw CalcException("On ne peut pas appliquer le cube à une expression");
}
