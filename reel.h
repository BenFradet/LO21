#ifndef REEL_H
#define REEL_H

#include "constante.h"
#include "complexe.h"
#include <QString>
#include <QTextStream>

class Entier;
class Rationnel;

//! La classe gerant les Reel.
/*! Elle herite de la classe Constante.*/
class Reel: public Constante
{
    //! Valeur du Reel representee par un float.
    float value;
public:
    //! Constructeur principal de la classe Reel.
    /*! On affecte la valeur passee en parametre a l'attribut value.
    \param val Un float a affecter a l'attribut value.
    */
    Reel(float val):value(val){}

    //! Autre constructeur.
    /*! Convertit la QString passe en parametre en un Reel.
      \param s Une QString transformee en float.
      \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    */
    Reel(QString s)
    {
       value = s.toFloat();
    }

    //! Definition de la methode virtuelle pure GetVal de la classe Constante.
    /*! Cree un nouvel objet Reel a partir de l'attribut value de l'argument implicite.
      \return Une reference sur Constante.
      \sa Constante::GetVal()
    */
    Constante& GetVal()const;

    //! Surcharge de l'operateur de cast de Reel vers int.
    operator int()const;
    //! Surcharge de l'operateur de cast de Reel vers float.
    operator float()const;
    //! Surcharge de l'operateur de cast de Reel vers Entier.
    /*! \sa Entier */
    operator Entier()const;
    //! Surcharge de l'operateur de cast de Reel vers Rationnel.
    /*! \sa Rationnel */
    operator Rationnel()const;
    //! Surcharge de l'operateur de cast de Reel vers Reel.
    operator Reel()const;
    //! Surcharge de l'operateur de cast de Reel vers Complexe.
    /*! \sa Complexe */
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

    operator QString(); // crée QString à partir d'un réel
};

#endif // REEL_H
