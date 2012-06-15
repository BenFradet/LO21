#include "rationnel.h"

//! Definition de la methode virtuelle pure GetVal de la classe Constante.
/*! Cree un nouvel objet Rationnel a partir des attributs de l'argument implicite.
  \return Une reference sur Constante.
  \sa Constante::GetVal()
*/
Constante& Rationnel::GetVal()const
{
    Constante* r = new Rationnel(num, den);
    return *r;
}

//! Surcharge de l'operateur de cast de Rationnel vers int.
Rationnel::operator int()const
{
    return num/den;
}

//! Surcharge de l'operateur de cast de Rationnel vers float.
Rationnel::operator float()const
{
    return (float)num/den;
}

//! Surcharge de l'operateur de cast de Rationnel vers Entier.
/*! \sa Entier */
Rationnel::operator Entier()const
{
    return Entier(num/den);
}

//! Surcharge de l'operateur de cast de Rationnel vers Rationnel.
Rationnel::operator Rationnel()const
{
    return *this;
}

//! Surcharge de l'operateur de cast de Rationnel vers Reel.
/*! \sa Reel */
Rationnel::operator Reel()const
{
    return Reel((float)num/den);
}

//! Surcharge de l'operateur de cast de Rationnel vers Complexe.
/*! \sa Compexe */
Rationnel::operator Complexe()const
{
    Rationnel* r = new Rationnel(num, den);
    Rationnel* zero = new Rationnel(0, 1);
    return Complexe(r, zero);
}

//! Surcharge de l'operateur d'addition entre deux Rationnel.
/*! A noter que l'on tente un dynamic cast sur l'argument qui est la seulement en cas d'un developpement futur
  car toutes nos operandes sont castees avant d'effectuer n'importe quelle operation.
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
*/
Constante& Rationnel::operator+(const Constante& c)const//ADAPTER A FAIRE
{
    try
    {
        const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
        if(r!=0)
        {
            Rationnel* res = new Rationnel(num*r->GetDen() + r->GetNum()*den, den*r->GetDen());
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

//! Surcharge de l'operateur de soustraction entre deux Rationnel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
*/
Constante& Rationnel::operator-(const Constante& c)const
{
    try
    {
        const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
        if(r!=0)
        {
            Rationnel* res = new Rationnel(num*r->GetDen() - r->GetNum()*den, den*r->GetDen());
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

//! Surcharge de l'operateur de multiplication entre deux Rationnel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
*/
Constante& Rationnel::operator*(const Constante& c)const
{
    try {
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel* res = new Rationnel(num*r->GetNum(), den*r->GetDen());
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

//! Surcharge de l'operateur de division entre deux Rationnel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
*/
Constante& Rationnel::operator/(const Constante& c)const
{
    try {
    const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
    if(r!=0)
    {
        Rationnel* res = new Rationnel(num*r->GetDen(), den*r->GetNum());
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

//! Surcharge de l'operateur de changement de signe d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
*/
Constante& Rationnel::operator-()const
{
    Rationnel* r = new Rationnel(-num, den);
    return *r;
}

//! Surcharge de l'operateur d'elevation a l'exposant entre deux Rationnel.
/*!
  \param c Une reference constante vers une Constante.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
  \sa <a href="http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Rationnel::operator^(const Constante& c)const
{
    try
    {
        const Rationnel* r = dynamic_cast<const Rationnel*>(&c);
        if(r!=0)
        {
            Rationnel* res = new Rationnel((int)pow((float)num, (float)(r->GetNum()/r->GetDen())), (int)pow((float)den, (float)(r->GetNum()/r->GetDen())));
            return *res;
        }
        else
            throw CalcException("L'opération d'elevation à l'exposant nécessite que les deux opérandes soient de même type");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Operation du calcul du sinus d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sin/">sin</a>
*/
Constante& Rationnel::sinus()const
{
    Reel* res = new Reel(sin((float)num/den));
    return *res;
}

//! Operation du calcul du cosinus d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/cos/">cos</a>
*/
Constante& Rationnel::cosinus()const
{
    Reel* res = new Reel(cos((float)num/den));
    return *res;
}

//! Operation du calcul de la tangente d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/tan/">tan</a>
*/
Constante& Rationnel::tangente()const
{
    Reel* res = new Reel(tan((float)num/den));
    return *res;
}

//! Operation du calcul du sinus hyperbolique d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sinh/">sinh</a>
*/
Constante& Rationnel::sinush()const
{
    Reel* res = new Reel(sinh((float)num/den));
    return *res;
}

//! Operation du calcul du cosinus hyperbolique d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/coh/">cosh</a>
*/
Constante& Rationnel::cosinush()const
{
    Reel* res = new Reel(cosh((float)num/den));
    return *res;
}

//! Operation du calcul de la tangente hyperbolique d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/tanh/">tanh</a>
*/
Constante& Rationnel::tangenteh()const
{
    Reel* res = new Reel(tanh((float)num/den));
    return *res;
}

//! Operation du calcul du logarithme decimal d'un Rationnel.
/*!
  On verifie que la valeur de l'argument implicite soit superieure a 0.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/log10/">log10</a>
*/
Constante& Rationnel::logdec()const
{
    try {
    if((num>0 && den>0) || (num<=0 && den<=0))
    {
        Reel* res = new Reel(log10((float)num/den));
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

//! Operation du calcul du logarithme neperien d'un Entier.
/*!
  On verifie que la valeur de l'argument implicite soit superieure a 0.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/log/">log</a>
*/
Constante& Rationnel::lognep()const
{

    try
    {
        if((num>0 && den>0) || (num<=0 && den<=0))
        {
            Reel* res = new Reel(log((float)num/den));
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

//! Operation du calcul de l'inverse d'un Entier.
/*!
  On verifie que le numerateur de l'argument implicite soit differente de 0.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
*/
Constante& Rationnel::inverse()const
{
    try
    {
        if(num!=0)
        {
            Rationnel* res = new Rationnel(den, num);
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

//! Operation du calcul de la racine carree d'un Rationnel.
/*!
  On verifie que la valeur de l'argument implicite soit superieure ou egale a 0.
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa CalcException
  \sa Reel
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/sqrt/">sqrt</a>
*/
Constante& Rationnel::racine()const
{
    try
    {
        if((num>0 && den>0) || (num<=0 && den<=0))
        {
            Reel* res = new Reel(sqrt((float)num/den));
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

//! Operation du calcul du carre d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Rationnel::carree()const
{
    Rationnel* res = new Rationnel((int)pow((float)num,2), (int)pow((float)den,2));
    return *res;
}

//! Operation du calcul du cube d'un Rationnel.
/*!
  \return Une reference sur une Constante contenant notre nouveau Rationnel.
  \sa <a href = "http://www.cplusplus.com/reference/clibrary/cmath/pow/">pow</a>
*/
Constante& Rationnel::cube()const
{
    Rationnel* res = new Rationnel((int)pow((float)num,3), (int)pow((float)den,3));
    return *res;
}

//! Surcharge de l'operateur de cast de Rationnel vers QString.
/*!
  On cree un QTextStream avec une QString initialement vide auquel on ajoute le numerateur ainsi que le denominateur de l'argument implicite separees du signe '/'.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/qtextstream.html">QTextStream</a>
*/
Rationnel::operator QString()
{
    QString str;
    QTextStream tx(&str);
    tx << num << '/' << den ;
    return str;
}
