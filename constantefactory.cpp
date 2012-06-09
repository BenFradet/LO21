#include "constantefactory.h"

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
