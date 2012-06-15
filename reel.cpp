#include "reel.h"

Constante& Reel::GetVal()const
{
    Constante* r = new Reel(value);
    return *r;
}

Reel::operator int()const
{
    return (int)value;
}

Reel::operator float()const
{
    return value;
}

Reel::operator Entier()const
{
    return Entier((int)value);
}

Reel::operator Rationnel()const
{
    float f = value;
    int e = (int)f, i = 0;
    do
    {
        f*=10;
        e = (int)f;
        i++;
    }while(f!=(float)e);
    return Rationnel(e, (int)pow((float)10, i));
}

Reel::operator Reel()const
{
    return *this;
}


Reel::operator Complexe()const
{
    Reel* r = new Reel(value);
    Reel* zero = new Reel(0);
    return Complexe(r, zero);
}

//! Surcharge de l'operateur d'addition entre deux Reel.
/*! A noter que l'on tente un dynamic cast sur l'argument qui est la seulement en cas d'un developpement futur
  car toutes nos operandes sont castees avant d'effectuer n'importe quelle operation.
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa CalcException
*/
Constante& Reel::operator+(const Constante& c)const
{
    try
    {
        const Reel* r = dynamic_cast<const Reel*>(&c);
        if(r!=0)
        {
            Reel* res = new Reel((float)*r + value);
            return *res;
        }
        else
        {
            throw CalcException("L'opération d'addition nécessite que les deux opérateurs soient de même type");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de soustraction entre deux Reel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Reel.
  \sa CalcException
*/
Constante& Reel::operator-(const Constante& c)const
{
    try
    {
        const Reel* r = dynamic_cast<const Reel*>(&c);
        if(r!=0)
        {
            Reel* res = new Reel(value - (float)*r);
            return *res;
        }
        else
        {
            throw CalcException("L'opération de soustraction nécessite que les deux opérateurs soient de même type");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de multiplication entre deux Reel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Reel.
  \sa CalcException
*/
Constante& Reel::operator*(const Constante& c)const
{
    try
    {
        const Reel* r = dynamic_cast<const Reel*>(&c);
        if(r!=0)
        {
            Reel* res = new Reel(value * (float)*r);
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

//! Surcharge de l'operateur de division entre deux Reel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouvel Reel.
  \sa CalcException
*/
Constante& Reel::operator/(const Constante& c)const
{
    try
    {
        const Reel* r = dynamic_cast<const Reel*>(&c);
        if(r!=0)
        {
            Reel* res = new Reel(value / (float)*r);
            return *res;
        }
        else
        {
            throw CalcException("L'opération de division nécessite que les deux opérateurs soient de même type");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Surcharge de l'operateur de changement du signe d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
*/
Constante& Reel::operator-()const
{
    Reel* r = new Reel(-value);
    return *r;
}

//! Surcharge de l'operateur d'elevation a l'exposant entre deux Reel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa CalcException
  \sa <a href="http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Reel::operator^(const Constante& c)const
{
    try
    {
        const Reel* r = dynamic_cast<const Reel*>(&c);
        if(r!=0)
        {
            Reel* res = new Reel(pow(value, (float)*r));
            return *res;
        }
        else
        {
            throw CalcException("L'opération de puissance nécessite que l'exposant soit un entier, un rationnel ou un réel");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul du sinus d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sin/">sin</a>
*/
Constante& Reel::sinus()const
{
    Reel* res = new Reel(sin(value));
    return *res;
}

//! Operation du calcul du cosinus d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/cos/">cos</a>
*/
Constante& Reel::cosinus()const
{
    Reel* res = new Reel(cos(value));
    return *res;
}

//! Operation du calcul de la tangente d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouvel Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/tan/">tan</a>
*/
Constante& Reel::tangente()const
{
    Reel* res = new Reel(tan(value));
    return *res;
}

//! Operation du calcul du sinus hyperbolique d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sinh/">sinh</a>
*/
Constante& Reel::sinush()const
{
    Reel* res = new Reel(sinh(value));
    return *res;
}

//! Operation du calcul du cosinus hyperbolique d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/cosh/">cosh</a>
*/
Constante& Reel::cosinush()const
{
    Reel* res = new Reel(cosh(value));
    return *res;
}

//! Operation du calcul de la tangente hyperbolique d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/cosh/">cosh</a>
*/
Constante& Reel::tangenteh()const
{
    Reel* res = new Reel(tanh(value));
    return *res;
}

//! Operation du calcul du logarithme decimal d'un Reel.
/*!
  On verifie que la valeur de l'argument implicite soit superieure a 0.
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa CalcException
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/log10/">log10</a>
*/
Constante& Reel::logdec()const
{
    try
    {
        if(value>0)
        {
            Reel* res = new Reel(log10(value));
            return *res;
        }
        else
        {
            throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul du logarithme neperien d'un Reel.
/*!
  On verifie que la valeur de l'argument implicite soit superieure a 0.
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa CalcException
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/log/">log</a>
*/
Constante& Reel::lognep()const
{
    try
    {
        if(value>0)
        {
            Reel* res = new Reel(log(value));
            return *res;
        }
        else
        {
            throw CalcException("L'opération de logarithme nécessite que l'opérateur soit positif");
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul de l'inverse d'un Reel.
/*!
  On verifie que la valeur de l'argument implicite soit differente de 0.
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa CalcException
*/
Constante& Reel::inverse()const
{
    try
    {
        if(value!=0)
        {
            Reel* res = new Reel(1/value);
            return *res;
        }
        else
            throw CalcException("L'opération d'inverse est impossible avec zéro");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul de la racine carree d'un Reel.
/*!
  On verifie que la valeur de l'argument implicite soit superieure ou egale a 0.
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa CalcException
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sqrt/">sqrt</a>
*/
Constante& Reel::racine()const
{
    try
    {
        if(value>=0)
        {
            Reel* res = new Reel(sqrt(value));
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

//! Operation du calcul du carre d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Reel::carree()const
{
    Reel* res = new Reel(pow(value,2));
    return *res;
}

//! Operation du calcul du cube d'un Reel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Reel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Reel::cube()const
{
    Reel* res = new Reel(pow(value,3));
    return *res;
}

//! Surcharge de l'operateur de cast de Reel vers QString.
/*!
  On cree un QTextStream avec une QString initialement vide auquel on ajoute la valeur de l'attribut value de l'argument implicite.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/qtextstream.html">QTextStream</a>
*/
Reel::operator QString()
{
    QString str;
    QTextStream tx(&str);
    tx << value;
    return str;
}
