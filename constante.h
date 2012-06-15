#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "calcexception.h"
#include <QString>

class Entier;
class Rationnel;
class Reel;
class Complexe;

//! La classe abstraite gerant les Constante.
/*! Elle a pour filles les class Entier, Rationnel, Reel et Complexe.
  On y definit les differentes methodes virtuelles et virtuelles pures qui seront remplacees ou implementees dans les classes filles.
  */
class Constante
{
public:

    //! Getter virtuel pur.
    /*! Elle est implementee dans toutes les classes filles.*/
    virtual Constante& GetVal()const = 0;

    //! Surcharge de l'operateur de cast int virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.*/
    virtual operator int()const = 0;
    //! Surcharge de l'operateur de cast float virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.*/
    virtual operator float()const = 0;
    //! Surcharge de l'operateur de cast Entier virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.
        \sa Entier */
    virtual operator Entier()const = 0;
    //! Surcharge de l'operateur de cast Rationnel virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.
        \sa Rationnel */
    virtual operator Rationnel()const = 0;
    //! Surcharge de l'operateur de cast Reel virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.
        \sa Reel */
    virtual operator Reel()const = 0;
    //! Surcharge de l'operateur de cast Complexe virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.
        \sa Complexe*/
    virtual operator Complexe()const = 0;

    //! Surcharge de l'operateur d'addition entre 2 Constantes.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.*/
    virtual Constante& operator+(const Constante&)const;
    //! Surcharge de l'operateur de soustraction entre 2 Constantes.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.*/
    virtual Constante& operator-(const Constante&)const;
    //! Surcharge de l'operateur de multiplication entre 2 Constantes.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.*/
    virtual Constante& operator*(const Constante&)const;
    //! Surcharge de l'operateur de division entre 2 Constantes.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.*/
    virtual Constante& operator/(const Constante&)const;
    //! Surcharge de l'operateur de changement de signe d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.*/
    virtual Constante& operator-()const;
    //! Surcharge de l'operateur de puissance entre 2 Constantes.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.*/
    virtual Constante& operator^(const Constante&)const;

    //! Operation de calcul du sinus d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& sinus()const;
    //! Operation de calcul du cosinus d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& cosinus()const;
    //! Operation de calcul de la tangente d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& tangente()const;
    //! Operation de calcul du sinus hyperbolique d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& sinush()const;
    //! Operation de calcul du cosinus hyperbolique d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& cosinush()const;
    //! Operation de calcul de la tangente hyperbolique d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& tangenteh()const;
    //! Operation de calcul du logarithme decimal d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& logdec()const;
    //! Operation de calcul du logarithme neperien d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& lognep()const;
    //! Operation de calcul de l'inverse d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.
        \return Une reference sur une Constante.
    */
    virtual Constante& inverse()const;
    //! Operation de calcul de la racine d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mises a part la classe Expression ainsi que la classe Complexe.
        \return Une reference sur une Constante.
    */
    virtual Constante& racine()const;
    //! Operation d'elevation au carre d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.
        \return Une reference sur une Constante.
    */
    virtual Constante& carree()const;
    //! Operation d'elevation au cube d'une Constante.
    /*! Elle est implementee dans toutes les classes filles mise a part la classe Expression.
        \return Une reference sur une Constante.
    */
    virtual Constante& cube()const;

    //! Surcharge de l'operateur de cast QString virtuelle pure.
    /*! Elle est implementee dans toutes les classes filles.
        \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a> */
    virtual operator QString() = 0;
};

#endif // CONSTANTE_H
