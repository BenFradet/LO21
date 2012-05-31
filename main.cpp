#include <QtGui/QApplication>
#include "mainwindow.h"
#include "include.h"
#include <iostream>


int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);

        Pile& pile = Pile::getInstance(20);
        Entier p(3);
        Entier k(4);
        Entier t(5);
        Entier l(5);

        pile.Empiler(&p);
        pile.Empiler(&k);
        pile.Empiler(&t);
        pile.Empiler(&l);
        pile.Empiler(&(Entier)pile.Plus());//besoin du mode

        MainWindow w(&pile, 0);

        w.show();

        //Pile::releaseInstance();

        return a.exec();
    }
    catch(CalcException c)
    {

    }
}

