#include "expressionfactory.h"

//! Methode statique creant une nouvelle Expression avec une Expression ainsi qu'une operation.
/*! On insere la chaine de caracteres representant l'operation a la fin de l'Expression.
  \param val QString representant l'Expression.
  \param operation QString representant l'operation.
  \return Un pointeur sur une Constante contenant notre nouvelle Expression.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Expression
*/
Constante* ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
{
    val.replace(val.length()-1, 1, " " + operation + "'");
    return new Expression(val);
}

//! Methode statique creant une nouvelle Expression a partir de 2 Expression ainsi qu'une operation.
/*! On concatene les 2 Expression puis on ajoute la QString correspondant a l'operation souhaitee.
  \param val1 QString representant la premiere Expression.
  \param val2 QString representant la seconde Expression.
  \param operation QString representant l'operation.
  \return Un pointeur sur une Constante contenant notre nouvelle Expression.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Expression
*/
Constante* ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
{
    val2.replace(0, 1, " ");
    val2.remove(val2.length() - 1, 1);
    val2.append(" " + operation + "'");
    val1.remove(val1.length()-1, 1);
    return new Expression(val1 + val2);
}

//! Methode statique creant une nouvelle Expression a partir d'une Expression, une Constante et une operation.
/*! On concatene l'Expression et la Constante puis on ajoute la QString correspondant a l'operation souhaitee.
  \param exp QString representant l'Expression.
  \param cons QString representant la Constante.
  \param operation QString representant l'operation.
  \return Un pointeur sur une Constante contenant notre nouvelle Expression.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Expression
*/
Constante* ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
{
    exp.replace(exp.length()-1, 1, " " + cons + " " + operation + "'");
    return new Expression(exp);
}
