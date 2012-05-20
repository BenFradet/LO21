#include "expression.h"

Constante& Expression::GetVal()const
{
    Expression e(exp);
    return e;
}

Constante& Expression::operator+(const Constante& c)const
{
    Expression e("Erreur");
    return e;
}

Constante& Expression::operator-(const Constante& c)const
{
    Expression e("Erreur");
    return e;
}

Constante& Expression::operator*(const Constante& c)const
{
    Expression e("Erreur");
    return e;
}

Constante& Expression::operator/(const Constante& c)const
{
    Expression e("Erreur");
    return e;
}

Constante& Expression::operator-(int)const
{
    Expression e("Erreur");
    return e;
}

Constante& Expression::operator^(const Constante& c)const
{
    Expression e("Erreur");
    return e;
}

