#ifndef INTEGER_H
#define INTEGER_H

#include <QTextStream>
#include "constante.h"
#include "reel.h"
#include "rationnel.h"

//! La classe gerant les Entier.
/*! Elle herite de la classe Constante.*/
class Entier: public Constante
{
    //! Valeur de l'Entier representee par un int.
    int value;
public:
    //! Constructeur principal de la classe Entier.
    /*! On affecte la valeur passee en parametre a l'attribut value.
    \param val Un entier a affecter a l'attribut value.
    */
    Entier(int val):value(val){}

    //! Autre constructeur.
    /*! Convertit la QString passe en parametre en un Entier.
      \param s Une QString transformee en int.
      \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    */
    Entier(QString s)
    {
        value = s.toInt();
    }

    //! Definition de la methode virtuelle pure GetVal de la classe Constante.
    /*! Cree un nouvel objet Entier a partir de l'attribut value de l'argument implicite.
      \return Une reference sur Constante.
      \sa Constante::GetVal()
    */
    Constante& GetVal()const;

    //! Surcharge de l'operateur de cast de Entier vers int.
    operator int()const;
    //! Surcharge de l'operateur de cast de Entier vers float.
    operator float()const;
    //! Surcharge de l'operateur de cast de Entier vers Reel.
    /*! \sa Reel */
    operator Reel()const;
    //! Surcharge de l'operateur de cast de Entier vers Rationnel.
    /*! \sa Rationnel */
    operator Rationnel()const;
    //! Surcharge de l'operateur de cast de Entier vers Entier.
    operator Entier()const;
    //! Surcharge de l'operateur de cast de Entier vers Complexe.
    /*! \sa Compexe */
    operator Complexe()const;

    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-()const;
    Constante& operator^(const Constante& c)const;
    Constante& sinus()const;
    Constante& cosinus()const;
    Constante& tangente()const;
    Constante& sinush()const;
    Constante& cosinush()const;
    Constante& tangenteh()const;
    Constante& logdec()const;
    Constante& lognep()const;
    Constante& inverse()const;
    Constante& racine()const;
    Constante& carree()const;
    Constante& cube()const;

    operator QString();

    Constante& operator%(const Constante& c)const;
    Constante& operator!()const;
};

#endif // INTEGER_H
