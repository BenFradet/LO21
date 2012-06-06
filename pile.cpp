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
    if(sommet == taille)
        throw CalcException("Pile pleine");
    else
        mementos[sommet++] = m;
}

Memento* Mementos::Depiler()
{
    if(sommet == 0)
        throw CalcException("Pile vide");
    else
        return mementos[--sommet];
}

Memento* Mementos::Tete()const
{
    if(sommet == 0)
        throw CalcException("Pile vide");
    else
        return mementos[sommet-1];
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
    if(sommet == taille)
        throw CalcException("Pile pleine");
    else
        tabElmt[sommet++] = c;
}

Constante* Pile::Depiler()
{
    if(sommet == 0)
        throw CalcException("Pile vide");
    else
        return tabElmt[--sommet];
}

Constante* Pile::Tete()const
{
    if(sommet == 0)
        throw CalcException("Pile vide");
    else
        return tabElmt[sommet-1];
}

void Pile::Clear()
{
    sommet = 0;
}

void Pile::Dup()
{
    if(sommet == taille)
        throw CalcException("Pile pleine");
    else
    {
        Constante* tmp = tabElmt[sommet-1];
        tabElmt[sommet++] = tmp;
    }
}

void Pile::Drop()
{
    if(sommet == 0)
        throw CalcException("Pile vide");
    else
        sommet--;
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
    Memento* m = undos->Depiler();
    retrieveMemento();
    taille = m->taille;
    sommet = m->sommet;
    tabElmt = m->tabElmt;
}

void Pile::Retablir()
{
    Memento* m = redos->Depiler();
    taille = m->taille;
    sommet = m->sommet;
    tabElmt = m->tabElmt;
}

void Pile::Plus(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        createMemento();
        if(complexe == false)
        {
            if(mode == "Entier")
            {
                Constante& tmp = (Entier)*b + (Entier)*a;
                Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
                Empiler(c);
            }
            else if(mode == "Rationnel")
            {
                Constante& tmp = (Rationnel)*b + (Rationnel)*a;
                Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
                Empiler(c);
            }
            else if(mode == "Reel")
            {
                Constante& tmp = (Reel)*b + (Reel)*a;
                Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
                Empiler(c);
            }
        }
        else
        {
            Constante& tmp = (Complexe)*b + (Complexe)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
}

void Pile::Moins(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)*b - (Entier)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)*b - (Rationnel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = (Reel)*b - (Reel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
}

void Pile::Multiplier(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)*b * (Entier)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)*b * (Rationnel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = (Reel)*b * (Reel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
}

void Pile::Diviser(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)*b / (Entier)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)*b / (Rationnel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = (Reel)*b / (Reel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
}

void Pile::Puissance(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)*b ^ (Entier)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)*b ^ (Rationnel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = (Reel)*b ^ (Reel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
}

void Pile::Modulo(QString mode)
{
    if(sommet>=2)
    {
        Constante* a = this->Depiler();
        Constante* b = this->Depiler();
        const Entier* e1 = dynamic_cast<const Entier*>(a);
        const Entier* e2 = dynamic_cast<const Entier*>(b);
        if(e1 != NULL && e2 != NULL && mode == "Entier")
        {
            createMemento();
            Constante* c = new Entier((Entier)*b % (Entier)*a);
            Empiler(c);
        }
        else
            throw CalcException("Cette opération nécessite deux entiers");
    }
    else
        throw CalcException("Cette opération nécessite deux opérandes");
}

void Pile::Signe(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = -(Entier)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = -(Rationnel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = -(Reel)*a;
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Sinus()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->sinus());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Cosinus()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->cosinus());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Tangente()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->tangente());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Sinush()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->sinush());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Cosinush()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->cosinush());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Tangenteh()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->tangenteh());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::LogaNep()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->lognep());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::LogaDec()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->logdec());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Inverse()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();        
        createMemento();
        Constante* res = &a->inverse();
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Racine()
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        Constante* res = new Reel(a->racine());
        Empiler(res);
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Carree(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)a->carree();
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)a->carree();
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = (Reel)a->carree();
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Cube(QString mode, bool complexe)
{
    ConstanteFactory* factory = new ConstanteFactory();
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        createMemento();
        if(mode == "Entier")
        {
            Constante& tmp = (Entier)a->cube();
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Rationnel")
        {
            Constante& tmp = (Rationnel)a->cube();
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
        else if(mode == "Reel")
        {
            Constante& tmp = (Reel)a->cube();
            Constante* c = factory->GetConstante(tmp.ToQString(), mode, complexe);
            Empiler(c);
        }
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Factorielle(QString mode)
{
    if(sommet>=1)
    {
        Constante* a = this->Depiler();
        const Entier* e = dynamic_cast<const Entier*>(a);
        if(e!=0 && mode == "Entier")
        {
            createMemento();
            Constante* res = new Entier(!(Entier)*a);
            Empiler(res);
        }
        else
            throw CalcException("Cette opération nécessite un entier");
    }
    else
        throw CalcException("Cette opération nécessite une opérande");
}

void Pile::Swap(int x, int y)
{
    if(sommet>x-1 && sommet>y-1)
    {
        createMemento();
        Constante* tmp;
        tmp = tabElmt[x-1];
        tabElmt[x-1] = tabElmt[y-1];
        tabElmt[y-1] = tmp;
    }
    else
        throw CalcException("Les indices doivent être dans la pile");
}

Constante& Pile::Sum(int x, QString mode)
{
    if(x-1<sommet && x-1>=0)
    {
        if(mode == "Entier")
        {
            createMemento();
            Entier* e = new Entier(0);
            for(int i = 0; i<=x-1; i++)
                *e = *e + (Entier)**(tabElmt + sommet - 1 - i);
            Empiler(e);
            return *e;
        }
        else if(mode == "Rationnel")
        {
            createMemento();
            Rationnel* r = new Rationnel(0, 1);
            for(int i = 0; i<x-1; i++)
                *r = *r + (Rationnel)**(tabElmt + sommet - 1 - i);
            Empiler(r);
            return *r;
        }
        else if(mode == "Reel")
        {
            createMemento();
            Reel* r = new Reel(0);
            for(int i = 0; i<x-1; i++)
                *r = *r + (Reel)**(tabElmt + sommet - 1 - i);
            Empiler(r);
            return *r;
        }
    }
    else
        throw CalcException("Indice en dehors des bornes autorisées");
}

void Pile::Mean(int x, QString mode)
{
    if(x-1<sommet && x-1>=0)
    {
        if(mode == "Entier" || mode == "Rationnel")
        {
            Constante* e = &Sum(x, mode);
            Constante* c = Depiler();
            Constante& res = *e / Entier(x);
            Empiler(&res);
        }
        else if (mode == "Reel")
        {
            Constante* e = &Sum(x, mode);
            Constante* c = Depiler();
            Constante& res = *e / Reel(x);
            Empiler(&res);
        }
    }
    else
        throw CalcException("Indice en dehors des bornes autorisées");
}

int Pile::rowCount (const QModelIndex &parent) const
{return sommet;}

QVariant Pile::data (const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= sommet)
        return QVariant();
    if (role == Qt::DisplayRole)
       return tabElmt[index.row()]->ToQString();
    else
        return QVariant();
}


void Pile::Parser(QString s)
{
    QStringList elements = s.split(" ");
    QRegExp complexe("^[0-9]+\\${1}[0-9]+$");  // à compléter, complexe prend 2 constantes
    QRegExp rationnel ("^[0-9]+/{1}[0-9]+$");
    QRegExp reel ("^[0-9]+\.{1}[0-9]+$");
    QRegExp entier ("^[0-9]+$");


    for (int i = 0; i< elements.size(); i++)
    {
        if(elements[i].contains(complexe) && MainWindow::getComplexeMode() == true)
        {
            ConstanteFactory* factory = new ConstanteFactory();
            QStringList comp = elements[i].split("$");
            Constante* re = factory->GetConstante(comp[0], MainWindow::getMode());
            Constante* im = factory->GetConstante(comp[1], MainWindow::getMode());
            Complexe* c = new Complexe(re, im);
            Empiler(c);
        }

         if(elements[i].contains(rationnel))
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
            Puissance(MainWindow::getMode(), MainWindow::getComplexeMode());

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
