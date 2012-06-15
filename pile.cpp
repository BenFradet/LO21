#include "pile.h"

Mementos* Mementos::instance1 = 0;
Mementos* Mementos::instance2 = 0;

Mementos& Mementos::getInstance1(int dim)
{
    if(instance1 == 0)
        instance1 = new Mementos(dim);
    return *instance1;
}

void Mementos::releaseInstance1()
{
    if(instance1 != 0)
        delete instance1;
    instance1 = 0;
}

Mementos& Mementos::getInstance2(int dim)
{
    if(instance2 == 0)
        instance2 = new Mementos(dim);
    return *instance2;
}

void Mementos::releaseInstance2()
{
    if(instance2 != 0)
        delete instance2;
    instance2 = 0;
}

Mementos::Mementos(int dim)
{
    taille = dim;
    sommet = 0;
    mementos = new Memento*[taille]();
}

Mementos::~Mementos()
{
    delete[] mementos;
}

void Mementos::Empiler(Memento* m)
{
    try
    {
        if(sommet == taille)
            throw CalcException("La pile de memento est pleine !");
        else
            mementos[sommet++] = m;
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Memento* Mementos::Depiler()
{
    try
    {
        if(sommet == 0)
            throw CalcException("La pile de memento est vide !");
        else
            return mementos[--sommet];
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Memento* Mementos::Tete()const
{
    try
    {
        if(sommet == 0)
            throw CalcException("La pile est vide !");
        else
            return mementos[sommet-1];
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Mementos::Clear()
{
    sommet = 0;
}

Pile* Pile::instance = 0;

Pile& Pile::getInstance(int dim)
{
    if(instance == 0)
        instance = new Pile(dim);
    return *instance;
}

void Pile::releaseInstance()
{
    if(instance != 0)
        delete instance;
    instance = 0;
}

//! Constructeur prive de la classe Pile.
/*! On initialise l'attribut sommet a 0.
  On cree dynamiquement un tableau de Constante ainsi que deux pointeurs sur des objets Mementos.
  \param dim La taille de la Pile.
  \sa Mementos::Mementos(int dim)
*/
Pile::Pile(int dim)
{
    taille = dim;
    sommet = 0;
    tabElmt = new Constante*[taille]();
    undos = new Mementos(50);
    redos = new Mementos(50);
}

//! Destructeur prive de la classe Pile.
/*! On detruit le tableau creee dynamiquement dans le constructeur ainsi que les deux pointeurs sur des objets Mementos.
  \sa Pile(int dim)
*/
Pile::~Pile()
{
    delete[] tabElmt;
    delete undos;
    delete redos;
}

//! Methode permettant l'ajout d'une Constante a un objet Pile.
/*! A noter qu'a chaque empilement on cree un Memento et on ecrit des Log.
    \sa createMemento()
    \sa Log::WriteLogs(QString string)
    \sa CalcException
    \param c Un pointeur sur une Constante.
*/
void Pile::Empiler(Constante* c)
{
    try
    {
        if(sommet == taille)
            throw CalcException("Impossible d'empiler, la pile est pleine.");
        else
        {
            createMemento();
            Log::WriteLogs("Empilement de:" + (QString)*c);
            tabElmt[sommet++] = c;
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant la suppression d'une Constante de la Pile.
/*! \return Un pointeur sur une Constante.
    \sa Log::WriteLogs(QString string)
    \sa CalcException
*/
Constante* Pile::Depiler()
{
    try
    {
        if(sommet == 0)
            throw CalcException("La pile est vide !");
        else
        {
            Log::WriteLogs("Dépilement de:" + (QString)*tabElmt[sommet-1]);
            return tabElmt[--sommet];
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de renvoyer l'element au sommet de la Pile.
/*! \return Un pointeur sur une Constante.
    \sa Log::WriteLogs(QString string)
    \sa CalcException
*/
Constante* Pile::Tete()const
{
    try
    {
        if(sommet == 0)
            throw CalcException("La pile est vide !");
        else
        {
            Log::WriteLogs("Renvoi de la tête:" + (QString)*tabElmt[sommet-1]);
            return tabElmt[sommet-1];
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de vider la Pile.
/*!
    \sa createMemento()
    \sa Log::WriteLogs(QString string)
*/
void Pile::Clear()
{
    createMemento();
    Log::WriteLogs("Clear de la pile");
    sommet = 0;
}

//! Methode permettant de dupliquer l'element se trouvant au sommet de la Pile.
/*!
    \sa createMemento()
    \sa Log::WriteLogs(QString string)
    \sa CalcException
*/
void Pile::Dup()
{
   try
    {
        if(sommet == taille)
            throw CalcException("La pile est pleine, il faut l'agrandir avant de dupliquer.");
        else if (sommet == 0)
            throw CalcException("Il n'y aucun élément à dupliquer !");
        else
        {
            createMemento();
            Constante* tmp = tabElmt[sommet-1];
            Log::WriteLogs("Duplication de:" + (QString)*tmp);
            tabElmt[sommet++] = tmp;
        }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de supprimer l'element se trouvant au sommet de la Pile.
/*!
    \sa createMemento()
    \sa Log::WriteLogs(QString string)
    \sa CalcException
*/
void Pile::Drop()
{
    try
    {
        if (sommet != 0)
        {
            createMemento();
            Log::WriteLogs("Drop de:" + (QString)*tabElmt[sommet-1]);
            sommet--;
        }
        else
            throw CalcException("La pile est vide ! Vous ne pouvez pas retirer d'éléments !");
    }
    catch (CalcException c)
    {
        c.alert();
    }

}

//! Methode permettant de creer un Memento a un instant donne.
/*!
  \sa Memento::Memento(int dim, int top, Constante** pt)
  \sa Mementos::Empiler(Memento* m)
*/
void Pile::createMemento()const
{
    Memento* m = new Memento(taille, sommet, tabElmt);
    undos->Empiler(m);
}

//! Methode permettant de remplir le Mementos de retablissements a chaque annulation.
/*!
  \sa Memento::Memento(int dim, int top, Constante** pt)
  \sa Mementos::Empiler(Memento* m)
*/
void Pile::retrieveMemento()const
{
    Memento* m = new Memento(taille, sommet, tabElmt);
    redos->Empiler(m);
}

//! Methode permettant l'annulation d'une action de l'utilisateur
/*!
  \sa Log::WriteLogs(QString string)
  \sa Mementos::Depiler()
  \sa retrieveMemento()
*/
void Pile::Annuler()
{
    Log::WriteLogs("Annulation");
    Memento* m = undos->Depiler();
    retrieveMemento();
    taille = m->taille;
    sommet = m->sommet;
    tabElmt = m->tabElmt;
}

//! Methode permettant de retablir une annulation de l'utilisateur
/*!
  \sa Log::WriteLogs(QString string)
  \sa Mementos::Depiler()
*/
void Pile::Retablir()
{
    Log::WriteLogs("Rétablissement");
    Memento* m = redos->Depiler();
    taille = m->taille;
    sommet = m->sommet;
    tabElmt = m->tabElmt;
}

//! Methode permettant d'ajouter les 2 dernieres Constante de la Pile.
/*!
  On convertit a chaque fois ces 2 dernieres Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
  \sa ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Expression
  \sa Rationnel
  \sa Reel
*/
void Pile::Plus(QString mode, bool complexe)
{
    try
    {
        if(sommet>=2)
        {
            Constante* a = this->Depiler();
            Constante* b = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Expression* e2 = dynamic_cast<const Expression*>(b);
            if(e1 != 0 || e2 != 0)
            {
                if(e1 != 0 && e2 != 0)
                {
                    Constante* e = ExpressionFactory::GetExpressionBinaire2Exp((QString)*a, (QString)*b, "+");
                    Empiler(e);
                }
                else
                {
                    if(e2 != 0)
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*b, (QString)*a, "+");
                        Empiler(e);
                    }
                    else
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*a, (QString)*b, "+");
                        Empiler(e);
                    }
                }
            }
            else
            {
                if(complexe == true)
                {
                    Constante& tmp = (Complexe)*b + (Complexe)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Ajout de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
                else
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = (Entier)*b + (Entier)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Ajout de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = (Rationnel)*b + (Rationnel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Ajout de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = (Reel)*b + (Reel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Ajout de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite deux opérandes !");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de soustraire les 2 dernieres Constante de la Pile.
/*!
  On convertit a chaque fois ces 2 dernieres Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
  \sa ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Expression
  \sa Rationnel
  \sa Reel
*/
void Pile::Moins(QString mode, bool complexe)
{
    try
    {
        if(sommet>=2)
        {
            Constante* a = this->Depiler();
            Constante* b = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Expression* e2 = dynamic_cast<const Expression*>(b);
            if(e1 != 0 || e2 != 0)
            {
                if(e1 != 0 && e2 != 0)
                {
                    Constante* e = ExpressionFactory::GetExpressionBinaire2Exp((QString)*a, (QString)*b, "-");
                    Empiler(e);
                }
                else
                {
                    if(e2 != 0)
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*b, (QString)*a, "-");
                        Empiler(e);
                    }
                    else
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*a, (QString)*b, "-");
                        Empiler(e);
                    }
                }
            }
            else
            {
                if(complexe == false)
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = (Entier)*b - (Entier)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Soustraction de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = (Rationnel)*b - (Rationnel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Soustraction de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = (Reel)*b - (Reel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Soustraction de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                }
                else
                {
                    Constante& tmp = (Complexe)*b - (Complexe)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Soustraction de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite deux opérandes !");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de multiplier les 2 dernieres Constante de la Pile.
/*!
  On convertit a chaque fois ces 2 dernieres Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
  \sa ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Expression
  \sa Rationnel
  \sa Reel
*/
void Pile::Multiplier(QString mode, bool complexe)
{
    try
    {
        if(sommet>=2)
        {
            Constante* a = this->Depiler();
            Constante* b = this->Depiler();

            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Expression* e2 = dynamic_cast<const Expression*>(b);
            if(e1 != 0 || e2 != 0)
            {
                if(e1 != 0 && e2 != 0)
                {
                    Constante* e = ExpressionFactory::GetExpressionBinaire2Exp((QString)*a, (QString)*b, "*");
                    Empiler(e);
                }
                else
                {
                    if(e2 != 0)
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*b, (QString)*a, "*");
                        Empiler(e);
                    }
                    else
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*a, (QString)*b, "*");
                        Empiler(e);
                    }
                }
            }
            else
            {
                if(complexe == false)
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = (Entier)*b * (Entier)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = (Rationnel)*b * (Rationnel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = (Reel)*b * (Reel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                }
                else
                {
                    Constante& tmp = (Complexe)*b * (Complexe)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de diviser les 2 dernieres Constante de la Pile.
/*!
  On convertit a chaque fois ces 2 dernieres Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
  \sa ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Expression
  \sa Rationnel
  \sa Reel
*/
void Pile::Diviser(QString mode, bool complexe)
{
    try
    {
        if(sommet>=2)
        {
            Constante* a = this->Depiler();
            Constante* b = this->Depiler();

            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Expression* e2 = dynamic_cast<const Expression*>(b);
            if(e1 != 0 || e2 != 0)
            {
                if(e1 != 0 && e2 != 0)
                {
                    Constante* e = ExpressionFactory::GetExpressionBinaire2Exp((QString)*a, (QString)*b, "/");
                    Empiler(e);
                }
                else
                {
                    if(e2 != 0)
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*b, (QString)*a, "/");
                        Empiler(e);
                    }
                    else
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*a, (QString)*b, "/");
                        Empiler(e);
                    }
                }
            }
            else
            {
                if(complexe == false)
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = (Entier)*b / (Entier)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, "Rationnel", complexe);
                        Log::WriteLogs("Division de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = (Rationnel)*b / (Rationnel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = (Reel)*b / (Reel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                        Empiler(c);
                    }
                }
                else
                {
                    Constante& tmp = (Complexe)*b / (Complexe)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Multiplication de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant d'elever a l'exposant les 2 dernieres Constante de la Pile.
/*!
  On convertit a chaque fois ces 2 dernieres Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
  \sa ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Entier
  \sa Expression
  \sa Rationnel
  \sa Reel
*/
void Pile::Puissance(QString mode)
{
   try
    {
        if(sommet>=2)
        {
            Constante* a = this->Depiler();
            Constante* b = this->Depiler();

            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Expression* e2 = dynamic_cast<const Expression*>(b);
            if(e1 != 0 || e2 != 0)
            {
                if(e1 != 0 && e2 != 0)
                {
                    Constante* e = ExpressionFactory::GetExpressionBinaire2Exp((QString)*a, (QString)*b, "^");
                    Empiler(e);
                }
                else
                {
                    if(e2 != 0)
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*b, (QString)*a, "^");
                        Empiler(e);
                    }
                    else
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*a, (QString)*b, "^");
                        Empiler(e);
                    }
                }
            }
            else
            {
                if(mode == "Entier")
                {
                    Constante& tmp = (Entier)*b ^ (Entier)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode);
                    Log::WriteLogs("Puissance de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
                else if(mode == "Rationnel")
                {
                    Constante& tmp = (Rationnel)*b ^ (Rationnel)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode);
                    Log::WriteLogs("Puissance de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
                else if(mode == "Reel")
                {
                    Constante& tmp = (Reel)*b ^ (Reel)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode);
                    Log::WriteLogs("Puissance de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }


}

//! Methode permettant de calculer le modulo des 2 dernieres Constante de la Pile.
/*!
  On convertit a chaque fois ces 2 dernieres Constante vers des Entier.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionBinaire2Exp(QString val1, QString val2, QString operation)
  \sa ExpressionFactory::GetExpressionBinaire1Exp(QString exp, QString cons, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Entier
  \sa Expression
*/
void Pile::Modulo(QString mode)
{
    try
    {
        if(sommet>=2)
        {
            Constante* a = this->Depiler();
            Constante* b = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Expression* e2 = dynamic_cast<const Expression*>(b);
            if(e1 != 0 || e2 != 0)
            {
                if(e1 != 0 && e2 != 0)
                {
                    Constante* e = ExpressionFactory::GetExpressionBinaire2Exp((QString)*a, (QString)*b, "%");
                    Empiler(e);
                }
                else
                {
                    if(e2 != 0)
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*b, (QString)*a, "%");
                        Empiler(e);
                    }
                    else
                    {
                        Constante* e = ExpressionFactory::GetExpressionBinaire1Exp((QString)*a, (QString)*b, "%");
                        Empiler(e);
                    }
                }
            }
            else
            {
                if(mode == "Entier")
                {
                    Constante* c = new Entier((Entier)*b % (Entier)*a);
                    Log::WriteLogs("Modulo de:" + (QString)*b + " et " + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de changer le signe de la derniere Constante de la Pile.
/*!
  On convertit a chaque fois cette derniere Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Expression
  \sa Rationnel
  \sa Reel
*/
void Pile::Signe(QString mode, bool complexe)
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "SIGN");
                Empiler(e);
            }
            else
            {
                if(complexe == false)
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = -(Entier)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Inversion du signe de:" + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = -(Rationnel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Inversion du signe de:" + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = -(Reel)*a;
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Inversion du signe de:" + (QString)*a);
                        Empiler(c);
                    }
                }
                else
                {
                    Constante& tmp = -(Complexe)*a;
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Inversion du signe de:" + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le sinus de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa MainWindow::getAngleMode()
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Sinus()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "SIN");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération de trigonométrie sur un Complexe");
            }
            else
            {
                if(MainWindow::getAngleMode() == "Radian")
                {
                    Constante* res = new Reel(a->sinus());
                    Log::WriteLogs("Sinus en radian de:" + (QString)*a);
                    Empiler(res);
                }
                else
                {
                    float f = 3.141592/180;
                    Constante* tmp = new Reel(f);
                    Constante& tmp2 = (Reel)*tmp * (Reel)*a;
                    Constante* res = new Reel(tmp2.sinus());
                    Log::WriteLogs("Sinus en degré de:" + (QString)*a);
                    Empiler(res);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le cosinus de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa MainWindow::getAngleMode()
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Cosinus()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "COS");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération de trigonométrie sur un Complexe");
            }
            else
            {
                if(MainWindow::getAngleMode() == "Radian")
                {
                    Constante* res = new Reel(a->cosinus());
                    Log::WriteLogs("Cosinus en radian de:" + (QString)*a);
                    Empiler(res);
                }
                else
                {
                    float f = 3.141592/180;
                    Constante* tmp = new Reel(f);
                    Constante& tmp2 = (Reel)*tmp * (Reel)*a;
                    Constante* res = new Reel(tmp2.cosinus());
                    Log::WriteLogs("Cosinus en degré de:" + (QString)*a);
                    Empiler(res);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer la tangente de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa MainWindow::getAngleMode()
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Tangente()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "TAN");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération de trigonométrie sur un Complexe");
            }
            else
            {
               if(MainWindow::getAngleMode() == "Radian")
                {
                    Constante* res = new Reel(a->tangente());
                    Log::WriteLogs("Tangente en radian de:" + (QString)*a);
                    Empiler(res);
                }
                else
                {
                    float f = 3.141592/180;
                    Constante* tmp = new Reel(f);
                    Constante& tmp2 = (Reel)*tmp * (Reel)*a;
                    Constante* res = new Reel(tmp2.tangente());
                    Log::WriteLogs("Tangente en degré de:" + (QString)*a);
                    Empiler(res);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le sinus hyperbolique de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa MainWindow::getAngleMode()
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Sinush()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "SINH");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération de trigonométrie sur un Complexe");
            }
            else
            {
                if(MainWindow::getAngleMode() == "Radian")
                {
                    Constante* res = new Reel(a->sinush());
                    Log::WriteLogs("Sinus hyperbolique en radian de:" + (QString)*a);
                    Empiler(res);
                }
                else
                {
                    float f = 3.141592/180;
                    Constante* tmp = new Reel(f);
                    Constante& tmp2 = (Reel)*tmp * (Reel)*a;
                    Constante* res = new Reel(tmp2.sinush());
                    Log::WriteLogs("Sinus hyperbolique en degré de:" + (QString)*a);
                    Empiler(res);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le cosinus hyperbolique de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa MainWindow::getAngleMode()
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Cosinush()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "COSH");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération de trigonométrie sur un Complexe");
            }
            else
            {
                if(MainWindow::getAngleMode() == "Radian")
                {
                    Constante* res = new Reel(a->cosinush());
                    Log::WriteLogs("Cosinus hyperbolique en radian de:" + (QString)*a);
                    Empiler(res);
                }
                else
                {
                    float f = 3.141592/180;
                    Constante* tmp = new Reel(f);
                    Constante& tmp2 = (Reel)*tmp * (Reel)*a;
                    Constante* res = new Reel(tmp2.cosinush());
                    Log::WriteLogs("Cosinus hyperbolique en radian de:" + (QString)*a);
                    Empiler(res);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer la tangente hyperbolique de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa MainWindow::getAngleMode()
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Tangenteh()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "TANH");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération de trigonométrie sur un Complexe");
            }
            else
            {
                if(MainWindow::getAngleMode() == "Radian")
                {
                    Constante* res = new Reel(a->tangenteh());
                    Log::WriteLogs("Tangente hyperbolique en radian de:" + (QString)*a);
                    Empiler(res);
                }
                else
                {
                    float f = 3.141592/180;
                    Constante* tmp = new Reel(f);
                    Constante& tmp2 = (Reel)*tmp * (Reel)*a;
                    Constante* res = new Reel(tmp2.tangenteh());
                    Log::WriteLogs("Tangente hyperbolique en radian de:" + (QString)*a);
                    Empiler(res);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le logarithme neperien de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::LogaNep()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "LN");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération logarithmique sur un Complexe");
            }
            else
            {
                Constante* res = new Reel(a->lognep());
                Log::WriteLogs("Logarithme néperien de:" + (QString)*a);
                Empiler(res);
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le logarithme decimal de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::LogaDec()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "LOG");
                Empiler(e);
            }
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer une opération logarithmique sur un Complexe");
            }
            else
            {
                Constante* res = new Reel(a->logdec());
                Log::WriteLogs("Logarithme décimal de:" + (QString)*a);
                Empiler(res);
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer l'inverse de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa Expression
*/
void Pile::Inverse()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "INV");
                Empiler(e);
            }
            else
            {
                Constante* res = &a->inverse();
                Log::WriteLogs("Inverse de:" + (QString)*a);
                Empiler(res);
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer la racine carree de la derniere Constante de la Pile.
/*!
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Racine()
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            const Complexe* c = dynamic_cast<const Complexe*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "SQRT");
                Empiler(e);
            }            
            else if(c!=0)
            {
                throw CalcException("Impossible d'effectuer la racine carree d'un Complexe");
            }
            else
            {
                Constante* res = new Reel(a->racine());
                Log::WriteLogs("Racine carrée de:" + (QString)*a);
                Empiler(res);
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le carre de la derniere Constante de la Pile.
/*!
  On convertit a chaque fois cette derniere Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Carree(QString mode, bool complexe)
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "SQR");
                Empiler(e);
            }
            else
            {
                if(complexe == false)
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = (Entier)a->carree();
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Carré de:" + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = (Rationnel)a->carree();
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Carré de:" + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = (Reel)a->carree();
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Carré de:" + (QString)*a);
                        Empiler(c);
                    }
                }
                else
                {
                    Constante& tmp = (Complexe)a->carree();
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Carré de:" + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer le cube de la derniere Constante de la Pile.
/*!
  On convertit a chaque fois cette derniere Constante dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \sa Depiler()
  \sa Empiler()
  \sa ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Expression
  \sa Reel
*/
void Pile::Cube(QString mode, bool complexe)
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "CUBE");
                Empiler(e);
            }
            else
            {
                if(complexe == false)
                {
                    if(mode == "Entier")
                    {
                        Constante& tmp = (Entier)a->cube();
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Cube de:" + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Rationnel")
                    {
                        Constante& tmp = (Rationnel)a->cube();
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Cube de:" + (QString)*a);
                        Empiler(c);
                    }
                    else if(mode == "Reel")
                    {
                        Constante& tmp = (Reel)a->cube();
                        Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                        Log::WriteLogs("Cube de:" + (QString)*a);
                        Empiler(c);
                    }
                }
                else
                {
                    Constante& tmp = (Complexe)a->cube();
                    Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
                    Log::WriteLogs("Cube de:" + (QString)*a);
                    Empiler(c);
                }
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant de calculer la factorielle de la derniere Constante de la Pile.
/*!
  On convertit a chaque fois cette derniere Constante vers des Entier.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \sa Depiler()
  \sa Empiler()
  \sa ExpressionFactory::GetExpressionUnaire(QString val, QString operation)
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Entier
  \sa Expression
*/
void Pile::Factorielle(QString mode)
{
    try
    {
        if(sommet>=1)
        {
            Constante* a = this->Depiler();
            const Expression* e1 = dynamic_cast<const Expression*>(a);
            if(e1!=0)
            {
                Constante* e = ExpressionFactory::GetExpressionUnaire((QString)*a, "!");
                Empiler(e);
            }
            else
            {
                if(mode == "Entier")
                {
                    Constante* res = new Entier(!(Entier)*a);
                    Log::WriteLogs("Factorielle de:" + (QString)*a);
                    Empiler(res);
                }
                else
                    throw CalcException("Cette opération nécessite d'être en mode entier");
            }
        }
        else
            throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant d'intervertir 2 elements dans la Pile.
/*!
  \param x Un entier designant la place du premier element a echanger.
  \param y Un entier designant la place du second element a echanger.
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
*/
void Pile::Swap(int x, int y)
{
    try
    {
        if(sommet>x-1 && sommet>y-1)
        {
            Constante* tmp;
            tmp = tabElmt[x-1];
            tabElmt[x-1] = tabElmt[y-1];
            tabElmt[y-1] = tmp;
            Log::WriteLogs("Swap de:" + (QString)*tabElmt[x-1] + " et " + (QString)*tabElmt[y-1]);
        }
        else
            throw CalcException("Les indices doivent être dans la pile");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant d'effectuer la somme des x derniers elements de la Pile.
/*! On convertit chacune des Constante parcourues dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \param x Un entier designant le nombre d'elements a sommer.
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Rationnel
  \sa Reel
*/
void Pile::Sum(int x, QString mode, bool complexe)
{
    try
    {
        if(x-1<sommet && x-1>=0)
        {
            if(complexe == true)
            {
                Entier* zero = new Entier(0);
                Complexe* c = new Complexe(zero, zero);
                for(int i = 0; i<=x-1; i++)
                    *c = *c + (Complexe)**(tabElmt + sommet - 1 - i);
                Log::WriteLogs("Somme des:" + (QString)Entier(x) + " premiers éléments de la pile");
                Empiler(c);
            }
            else
            {
                if(mode == "Entier")
                {
                    Entier* e = new Entier(0);
                    for(int i = 0; i<=x-1; i++)
                        *e = *e + (Entier)**(tabElmt + sommet - 1 - i);
                    Log::WriteLogs("Somme des:" + (QString)Entier(x) + " premiers éléments de la pile");
                    Empiler(e);
                }
                else if(mode == "Rationnel")
                {
                    Rationnel* r = new Rationnel(0, 1);
                    for(int i = 0; i<x-1; i++)
                        *r = *r + (Rationnel)**(tabElmt + sommet - 1 - i);
                    Log::WriteLogs("Somme des:" + (QString)Entier(x) + " premiers éléments de la pile");
                    Empiler(r);
                }
                else if(mode == "Reel")
                {
                    Reel* r = new Reel(0);
                    for(int i = 0; i<x-1; i++)
                        *r = *r + (Reel)**(tabElmt + sommet - 1 - i);
                    Log::WriteLogs("Somme des:" + (QString)Entier(x) + " premiers éléments de la pile");
                    Empiler(r);
                }
            }
        }
        else
            throw CalcException("Indice en dehors des bornes autorisées");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

//! Methode permettant d'effectuer la somme des x derniers elements de la Pile.
/*! On convertit chacune des Constante parcourues dans le mode dans lequel on se trouve.
  \param mode Une QString designant le mode dans lequel se trouve la calculatrice.
  \param complexe Un bool decrivant si oui ou non la calculatrice est en mode Complexe.
  \param x Un entier designant le nombre d'elements a sommer.
  \sa Logs::WriteLogs(QString string)
  \sa CalcException
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa Complexe
  \sa Entier
  \sa Rationnel
  \sa Reel
*/
void Pile::Mean(int x, QString mode, bool complexe)
{
    Sum(x, mode, complexe);
    Constante* sum = this->Depiler();
    if(complexe == true)
    {
        Entier* e = new Entier(x);
        Constante& tmp = (Complexe)*sum / (Complexe)*e;
        Constante* res = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
        Log::WriteLogs("Moyenne des:" + (QString)Entier(x) + " premiers éléments de la pile");
        Empiler(res);
    }
    else
    {
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)*sum / Entier(x);
            Constante* res = ConstanteFactory::GetConstante((QString)tmp, "Rationnel", complexe);
            Log::WriteLogs("Moyenne des:" + (QString)Entier(x) + " premiers éléments de la pile");
            Empiler(res);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)*sum / Rationnel(x, 1);
            Constante* res = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
            Log::WriteLogs("Moyenne des:" + (QString)Entier(x) + " premiers éléments de la pile");
            Empiler(res);
        }
        else if (mode == "Reel")
        {
            Constante& tmp = (Reel)*sum / Reel((float)x);
            Constante* res = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
            Log::WriteLogs("Moyenne des:" + (QString)Entier(x) + " premiers éléments de la pile");
            Empiler(res);
        }
    }
}

int Pile::rowCount(const QModelIndex &parent)const
{return sommet;}

QVariant Pile::data (const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= sommet)
        return QVariant();
    if (role == Qt::DisplayRole)
       return (QString)*tabElmt[index.row()];
    else
        return QVariant();
}

//! Methode nous servant a analyser ce que l'utilisateur a entre.
/*! On separe d'abord la saisie par ses espaces.
    Puis, nous utilisons des QRegExp pour savoir si chaque partie de la saisie correspond à quelque chose.
  Si non, rien n'est empile.
  \param s Une QString designant l'objet a parser.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QRegExp.html">QRegExp</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QStringList.html">QStringList</a>
*/
void Pile::Parser(QString s)
{
    QStringList elements = s.split(" ");
    QRegExp complexeI("^[0-9]+\\${1}[0-9]+$");
    QRegExp complexeR("^[0-9]+\.{1}[0-9]+\\${1}[0-9]+\.{1}[0-9]+$");
    QRegExp complexeF("^[0-9]+/{1}[0-9]+\\${1}[0-9]+/{1}[0-9]+$");
    QRegExp complexeIR("^[0-9]+\\${1}[0-9]+\.{1}[0-9]+$");
    QRegExp complexeRI("^[0-9]+\.{1}[0-9]+\\${1}[0-9]+$");
    QRegExp complexeIF("^[0-9]+\\${1}[0-9]+/{1}[0-9]+$");
    QRegExp complexeFI("^[0-9]+/{1}[0-9]+\\${1}[0-9]+$");
    QRegExp complexeFR("^[0-9]+/{1}[0-9]+\\${1}[0-9]+\.{1}[0-9]+$");
    QRegExp complexeRF("^[0-9]+\\.{1}[0-9]+\\${1}[0-9]+/{1}[0-9]+$");
    QRegExp rationnel("^[0-9]+/{1}[0-9]+$");
    QRegExp reel("^[0-9]+\.{1}[0-9]+$");
    QRegExp entier("^[0-9]+$");
    QRegExp expdebut("^'{1}");
    QRegExp expfin("'{1}$");

    QString expression("");

    for (int i = 0; i< elements.size(); i++)
    {
        if(elements[i].contains(expfin))
        {
            expression.append(elements[i]);
            Expression* exp = new Expression(expression);
            Empiler(exp);
            expression = "";
        }

        if(expression != "")
        {
            expression.append(elements[i]);
            expression.append(" ");
        }

        else if(elements[i].contains(expdebut))
        {
            expression.append(elements[i]);
            expression.append(" ");
        }        

        else if(elements[i].contains(complexeF) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Rationnel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Rationnel");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeIF) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Entier");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Rationnel");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeFI) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Rationnel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Entier");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeRF) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Reel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Rationnel");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeFR) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Rationnel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Reel");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeI) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Entier");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Entier");
            Complexe* c = new Complexe(re, im);

            Empiler(c);
        }

        else if(elements[i].contains(complexeR) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Reel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Reel");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeIR) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Entier");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Reel");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(complexeRI) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Reel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Entier");
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

        else if(elements[i].contains(rationnel))
        {
            Constante* nouveau2 = new Rationnel(elements[i]);
            Empiler(nouveau2);
        }

        else if(elements[i].contains(reel))
        {
            Constante* nouveau2 = new Reel(elements[i]);
            Empiler(nouveau2);
        }

        else if(elements[i].contains(entier))
        {
            Constante* nouveau2 = new Entier(elements[i]);
            Empiler(nouveau2);
        }

        else if(elements[i] == "+")
            Plus(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "-")
            Moins(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "*")
            Multiplier(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "/")
            Diviser(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "POW")
            Puissance(MainWindow::getMode());

        else if(elements[i] == "MOD")
            Modulo(MainWindow::getMode());

        else if(elements[i] == "SIGN")
            Signe(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "SIN")
            Sinus();

        else if(elements[i] == "COS")
            Cosinus();

        else if(elements[i] == "TAN")
            Tangente();

        else if(elements[i] == "COSH")
            Cosinush();

        else if(elements[i] == "SINH")
            Sinush();

        else if(elements[i] == "TANH")
            Tangenteh();

        else if(elements[i] == "LOG")
            LogaDec();

        else if(elements[i] == "LN")
            LogaNep();

        else if(elements[i] == "INV")
            Inverse();

        else if(elements[i] == "SQRT")
            Racine();

        else if(elements[i] == "SQR")
            Carree(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "CUBE")
            Cube(MainWindow::getMode(), MainWindow::getComplexeMode());

        else if(elements[i] == "!")
            Factorielle(MainWindow::getMode());

    }
}

//! Setter permettant la paramétrisation de la taille de la Pile.
/*! \param i Un entier designant la nouvelle taille de la Pile.
*/
void Pile::setTaille(int i)
{
    createMemento();
    if (i < taille)
    {
        taille = i;
        if (sommet >= taille)
            sommet = taille;
    }
    else
    {
        taille = i;
    }
}
