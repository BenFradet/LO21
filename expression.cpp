#include "expression.h"
#include <QTextStream>

Constante& Expression::GetVal()const
{
    Expression e(exp);
    return e;
}

Expression::operator QString()
{
    return exp;
   /* QTextStream tx(&str);
    tx << exp;
    return str;*/
}

Expression::operator int()const
{
    //exception
    return 0;
}

Expression::operator float()const
{
    //exception
    return 0;
}

Expression::operator Entier()const
{
    //exception
    return Entier(0);
}

Expression::operator Rationnel()const
{
    //exception
    return Rationnel(0, 1);
}

Expression::operator Reel()const
{
    //exception
    return Reel(0);
}

Expression::operator Complexe()const
{
    //exception
    return Complexe(&Entier(0), &Entier(0));
}

