#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include "include.h"
#include <QString>

class ConstanteFactory
{
public:
    ConstanteFactory(){}
    Constante* GetConstante(QString val, QString mode);
};

#endif // CONSTANTEFACTORY_H
