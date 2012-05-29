#ifndef PILE_H
#define PILE_H

#include "constante.h"
#include "entier.h"
#include "expression.h"
#include "complex"
#include "rationnel.h"
#include "reel.h"
#include <QAbstractListModel>
#include <typeinfo>
#include <QVariant>
#include <QList>

class Pile: public QAbstractListModel
{
    int taille;
    int sommet;
    Constante** tabElmt;

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

    void Empiler(Constante* c);
    Constante* Depiler();
    Constante* Tete()const;

    void Swap(int x, int y);
    Constante& Sum(int x);//somme des x premiers éléments (N, Q, R, C)         TEMPLATE METHOD
    Constante& Mean(int x);//moyenne des x premiers éléments (N, Q, R, C)

    void Clear();
    void Dup();//duplique le dernier élément
    void Drop();//supprime le dernier élément

    void Plus();//test sur les sommets et les types à faire
    void Moins();
    void Multiplier();
    void Diviser();
    void Puissance();
    void Modulo();
    void Signe();
    void Sinus();
    void Cosinus();
    void Tangente();
    void Sinush();
    void Cosinush();
    void Tangenteh();
    void LogaNep();
    void LogaDec();
    void Inverse();
    void Racine();
    void Carree();
    void Cube();
    void Factorielle();

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
