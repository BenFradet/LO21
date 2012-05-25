#include <QtGui/QApplication>
#include "mainwindow.h"
#include "include.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile(20);
    Entier p = 3;
    Entier k = 4;
    Entier t = 5;
    Entier l = 5;

    MainWindow w(&pile,0);
    pile.Empiler(&p);
    pile.Empiler(&k);
    pile.Empiler(&t);
    pile.Empiler(&l);

    w.show();



    return a.exec();
}

