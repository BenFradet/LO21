#include "complexe.h"
#include <QTextStream>

Complexe::Complexe(QString &s, QString mode)
{
    QStringList list = s.split("$");
    pRe = ConstanteFactory::GetConstante(list[0], mode);
    pIm = ConstanteFactory::GetConstante(list[1], mode);
}

Constante& Complexe::GetVal()const
{
    Complexe c(pRe, pIm);
    return c;
}

Complexe::operator int()const
{
    //exception
    return 0;
}

Complexe::operator float()const
{
    //exception
    return 0;
}

Complexe::operator Entier()const
{
    //exception
    return Entier(0);
}

Complexe::operator Rationnel()const
{
    //exception
    return Rationnel(0,1);
}

Complexe::operator Reel()const
{
    //exception
    return Reel(0);
}

Complexe::operator Complexe()const
{
    return *this;
}

Constante& Complexe::operator+(const Constante& c)const
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

Constante& Complexe::operator-(const Constante& c)const
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

Constante& Complexe::operator*(const Constante& c)const
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

Constante& Complexe::operator/(const Constante& c)const
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

Constante& Complexe::operator-()const
{
    if(MainWindow::getMode() == "Entier")
    {
        Complexe* c = new Complexe(&((Entier)*pRe - Entier(2)*((Entier)*pRe)), &((Entier)*pIm-Entier(2)*((Entier)*pIm)));
        return *c;
    }
    else if(MainWindow::getMode() == "Reel")
    {
        Complexe* c = new Complexe(&((Reel)*pRe - (Reel)Entier(2)*((Reel)*pRe)), &((Reel)*pIm-(Reel)Entier(2)*((Reel)*pIm)));
        return *c;
    }
    else
    {
        Complexe* c = new Complexe(&((Rationnel)*pRe - (Rationnel)Entier(2)*((Rationnel)*pRe)), &((Rationnel)*pIm-(Rationnel)Entier(2)*((Rationnel)*pIm)));
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
