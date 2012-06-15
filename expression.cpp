#include "expression.h"

Constante& Expression::GetVal()const
{
    Constante* e = new Expression(exp);
    return *e;
}

Expression::operator QString()
{
    return exp;
}

Expression::operator int()const
{
    try
    {
        throw CalcException("Impossible de convertir une expression en un int.");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Expression::operator float()const
{
    try
    {
        throw CalcException("Impossible de convertir une expression en un float.");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Expression::operator Entier()const
{
    try
    {
        throw CalcException("Impossible de convertir une expression en un Entier.");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Expression::operator Rationnel()const
{
    try
    {
        throw CalcException("Impossible de convertir une expression en un Rationnel.");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Expression::operator Reel()const
{
    try
    {
        throw CalcException("Impossible de convertir une expression en un Reel.");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Expression::operator Complexe()const
{
    try
    {
        throw CalcException("Impossible de convertir une expression en un Complexe.");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

