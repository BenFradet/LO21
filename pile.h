#ifndef PILE_H
#define PILE_H
#include "constante.h"
#include "constantefactory.h"
#include "expressionfactory.h"
#include "mainwindow.h"
#include "log.h"
#include <string>
#include <QAbstractListModel>
#include <typeinfo>
#include <QVariant>
#include <QList>
#include <QStringList>
#include <QRegExp>
#include <QString>

class MainWindow;

//! Gere un Memento de la Pile.
/*! Cette classe prend une photo de la Pile a un instant donne pour pouvoir ensuite la restaurer
    en utilisant le design pattern <a href="http://fr.wikipedia.org/wiki/M%C3%A9mento_(patron_de_conception)">Memento</a>.
*/
class Memento
{
    //! On met la classe Pile en ami pour pouvoir avoir acces a ses attributs prives directement.
    /*! \sa Pile */
    friend class Pile;
    //! La taille de la Pile est stockee dans un Memento.
    int taille;
    //! Le sommet de la Pile est aussi stocke dans un Memento.
    int sommet;
    //! On stocke aussi un pointeur vers le premier element du tableau d'elements de la Pile.
    Constante** tabElmt;
public:
    //! Le constructeur principal de la classe Memento.
    /*! On prend chaque attribut en parametre pour ensuite les affecter.
      \param dim Un entier designant la taille de la Pile.
      \param top Un entier correspondant au sommet de la Pile.
      \param pt Un pointeur sur le premier element du tableau d'elements de la classe Pile.
      */
    Memento(int dim, int top, Constante** pt)
    {
        taille = dim;
        sommet = top;
        tabElmt = pt;
    }
};

//! Gere les Memento de la Pile.
/*! Pour gere les differents Memento de la Pile, on a mis en place une pile de Memento, Mementos.
*/
class Mementos
{
    //! La taille de la pile Mementos.
    int taille;
    //! Le sommet de la pile Mementos.
    int sommet;
    //! Un tableau de pointeur sur des Memento.
    Memento** mementos;
    //! On declare la classe Pile en amie pour qu'elle puisse acceder aux membres prives de Mementos.
    /*! Cela genere malheureusement un conflit avec le doubleton de Mementos.
        \sa Pile*/
    friend class Pile;

    //! La premiere instance de Mementos correspondant a la pile d'annulations.
    /*! On a choisit de limiter le nombre de Mementos a 2: une pile pour les annulations et une pile pour les retablissements
        en utilisant le design pattern <a href="http://fr.wikipedia.org/wiki/Singleton_(patron_de_conception)">Singleton</a> adapte a 2 instances.*/
    static Mementos* instance1;
    //! La deuxieme instance de Mementos correspondant a la pile de retablissements.
    static Mementos* instance2;
    //! Le constructeur prive de la classe Mementos.
    /*! On initialise l'attribut sommet a 0.
      On cree dynamiquement un tableau de Memento ayant pour taille le parametre.
      \param dim La taille de la pile Mementos.
    */
    Mementos(int dim);
    //! Le destructeur prive de la classe Mementos.
    /*! On detruit le tableau creee dynamiquement dans le constructeur.
        \sa Mementos(int dim)
    */
    ~Mementos();
    //! Surcharge de l'operateur d'affectation pour eviter la multiplication d'objets Mementos.
    Mementos& operator=(const Mementos&)
    {
        return *this;
    }

public:
    //! Getter statique de la premiere instance de Mementos, servant de constructeur.
    /*! \param dim Un entier representant la taille de la pile d'annulations.
      \return Une reference sur un Mementos.
    */
    static Mementos& getInstance1(int dim);
    //! Methode statique servant de destructeur de la premiere instance de Mementos.
    static void releaseInstance1();

    //! Getter statique de la seconde instance de Mementos, servant de constructeur.
    /*! \param dim Un entier representant la taille de la pile d'annulations.
      \return Une reference sur un Mementos.
    */
    static Mementos& getInstance2(int dim);
    //! Methode statique servant de destructeur de la seconde instance de Mementos.
    static void releaseInstance2();

    //! Getter retournant la taille d'un objet Mementos.
    /*! \return La taille de la pile de Memento: Mementos passe en argument implicite.
    */
    int GetTaille()const{return taille;}

    //! Ajout d'un Memento a la pile Mementos.
    /*! \param m Un pointeur de Memento.
    */
    void Empiler(Memento* m);
    //! Suppression d'un Memento de la pile Mementos.
    /*! \return Un pointeur sur un Memento.
        \sa CalcException
    */
    Memento* Depiler();
    //! Retourne la tete de la pile Mementos.
    /*! \return Un pointeur sur un Memento.
        \sa CalcException
    */
    Memento* Tete()const;
    //! Methode permmettant de vider la pile Mementos.
    /*! \sa CalcException */
    void Clear();
};

//! Pile de Constante.
/*! Elle herite de la classe QAbstractListModel
    \sa <a href="http://qt-project.org/doc/qt-4.8/QAbstractListModel.html">QAbstractListModel</a>
*/
class Pile: public QAbstractListModel
{
    //! Taille de la Pile.
    int taille;
    //! Sommet de la Pile.
    int sommet;
    //! Tableau de pointeurs sur des Constante.
    Constante** tabElmt;

    //! Un pointeur sur Mementos, pile d'annulations.
    Mementos* undos;
    //! Un pointeur sur Mementos, pile de retablissements.
    Mementos* redos;

    //! Instance unique de la classe Pile.
    /*! Pour la classe Pile, nous avons choisi de limite le nombre d'objet Pile a 1 en utilisant
      le design pattern <a href="http://fr.wikipedia.org/wiki/Singleton_(patron_de_conception)">Singleton</a>.*/
    static Pile* instance;
    Pile(int dim);
    ~Pile();
    //! Surcharge de l'operateur d'affectation pour eviter la multiplication des objets Pile.
    /*! \param Une reference constante sur le Pile.
    */
    Pile& operator=(const Pile&)
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
    void Sum(int x, QString mode, bool complexe);
    void Mean(int x, QString mode, bool complexe);

    void Clear();
    void Dup();
    void Drop();

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

    void Parser (QString s);

    //! Getter pour l'attribut taille de la classe Pile.
    int getTaille() const
    {
        return taille;
    }

    void setTaille(int i);

    //! Getter pour avoir acces a l'element d'indice i.
    /*! \param i Un entier indiquant l'indice de l'element que l'on recherche.
    */
    Constante* getElement(int i)
    {
        return tabElmt[i];
    }

    //! Getter pour l'attribut sommet de la classe Pile.
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
    Iterator Begin()const
    {
        return Iterator(tabElmt);
    }
    Iterator End()const
    {
        return Iterator(tabElmt + sommet);
    }

    //A commenter.
    int rowCount (const QModelIndex &parent=QModelIndex()) const;
    QVariant data (const QModelIndex &index, int role=Qt::DisplayRole) const;

    void emitLayoutChanged()
    {
        emit ( layoutChanged());
    }
};

#endif // PILE_H
