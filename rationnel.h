#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "entier.h"
#include <QString>
#include <QStringList>
#include <QTextStream>

class Entier;
class Reel;

//! La classe gerant les Rationnel.
/*! Elle herite de la classe Constante.
    A noter que nous aurions pu faire un Adapter avec la classe Fraction developpee en td mais nous avons préféré redévelopper une nouvelle classe.*/
class Rationnel : public Constante
{
    //! Valeur du numerateur du Rationnel representee par un int.
    int num;
    //! Valeur du numerateur du Rationnel representee par un int.
    int den;
    //! Methode permettant de simplifier un Rationnel.
    void simplifier();
public:
    //! Constructeur principal de la classe Rationnel.
    /*! On affecte les valeurs passees en parametres aux attributs num et den.
    \param n Un entier a affecter a l'attribut num.
    \param d Un entier a affecter a l'attribut den.
    \sa CalcException
    */
    Rationnel(int n, int d)
    {
        try
        {
            if(d!=0)
            {
                num = n;
                den = d;
                simplifier();
            }
            else
                throw CalcException("Le dénominateur ne peut pas valoir zéro");
        }
        catch (CalcException c)
        {
            c.alert();
        }
    }

    //! Autre constructeur.
    /*! Convertit la QString passe en parametre en un Rationnel.
      On separe tout d'abord la QString passee en parametre par le '/' puis on affecte au numerateur la partie de gauche et au denominateur la partie de droite.
      \param s Une QString representant un Rationnel.
      \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
      \sa <a href="http://qt-project.org/doc/qt-4.8/QStringList.html">QStringList</a>
      \sa CalcException
    */
    Rationnel(QString s)
    {
        QStringList liste = s.split("/");

        if (liste[1].toInt() != 0)
        {
            num = liste[0].toInt();
            den = liste[1].toInt();
            simplifier();
        }
        else
            throw CalcException("Le dénominateur ne peut pas valoir zéro");
    }

    int GetDen()const{return den;}
    int GetNum()const{return num;}
    Constante& GetVal()const;
    void SetDen(int d){den = d;}
    void SetNum(int n){num = n;}

    operator int()const;
    operator float()const;
    operator Entier()const;
    operator Rationnel()const;
    operator Reel()const;
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
};

#endif // RATIONNEL_H
