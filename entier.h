#ifndef INTEGER_H
#define INTEGER_H

#include "include.h"

class Reel;
class Rationnel;

//! La classe gerant les Entier.
/*! Elle herite de la classe Constante.*/
class Entier: public Constante
{
    //! Valeur de l'entier representee par un int.
    int value;
public:
    //! Constructeur principal de la classe Entier.
    /*! On affecte la valeur passee en parametre a l'attribut value.
    \param val Un entier a affecter a l'attribut value.
    */
    Entier(int val):value(val){}

    //! Autre constructeur.
    /*! Convertir la QString passe en parametre en un entier.
      \param s Une QString transformee en int.
    */
    Entier(QString s)
    {
        value = s.toInt();

    }

    //! Definition de la methode virtuelle pure GetVal de la classe Constante.
    /*! Cree un nouvel objet Entier a partir de l'attribut value de l'argument implicite.
      \return Une reference sur Constante.
    */
    Constante& GetVal()const;

    //! Surcharge de l'operateur de cast de Entier vers int.
    operator int()const;
    //! Surcharge de l'operateur de cast de Entier vers float.
    operator float()const;
    //! Surcharge de l'operateur de cast de Entier vers Reel.
    operator Reel()const;
    //! Surcharge de l'operateur de cast de Entier vers Rationnel.
    operator Rationnel()const;
    //! Surcharge de l'operateur de cast de Entier vers Entier.
    operator Entier()const;
    //! Surcharge de l'operateur de cast de Entier vers Complexe.
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

    operator QString();  // crée un QString à partir d'un entier

    Constante& operator%(const Constante& c)const;
    Constante& operator!()const;
};

#endif // INTEGER_H
