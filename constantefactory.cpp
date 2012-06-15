#include "constantefactory.h"

//! Methode static qui cree une Constante de type donne par l'argument mode.
/*! \param val Une QString designant la Constante.
    \param mode Le mode dans lequel la Caclulatrice se trouve.
    \param complexe Un booleen indiquant si on se trouve en mode Complexe ou non.
    \return Un pointeur sur une Constante.
    \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    \sa Constante
    \sa Entier
    \sa Reel
    \sa Rationnel
    \sa Complexe
*/
Constante* ConstanteFactory::GetConstante(QString val, QString mode, bool complexe)
{
    if(complexe == true)
        return new Complexe(val, mode);
    else if(mode == "Entier")
        return new Entier(val);
    else if(mode == "Reel")
        return new Reel(val);
    else if(mode == "Rationnel")
        return new Rationnel(val);
    return 0;
}

//! Methode static qui cree une Constante de type donne par l'argument mode.
/*! Elle est appelée uniquement par les Complexes pour eviter d'essayer de creer un Complexe a partir de sa partie reelle ou imaginaire.
    \param val Une QString designant la Constante.
    \param mode Le mode dans lequel la Caclulatrice se trouve.
    \return Un pointeur sur une Constante.
    \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    \sa Constante
    \sa Entier
    \sa Reel
    \sa Rationnel
*/
Constante* ConstanteFactory::GetConstante(QString val, QString mode)
{
    if(mode == "Entier")
        return new Entier(val);
    if(mode == "Reel")
        return new Reel(val);
    if(mode == "Rationnel")
        return new Rationnel(val);
    return 0;
}
