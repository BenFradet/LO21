#include "entier.h"

Constante& Entier::GetVal()const
{
    Constante* e = new Entier(value);
    return *e;
}

Entier::operator int()const
{
    return value;
}

Entier::operator float()const
{
    return (float)value;
}

Entier::operator Reel()const
{
    return Reel((float)value);
}

Entier::operator Rationnel()const
{
    return Rationnel(value, 1);
}

Entier::operator Entier()const
{
    return *this;
}

Entier::operator Complexe()const
{
    Entier* e = new Entier(value);
    Entier* zero = new Entier(0);
    return Complexe(e, zero);
}

//! Surcharge de l'operateur d'addition entre deux Entier.
/*! A noter que l'on tente un dynamic cast sur l'argument qui est la seulement en cas d'un developpement futur
  car toutes nos operandes sont castees avant d'effectuer n'importe quelle operation.
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
*/
Constante& Entier::operator+(const Constante& c)const
{
    try
    {
        const Entier* e = dynamic_cast<const Entier*>(&c);
        if(e!=0)
        {
            Entier* res = new Entier(value+(int)*e);
            return *res;
        }
        else
            throw CalcException("L'opération d'addition nécessite que les deux opérateurs soient de même type");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de soustraction entre deux Entier.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
*/
Constante& Entier::operator-(const Constante& c)const
{
    try
    {
        const Entier* e = dynamic_cast<const Entier*>(&c);
        if(e!=0)
        {
            Entier* res = new Entier(value-(int)*e);
            return *res;
        }
        else
            throw CalcException("L'opération de soustraction nécessite que les deux opérateurs soient de même type");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de multiplication entre deux Entier.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
*/
Constante& Entier::operator*(const Constante& c)const
{
    try
    {
        const Entier* e = dynamic_cast<const Entier*>(&c);
        if(e!=0)
        {
            Entier* res = new Entier(value*(int)*e);
            return *res;
        }
        else
        {
            throw CalcException("L'opération de multiplication nécessite que les deux opérateurs soient de même type");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de division entre deux Entier.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
*/
Constante& Entier::operator/(const Constante& c)const
{
    try
    {
        const Entier* e = dynamic_cast<const Entier*>(&c);
        if(e!=0)
        {
            Rationnel* res = new Rationnel(value, (int)*e);
            return *res;
        }
        else
            throw CalcException("L'opération de division nécessite que les deux opérateurs soient de même type");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de changement du signe d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
*/
Constante& Entier::operator-()const
{
    Entier* e = new Entier(-value);
    return *e;
}

//! Surcharge de l'operateur d'elevation a l'exposant entre deux Entier.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
  \sa <a href="http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Entier::operator^(const Constante& c)const
{
    try
    {
        const Entier* e = dynamic_cast<const Entier*>(&c);

        if(e!=0)
        {
            Entier* res = new Entier((int)pow((float)value, (int)*e));
            return *res;
        }
        else
            throw CalcException("L'opération de puissance nécessite que l'opérande et l'exposant soient entiers");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul du sinus d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sin/">sin</a>
*/
Constante& Entier::sinus()const
{
    Reel* res = new Reel(sin((float)value));
    return *res;
}

//! Operation du calcul du cosinus d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/cos/">cos</a>
*/
Constante& Entier::cosinus()const
{
    Reel* res = new Reel(cos((float)value));
    return *res;
}

//! Operation du calcul de la tangente d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/tan/">tan</a>
*/
Constante& Entier::tangente()const
{
    Reel* res = new Reel(tan((float)value));
    return *res;
}

//! Operation du calcul du sinus hyperbolique d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sinh/">sinh</a>
*/
Constante& Entier::sinush()const
{
    Reel* res = new Reel(sinh((float)value));
    return *res;
}

//! Operation du calcul du cosinus hyperbolique d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/cosh/">cosh</a>
*/
Constante& Entier::cosinush()const
{
    Reel* res = new Reel(cosh((float)value));
    return *res;
}

//! Operation du calcul de la tangente hyperbolique d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/tanh/">tanh</a>
*/
Constante& Entier::tangenteh()const
{
    Reel* res = new Reel(tanh((float)value));
    return *res;
}

//! Operation du calcul du logarithme decimal d'un Entier.
/*!
  On verifie que la valeur de l'argument implicite soit superieure a 0.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/log10/">log10</a>
*/
Constante& Entier::logdec()const
{
    try
    {
        if((int)*this>0)
        {
            Reel* res = new Reel(log10((float)value));
            return *res;
        }
        else
            throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul du logarithme neperien d'un Entier.
/*!
  On verifie que la valeur de l'argument implicite soit superieure a 0.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/log/">log</a>
*/
Constante& Entier::lognep()const
{
    try
    {
        if((int)*this>0)
        {
            Reel* res = new Reel(log((float)value));
            return *res;
        }
        else
            throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");

    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul de l'inverse d'un Entier.
/*!
  On verifie que la valeur de l'argument implicite soit differente de 0.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
  \sa Rationnel
*/
Constante& Entier::inverse()const
{
    try
    {
        if(value!=0)
        {
            Rationnel* res = new Rationnel(1, value);
            return *res;
        }
        else
            throw CalcException("L'opération du calculde l'inverse est impossible avec zéro");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de calcul du modulo entre deux Entiers.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
*/
Constante& Entier::operator%(const Constante& c)const
{
    try
    {
        const Entier* e = dynamic_cast<const Entier*>(&c);
        if(e!=0)
        {
            Entier* res = new Entier(value%(int)*e);
            return *res;
        }
        else
            throw CalcException("L'opération de modulo nécessite que les deux opérateurs soient des entiers");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de calcul du factoriel d'un Entier.
/*!
  On verifie que la valeur de l'argument implicite est superieure ou egale a 0.
  On calcule le factoriel de maniere iterative.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
*/
Constante& Entier::operator!()const
{
    try
    {
        int e = (int)*this;
        if(e>0)
        {
            for(int i = e-1; i>1; i--)
                e *= i;
            Entier* res = new Entier(e);
            return *res;
        }
        else if(e==0)
        {
            Entier* res = new Entier(e);
            return *res;
        }
        else
            throw CalcException("L'opération factorielle nécessite une valeur positive");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul de la racine carree d'un Entier.
/*!
  On verifie que la valeur de l'argument implicite soit superieure ou egale a 0.
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa CalcException
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sqrt/">sqrt</a>
*/
Constante& Entier::racine()const
{
    try
    {
        if(value>=0)
        {
            Reel* res = new Reel(sqrt((float)value));
            return *res;
        }
        else
            throw CalcException("L'opération de racine carrée nécessite une valeur positive");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul du carre d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Entier::carree()const
{
    Entier* res = new Entier((int)pow((float)value, 2));
    return *res;
}

//! Operation du calcul du cube d'un Entier.
/*!
  \return Une reference sur une Constante contenant notre nouvel Entier.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Entier::cube()const
{
    Entier* res = new Entier((int)pow((float)value, 3));
    return *res;
}

//! Surcharge de l'operateur de cast de Entier vers QString.
/*!
  On cree un QTextStream avec une QString initialement vide auquel on ajoute la valeur de l'attribut value de l'argument implicite.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/qtextstream.html">QTextStream</a>
*/
Entier::operator QString()
{
    QString res;
    QTextStream ss(&res);
    ss << value;
    return res;
}


