#include "expression.h"
#include <QTextStream>

Constante& Expression::GetVal()const
{
    Expression e(exp);
    return e;
}

QString Expression::ToQString()
{
    QString str ="a";
   /* QTextStream tx(&str);
    tx << exp;*/
    return str;
}

