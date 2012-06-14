#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "include.h"
#include "constantefactory.h"
#include "mainwindow.h"
#include <QString>
#include <QStringList>

//! La classe gerant les Complexes.
/*! Elle herite de la classe Constante*/

class Complexe: public Constante
{
    //! Sa partie reelle.
    /*! On utilise un pointeur sur une constante.*/
    Constante* pRe;
    //! Sa partie imaginaire.
    /*! On utilise un pointeur sur une constante.*/
    Constante* pIm;
public:
    //! Le constructeur principal de la classe Complexe.
    /*! Initialise les attributs de la classe avec les pointeurs sur Constante passes en argument.
        \param r Un pointeur sur Constante designant la partie reelle du Complexe.
        \param i Un pointeur sur Constante designant la partie imaginaire du Complexe.
    */
    Complexe(Constante* r, Constante* i): Constante(), pRe(r), pIm(i){}

    Complexe(QString &s, QString mode);

    //! Getter de la partie reelle.
    /*! Objet Complexe non modifie donc l'argument implicite reste constant.
      \return La partie reelle de l'objet complexe sous forme de pointeur vers une constante.
    */
    Constante* GetRe()const{return pRe;}
    //! Getter de la partie imaginaire.
    /*! Objet Complexe non modifie donc l'argument implicite reste constant.
      \return La partie imaginaire de l'objet complexe sous forme de pointeur vers une constante.
    */
    Constante* GetIm()const{return pIm;}
    //! Setter de la partie reelle.
    /*! Affecte l'argument à la partie reelle de l'objet complexe.
      \param r Un pointeur vers une Constante.
    */
    void SetRe(Constante* r){pRe = r;}
    //! Setter de la partie imaginaire.
    /*! Affecte l'argument à la partie imaginaire de l'objet complexe.
      \param i Un pointeur vers une Constante.
    */
    void SetIm(Constante* i){pIm = i;}

    //! Definition de la methode virtuelle pure GetVal de la classe Constante.
    /*! Cree un nouvel objet Complexe avec la partie reelle et imaginaire de l'argument implicite.
      \return Une reference sur Constante.
    */
    Constante& GetVal()const;

    //! Surcharge de l'operateur de cast de Complexe vers int.
    /*! On a choisi de convertir la partie reelle du complexe en int.
    */
    operator int()const;
    //! Surcharge de l'operateur de cast de Complexe vers float.
    /*! On a choisi de convertir la partie reelle du complexe en float.
    */
    operator float()const;
    //! Surcharge de l'operateur de cast de Complexe vers Entier.
    /*! On a choisi de convertir la partie reelle du complexe en Entier.
    */
    operator Entier()const;
    //! Surcharge de l'operateur de cast de Complexe vers Rationnel.
    /*! On a choisi de convertir la partie reelle du complexe en Rationnel.
    */
    operator Rationnel()const;
    //! Surcharge de l'operateur de cast de Complexe vers Reel.
    /*! On a choisi de convertir la partie reelle du complexe en Reel.
    */
    operator Reel()const;
    //! Surcharge de l'operateur de cast de Complexe vers Complexe.
    /*! On retourne la valeur de l'argument implicite.
    */
    operator Complexe()const;

    Constante& operator+(const Constante& c)const;
    Constante& operator-(const Constante& c)const;
    Constante& operator*(const Constante& c)const;
    Constante& operator/(const Constante& c)const;
    Constante& operator-()const;
    Constante& carree()const;
    Constante& cube()const;

    operator QString();
};

#endif // COMPLEXE_H
