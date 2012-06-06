#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include "include.h"
#include <QString>

class ConstanteFactory
{
public:
    ConstanteFactory(){}
    static Constante* GetConstante(QString val, QString mode, bool complexe);
    static Constante* GetConstante(QString val, QString mode);
};

#endif // CONSTANTEFACTORY_H
