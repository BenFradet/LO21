#ifndef PILE_H
#define PILE_H
#include "include.h"
#include "constantefactory.h"
#include <string>
#include <QAbstractListModel>
#include <typeinfo>
#include <QVariant>
#include <QList>

using namespace std;

class Memento
{
    friend class Pile;
    int taille;
    int sommet;
    Constante** tabElmt;
public:
    Memento(int dim, int top, Constante** pt)
    {
        taille = dim;
        sommet = top;
        tabElmt = pt;
    }
};

class Pile: public QAbstractListModel
{
    int taille;
    int sommet;
    Constante** tabElmt;

    string mode;

    static Pile* instance;
    Pile(int dim);
    ~Pile();
    Pile& operator=(const Pile& p)
    {
        return *this;
    }

public:
    static Pile& getInstance(int dim);
    static void releaseInstance();    

    Memento* createMemento()const
    {
        return new Memento(taille, sommet, tabElmt);
    }
    void reinstateMemento(Memento* mem);

    void Empiler(Constante* c);
    Constante* Depiler();
    Constante* Tete()const;

    void Swap(int x, int y);
    Constante& Sum(int x);//somme des x premiers éléments (N, Q, R, C)         TEMPLATE METHOD
    Constante& Mean(int x);//moyenne des x premiers éléments (N, Q, R, C)

    void Clear();
    void Dup();//duplique le dernier élément
    void Drop();//supprime le dernier élément

    void Plus(QString mode);//test sur les sommets et les types à faire
    void Moins(QString mode);
    void Multiplier(QString mode);
    void Diviser(QString mode);
    void Puissance(QString mode);
    void Modulo(QString mode);
    void Signe(QString mode);
    void Sinus();
    void Cosinus();
    void Tangente();
    void Sinush();
    void Cosinush();
    void Tangenteh();
    void LogaNep();
    void LogaDec();
    void Inverse(QString mode);
    void Racine();
    void Carree(QString mode);
    void Cube(QString mode);
    void Factorielle(QString mode);

    void Parser (QString s); // découpe un QString en Constantes ou opérateur et les empile

    int getTaille() const
    {
        return taille;
    }

    Constante* getElement(int i)
    {
        return tabElmt[i];
    }

    class Iterator
    {
        Constante** elements;
    public:
        Iterator(Constante** elmts):elements(elmts){}
        Iterator& operator++()
        {
            elements++;
            return *this;
        }
        bool operator!=(const Iterator& it)
        {
            return it.elements != elements;
        }
        Constante& operator*()
        {
            return **elements;
        }
    };
    Iterator& Begin()const
    {
        return Iterator(tabElmt);
    }
    Iterator& End()const
    {
        return Iterator(tabElmt + sommet);
    }

    int rowCount (const QModelIndex &parent=QModelIndex()) const;
    QVariant data (const QModelIndex &index, int role=Qt::DisplayRole) const;

    void emitLayoutChanged()
    {
        emit ( layoutChanged());
    }
};

#endif // PILE_H
