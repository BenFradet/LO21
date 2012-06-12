#include "expressionfactory.h"

Constante* ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
{
    return 0;
}

Constante* ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
{
    val2.replace(0, 1, " ");
    val2.remove(val2.length() - 1, 1);
    val2.append(" " + operation + "'");
    val1.remove(val1.length()-1, 1);
    return new Expression(val1 + val2);
}

Constante* ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
{
    exp.replace(exp.length()-1, 1, " " + cons + " " + operation + "'");
    return new Expression(exp);
}
