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

        MainWindow w(&pile, 0);

        w.show();

        return a.exec();
        Pile::releaseInstance();
    }
    catch(CalcException c)
    {

    }
}

