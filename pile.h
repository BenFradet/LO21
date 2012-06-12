#ifndef PILE_H
#define PILE_H
#include "include.h"
#include "constantefactory.h"
#include "expressionfactory.h"
#include "mainwindow.h"
#include "log.h"
#include <string>
#include <QAbstractListModel>
#include <typeinfo>
#include <QVariant>
#include <QList>

class MainWindow;

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

class Mementos
{
    int taille;
    int sommet;
    Memento** mementos;
    friend class Pile;

    static Mementos* instance1;
    static Mementos* instance2;
    Mementos(int dim);
    ~Mementos();
    Mementos& operator=(const Mementos& m)
    {
        return *this;
    }

public:
    static Mementos& getInstance1(int dim);
    static void releaseInstance1();

    static Mementos& getInstance2(int dim);
    static void releaseInstance2();

    int GetTaille()const{return taille;}

    /*Mementos(int dim);
    ~Mementos();*/

    void Empiler(Memento* m);
    Memento* Depiler();
    Memento* Tete()const;
    void Clear();
};

class Pile: public QAbstractListModel
{
    int taille;
    int sommet;
    Constante** tabElmt;

    Mementos* undos;
    Mementos* redos;

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

    void createMemento()const;
    void retrieveMemento()const;

    void Empiler(Constante* c);
    Constante* Depiler();
    Constante* Tete()const;

    void Swap(int x, int y);
    Constante& Sum(int x, QString mode);
    void Mean(int x, QString mode);

    void Clear();
    void Dup();//duplique le dernier élément
    void Drop();//supprime le dernier élément

    void Plus(QString mode, bool complexe);
    void Moins(QString mode, bool complexe);
    void Multiplier(QString mode, bool complexe);
    void Diviser(QString mode, bool complexe);
    void Puissance(QString mode);
    void Modulo(QString mode);
    void Signe(QString mode, bool complexe);
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
    void Carree(QString mode, bool complexe);
    void Cube(QString mode, bool complexe);
    void Factorielle(QString mode);

    void Annuler();
    void Retablir();

    void Parser (QString s); // découpe un QString en Constantes ou opérateur et les empile

    int getTaille() const
    {
        return taille;
    }

    void setTaille(int i);

    Constante* getElement(int i)
    {
        return tabElmt[i];
    }

    int getSommet() const
    {
        return sommet;
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
        Iterator& operator--()
        {
            elements--;
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
