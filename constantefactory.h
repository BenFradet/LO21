#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include "include.h"
#include <QString>

//! Fabrique de Constante.
/*! Grace au design pattern Fabrique on cree un objet suivant le mode dans lequel la calculatrice se trouve.
*/
class ConstanteFactory
{
public:
    static Constante* GetConstante(QString val, QString mode, bool complexe);
    static Constante* GetConstante(QString val, QString mode);
};

#endif // CONSTANTEFACTORY_H
