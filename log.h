#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <iostream>
#include <string>

//! La classe gerant les Log.
/*! Elle repertorie toutes les actions effectuees par l'utilisateur dans un fichier.
*/
class Log
{
public:
    static void WriteLogs(QString string, int degre);
    static void WriteLogs(QString string);
};

#endif // LOG_H
