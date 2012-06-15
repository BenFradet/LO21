#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <QString>

//! Fabrique de Constante.
/*! Grace au design pattern <a href="http://fr.wikipedia.org/wiki/Fabrique_(patron_de_conception)">Fabrique</a> on cree un objet suivant le mode dans lequel la calculatrice se trouve.
*/
class ConstanteFactory
{
public:
    static Constante* GetConstante(QString val, QString mode, bool complexe);
    static Constante* GetConstante(QString val, QString mode);
};

#endif // CONSTANTEFACTORY_H
