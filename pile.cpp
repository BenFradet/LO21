#include "pile.h"
#include "QStringList"
#include "QRegExp"
#include "QString"

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
        throw CalcException("La pile est pleine !");
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
        throw CalcException("La pile est vide !");
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
    try {
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

Pile::Pile(int dim)
{
    taille = dim;
    sommet = 0;
    tabElmt = new Constante*[taille]();
    undos = new Mementos(dim);
    redos = new Mementos(dim);
}

Pile::~Pile()
{
    delete[] tabElmt;
    delete undos;
    delete redos;
}

void Pile::Empiler(Constante* c)
{
    try
    {
    if(sommet == taille)
        throw CalcException("Impossible d'empiler, la pile est pleine.");
    else
    {
        createMemento();
        //Log::WriteLogs("Empilement de:" + (QString)*c);
        tabElmt[sommet++] = c;
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

Constante* Pile::Depiler()
{
    try
    {
    if(sommet == 0)
        throw CalcException("La pile est vide !");
    else
    {
        //createMemento();
        Log::WriteLogs("Dépilement de:" + (QString)*tabElmt[sommet-1]);
        return tabElmt[--sommet];
    }
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

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

void Pile::Clear()
{
    createMemento();
    Log::WriteLogs("Clear de la pile");
    sommet = 0;
}

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

void Pile::createMemento()const
{
    Memento* m = new Memento(taille, sommet, tabElmt);
    undos->Empiler(m);
}

void Pile::retrieveMemento()const
{
    Memento* m = new Memento(taille, sommet, tabElmt);
    redos->Empiler(m);
}

void Pile::Annuler()
{
    Log::WriteLogs("Annulation");
    Memento* m = undos->Depiler();
    retrieveMemento();
    taille = m->taille;
    sommet = m->sommet;
    tabElmt = m->tabElmt;
}

void Pile::Retablir()
{
    Log::WriteLogs("Rétablissement");
    Memento* m = redos->Depiler();
    taille = m->taille;
    sommet = m->sommet;
    tabElmt = m->tabElmt;
}

void Pile::Plus(QString mode, bool complexe)
{
    try
    {
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite deux opérandes !");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Moins(QString mode, bool complexe)
{
    try
    {
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite deux opérandes !");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Multiplier(QString mode, bool complexe)
{
    try
    {
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Diviser(QString mode, bool complexe)
{
    try
    {
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        if(complexe == false)
        {
            if(mode == "Entier")
            {
                Constante& tmp = (Entier)*b / (Entier)*a;
                Constante* c = ConstanteFactory::GetConstante((QString)tmp, mode, complexe);
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
    else
        throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Puissance(QString mode)
{
   try
    {
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }


}

void Pile::Modulo(QString mode)
{
    try {
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        const Entier* e1 = dynamic_cast<const Entier*>(a);
        const Entier* e2 = dynamic_cast<const Entier*>(b);
        if(e1 != NULL && e2 != NULL && mode == "Entier")
        {
            Constante* c = new Entier((Entier)*b % (Entier)*a);
            Log::WriteLogs("Modulo de:" + (QString)*b + " et " + (QString)*a);
            Empiler(c);
        }
        else
            throw CalcException("Cette opération nécessite deux entiers");
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Signe(QString mode, bool complexe)
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Sinus()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Cosinus()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Tangente()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Sinush()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Cosinush()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Tangenteh()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::LogaNep()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        Constante* res = new Reel(a->lognep());
        Log::WriteLogs("Logarithme néperien de:" + (QString)*a);
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::LogaDec()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        Constante* res = new Reel(a->logdec());
        Log::WriteLogs("Logarithme décimal de:" + (QString)*a);
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Inverse()
{
    try{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        Constante* res = &a->inverse();
        Log::WriteLogs("Inverse de:" + (QString)*a);
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Racine()
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        Constante* res = new Reel(a->racine());
        Log::WriteLogs("Racine carrée de:" + (QString)*a);
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Carree(QString mode, bool complexe)
{
   try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Cube(QString mode, bool complexe)
{
    try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
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
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Factorielle(QString mode)
{
   try {
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        const Entier* e = dynamic_cast<const Entier*>(a);
        if(e!=0 && mode == "Entier")
        {
            Constante* res = new Entier(!(Entier)*a);
            Log::WriteLogs("Factorielle de:" + (QString)*a);
            Empiler(res);
        }
        else
            throw CalcException("Cette opération nécessite un entier");
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
    }
    catch (CalcException c)
    {
        c.alert();
    }
}

void Pile::Swap(int x, int y)
{
    try {
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

Constante& Pile::Sum(int x, QString mode)
{
    try {
    if(x-1<sommet && x-1>=0)
    {
        if(mode == "Entier")
        {
            Entier* e = new Entier(0);
            for(int i = 0; i<=x-1; i++)
                *e = *e + (Entier)**(tabElmt + sommet - 1 - i);
            Log::WriteLogs("Somme des:" + (QString)x + " premiers éléments de la pile");
            Empiler(e);
            return *e;
        }
        else if(mode == "Rationnel")
        {
            Rationnel* r = new Rationnel(0, 1);
            for(int i = 0; i<x-1; i++)
                *r = *r + (Rationnel)**(tabElmt + sommet - 1 - i);
            Log::WriteLogs("Somme des:" + (QString)x + " premiers éléments de la pile");
            Empiler(r);
            return *r;
        }
        else if(mode == "Reel")
        {
            Reel* r = new Reel(0);
            for(int i = 0; i<x-1; i++)
                *r = *r + (Reel)**(tabElmt + sommet - 1 - i);
            Log::WriteLogs("Somme des:" + (QString)x + " premiers éléments de la pile");
            Empiler(r);
            return *r;
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

void Pile::Mean(int x, QString mode)
{
    try {
    if(x-1<sommet && x-1>=0)
    {
        if(mode == "Entier" || mode == "Rationnel")
        {
            Constante* e = &Sum(x, mode);
            Constante* c = Depiler();
            Constante& res = *e / Entier(x);
            Log::WriteLogs("Moyenne des:" + (QString)x + " premiers éléments de la pile");
            Empiler(&res);
        }
        else if (mode == "Reel")
        {
            Constante* e = &Sum(x, mode);
            Constante* c = Depiler();
            Constante& res = *e / Reel(x);
            Log::WriteLogs("Moyenne des:" + (QString)x + " premiers éléments de la pile");
            Empiler(&res);
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

int Pile::rowCount (const QModelIndex &parent) const
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

        else if(elements[i].contains(complexeF) && MainWindow::getComplexeMode() == true)
        {
            QStringList comp = elements[i].split("$");
            Constante* re = ConstanteFactory::GetConstante(comp[0], "Rationnel");
            Constante* im = ConstanteFactory::GetConstante(comp[1], "Rationnel");
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
