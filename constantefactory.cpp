#include "constantefactory.h"

Constante* ConstanteFactory::GetConstante(QString val, QString mode)
{
    if(mode == "Entier")
        return new Entier(val);
    if(mode == "Réel")
        return new Reel(val);
    if(mode == "Rationnel")
        return new Rationnel(val);
    /*if(mode == "Complexe")
      return new Complexe(val);*/
    return 0;
}
