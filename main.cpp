#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>
#include <QDomDocument>
#include <QString>
#include <QFile>


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

