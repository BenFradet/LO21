#include "complexe.h"
#include <QTextStream>

//! Un autre constructeur de la classe Complexe.
/*! Constuit un objet Complexe a l'aide d'une reference sur QString ainsi que le mode dans lequel notre calculatrice se trouve.
  On separe s par rapport au '$', ensuite on cree un objet de type mode pour la partie reelle ainsi que la partie imaginaire.
  \param s Une reference sur une QString representant le Complexe.
  \param mode Une QString designant le mode de la calculatrice.
*/
Complexe::Complexe(QString &s, QString mode)
{
    QStringList list = s.split("$");
    pRe = ConstanteFactory::GetConstante(list[0], mode);
    pIm = ConstanteFactory::GetConstante(list[1], mode);
}

Constante& Complexe::GetVal()const
{
    Complexe* c = new Complexe(pRe, pIm);
    return *c;
}

Complexe::operator int()const
{
    return (int)*pRe;
}

Complexe::operator float()const
{
    return (float)*pRe;
}

Complexe::operator Entier()const
{
    return Entier((int)*pRe);
}

Complexe::operator Rationnel()const
{
    return Rationnel((int)*pRe, 1);
}

Complexe::operator Reel()const
{
    return Reel((float)*pRe);
}

Complexe::operator Complexe()const
{
    return *this;
}

//! Surcharge de l'operateur d'addition entre deux complexes
/*! On additionne les 2 parties reelles ainsi que les 2 parties imaginaires et on cree un nouveau Complexe avec ces valeurs.
  A noter que l'on tente un dynamic cast sur l'argument qui est la seulement en cas d'un developpement futur
  car toutes nos operandes sont castees avant d'effectuer n'importe quelle operation.
  \param c Une reference constante vers une Constante
  \return On retourne une reference sur une Constante contenant notre Complexe
*/
Constante& Complexe::operator+(const Constante& c)const
{
    try
    {
        const Complexe* co = dynamic_cast<const Complexe*>(&c);
        if(co!=0)
        {
            if(MainWindow::getMode() == "Entier")
            {
                Complexe* res = new Complexe(&((Entier)*pRe + (Entier)*(co->GetRe())), &((Entier)*pIm + (Entier)*(co->GetIm())));
                return *res;
            }
            else if(MainWindow::getMode() == "Reel")
            {
                Complexe* res = new Complexe(&((Reel)*pRe + (Reel)*(co->GetRe())), &((Reel)*pIm + (Reel)*(co->GetIm())));
                return *res;
            }
            else
            {
                Complexe* res = new Complexe(&((Rationnel)*pRe + (Rationnel)*(co->GetRe())), &((Rationnel)*pIm + (Rationnel)*(co->GetIm())));
                return *res;
            }
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

//! Surcharge de l'operateur de soustraction entre deux complexes
/*! On soustrait les 2 parties reelles ainsi que les 2 parties imaginaires et on cree un nouveau Complexe avec ces valeurs.
  \param c Une reference constante vers une Constante
  \return On retourne une reference sur une Constante contenant notre Complexe
*/
Constante& Complexe::operator-(const Constante& c)const
{
    try
    {
        const Complexe* co = dynamic_cast<const Complexe*>(&c);
        if(co!=0)
        {
            if(MainWindow::getMode() == "Entier")
            {
                Complexe* res = new Complexe(&((Entier)*pRe - (Entier)*(co->GetRe())), &((Entier)*pIm - (Entier)*(co->GetIm())));
                return *res;
            }
            else if(MainWindow::getMode() == "Reel")
            {
                Complexe* res = new Complexe(&((Reel)*pRe - (Reel)*(co->GetRe())), &((Reel)*pIm - (Reel)*(co->GetIm())));
                return *res;
            }
            else
            {
                Complexe* res = new Complexe(&((Rationnel)*pRe - (Rationnel)*(co->GetRe())), &((Rationnel)*pIm - (Rationnel)*(co->GetIm())));
                return *res;
            }
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

//! Surcharge de l'operateur de multiplication entre deux complexes
/*!
  \param c Une reference constante vers une Constante
  \return On retourne une reference sur une Constante contenant notre Complexe
*/
Constante& Complexe::operator*(const Constante& c)const
{
    try
    {
        const Complexe* co = dynamic_cast<const Complexe*>(&c);
        if(co!=0)
        {
            if(MainWindow::getMode() == "Entier")
            {
                Complexe* res = new Complexe(&((Entier)*pRe*((Entier)*(co->GetRe()))-(Entier)*pIm*((Entier)*(co->GetIm()))),
                                             &((Entier)*pRe*((Entier)*(co->GetIm()))+(Entier)*pIm*((Entier)*(co->GetRe()))));
                return *res;
            }
            else if(MainWindow::getMode() == "Reel")
            {
                Complexe* res = new Complexe(&((Reel)*pRe*((Reel)*(co->GetRe()))-(Reel)*pIm*((Reel)*(co->GetIm()))),
                                             &((Reel)*pRe*((Reel)*(co->GetIm()))+(Reel)*pIm*((Reel)*(co->GetRe()))));
                return *res;
            }
            else
            {
                Complexe* res = new Complexe(&((Rationnel)*pRe*((Rationnel)*(co->GetRe()))-(Rationnel)*pIm*((Rationnel)*(co->GetIm()))),
                                             &((Rationnel)*pRe*((Rationnel)*(co->GetIm()))+(Rationnel)*pIm*((Rationnel)*(co->GetRe()))));
                return *res;
            }
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

//! Surcharge de l'operateur de division entre deux complexes
/*!
  \param c Une reference constante vers une Constante
  \return On retourne une reference sur une Constante contenant notre Complexe
*/
Constante& Complexe::operator/(const Constante& c)const
{
    try
    {
        const Complexe* co = dynamic_cast<const Complexe*>(&c);
        if(co!=0)
        {
            if(MainWindow::getMode() == "Entier")
            {
                Complexe* res = new Complexe(&(((Entier)*pRe * (Entier)*(co->GetRe()) + (Entier)*pIm * (Entier)*(co->GetIm())) /
                                               ((Entier)*co->GetRe() * (Entier)*co->GetRe() + (Entier)*co->GetIm() * (Entier)*co->GetIm())),
                                             &(((Entier)*pIm * (Entier)*(co->GetRe()) - (Entier)*pRe * (Entier)*(co->GetIm())) /
                                               ((Entier)*co->GetRe() * (Entier)*co->GetRe() + (Entier)*co->GetIm() * (Entier)*co->GetIm())));
                return *res;
            }
            if(MainWindow::getMode() == "Reel")
            {
                Complexe* res = new Complexe(&(((Reel)*pRe * (Reel)*(co->GetRe()) + (Reel)*pIm * (Reel)*(co->GetIm())) /
                                               ((Reel)*co->GetRe() * (Reel)*co->GetRe() + (Reel)*co->GetIm() * (Reel)*co->GetIm())),
                                             &(((Reel)*pIm * (Reel)*(co->GetRe()) - (Reel)*pRe * (Reel)*(co->GetIm())) /
                                               ((Reel)*co->GetRe() * (Reel)*co->GetRe() + (Reel)*co->GetIm() * (Reel)*co->GetIm())));
                return *res;
            }
            else
            {
                Complexe* res = new Complexe(&(((Rationnel)*pRe * (Rationnel)*(co->GetRe()) + (Rationnel)*pIm * (Rationnel)*(co->GetIm())) /
                                               ((Rationnel)*co->GetRe() * (Rationnel)*co->GetRe() + (Rationnel)*co->GetIm() * (Rationnel)*co->GetIm())),
                                             &(((Rationnel)*pIm * (Rationnel)*(co->GetRe()) - (Rationnel)*pRe * (Rationnel)*(co->GetIm())) /
                                               ((Rationnel)*co->GetRe() * (Rationnel)*co->GetRe() + (Rationnel)*co->GetIm() * (Rationnel)*co->GetIm())));
                return *res;
            }
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

//! Surcharge de l'operateur de changement de signe d'un complexe
/*!
  \return On retourne une reference sur une Constante contenant notre Complexe
*/
Constante& Complexe::operator-()const
{
    if(MainWindow::getMode() == "Entier")
    {
        Complexe* c = new Complexe(&(-(Entier)*pRe), &(-(Entier)*pIm));
        return *c;
    }
    else if(MainWindow::getMode() == "Reel")
    {
        Complexe* c = new Complexe(&(-(Reel)*pRe), &(-(Reel)*pIm));
        return *c;
    }
    else
    {
        Complexe* c = new Complexe(&(-(Rationnel)*pRe), &(-(Rationnel)*pIm));
        return *c;
    }
}

Constante& Complexe::carree()const
{
    Entier* e = new Entier(0);//à implémenter
    return *e;
}

Constante& Complexe::cube()const
{
    Entier* e = new Entier(0);//à implémenter
    return *e;
}

Complexe::operator QString()
{
    QString str;
    QTextStream tx(&str);
    tx << (QString)*pRe <<"$"<< (QString)*pIm;
    return str;
}
