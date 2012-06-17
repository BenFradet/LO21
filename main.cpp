#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>
#include <QDomDocument>
#include <QString>
#include <QFile>


//! Fonction principale de l'application
/*! Ouvre le fichier de configuration pour chercher la taille de la pile. Si ce fichier
    n'existe pas, la pile est creee avec une taille de 50 par defaut.
    On cree ensuite une instance de la pile avec cette taille et on cree une Mainwindow reliee
    a cette pile. En fin d'execution, on n'oublie pas de relacher la memoire. */

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        QDomDocument doc ("CONFIGURATION");
        QFile file ("PILE.xml");
        if( !doc.setContent( &file ) )
        {
          file.close();
        }
        file.close();
        QString s(doc.firstChild().childNodes().at(7).firstChild().nodeValue());
        if (s.toInt() == 0)
            s ="50";


        Pile& pile = Pile::getInstance(s.toInt());

        MainWindow w(&pile, 0);

        w.show();

        return a.exec();
        Pile::releaseInstance();
}

