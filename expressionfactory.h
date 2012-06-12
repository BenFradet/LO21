#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include <QString>
#include "expression.h"
#include "constante.h"

class ExpressionFactory
{
public:
    ExpressionFactory(){}
    static Constante* GetExpressionUnaire(QString val, QString operation);
    static Constante* GetExpressionBinaire2Exp(QString val1, QString val2, QString operation);
    static Constante* GetExpressionBinaire1Exp(QString exp, QString cons, QString operation);
};

#endif // EXPRESSIONFACTORY_H
