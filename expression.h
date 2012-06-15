#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "include.h"
#include <QString>

//! La classe gerant les Expression.
/*! Elle herite de la classe Constante.*/
class Expression: public Constante
{
    //! La valeur de l'expression modelisee par une QString.
    /*! \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>*/
    QString exp;
public:
    //! Constructeur principal de la classe Expression.
    /*! On affecte la valeur passee en parametre a l'attribut exp.
    \param val Une QString affectee a l'attribut exp.
    \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    */
    Expression(QString s): exp(s){}

    //! Surcharge de l'operateur de cast de Expression vers int.
    /*! Surcharge obligatoire car methode virtuelle pure dans Constante, lance une exception.
      \sa CalcException
    */
    operator int()const;
    //! Surcharge de l'operateur de cast de Expression vers float.
    /*! Surcharge obligatoire car methode virtuelle pure dans Constante, lance une exception.
      \sa CalcException
    */
    operator float()const;
    //! Surcharge de l'operateur de cast de Expression vers Entier.
    /*! Surcharge obligatoire car methode virtuelle pure dans Constante, lance une exception.
      \sa Entier
      \sa CalcException
    */
    operator Entier()const;
    //! Surcharge de l'operateur de cast de Expression vers Rationnel.
    /*! Surcharge obligatoire car methode virtuelle pure dans Constante, lance une exception.
      \sa Rationnel
      \sa CalcException
    */
    operator Rationnel()const;
    //! Surcharge de l'operateur de cast de Expression vers Reel.
    /*! Surcharge obligatoire car methode virtuelle pure dans Constante, lance une exception.
      \sa Reel
      \sa CalcException
    */
    operator Reel()const;
    //! Surcharge de l'operateur de cast de Expression vers Complexe.
    /*! Surcharge obligatoire car methode virtuelle pure dans Constante, lance une exception.
      \sa Complexe
      \sa CalcException
    */
    operator Complexe()const;

    //! Definition de la methode virtuelle pure GetVal de la classe Constante.
    /*! Cree un nouvel objet Entier a partir de l'attribut exp de l'argument implicite.
      \return Une reference sur Constante.
      \sa Constante::GetVal()
    */
    Constante& GetVal()const;

    //! Surcharge de l'operateur de cast de Expression vers QString.
    /*!
      On retourne la valeur de l'attribut exp de l'argument implicite qui est deja une QString.
      \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    */
    operator QString();
};

#endif // EXPRESSION_H
