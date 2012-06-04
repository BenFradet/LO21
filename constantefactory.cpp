#include "constantefactory.h"

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