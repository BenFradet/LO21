#include "expression.h"

Constante& Expression::GetVal()const
{
    Expression e(exp);
    return e;
}

Constante& Expression::operator+(const Constante& c)
{
    return Entier(0);
    //erreur
}

Constante& Expression::operator-(const Constante& c)
{
    return Entier(0);
    //erreur
}

Constante& Expression::operator*(const Constante& c)
{
    return Entier(0);
    //erreur
}

Constante& Expression::operator/(const Constante& c)
{
    return Entier(0);
    //erreur
}

