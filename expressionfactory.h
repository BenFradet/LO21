#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include <QString>
#include "expression.h"
#include "constante.h"

//! Fabrique d'Expression
/*! Grace au design pattern <a href="http://fr.wikipedia.org/wiki/Fabrique_(patron_de_conception)">Fabrique</a> on cree une Expression en fonction des QString et de l'operation que l'on veut ajoute à cette expression.
*/
class ExpressionFactory
{
public:
    static Constante* GetExpressionUnaire(QString val, QString operation);
    static Constante* GetExpressionBinaire2Exp(QString val1, QString val2, QString operation);
    static Constante* GetExpressionBinaire1Exp(QString exp, QString cons, QString operation);
};

#endif // EXPRESSIONFACTORY_H
