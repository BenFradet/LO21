#include <QtGui/QApplication>
#include "mainwindow.h"
#include "include.h"
#include <iostream>


int main(int argc, char *argv[])
{

        QApplication a(argc, argv);

        Pile& pile = Pile::getInstance(50);

        MainWindow w(&pile, 0);

        w.show();

        return a.exec();
        Pile::releaseInstance();

}

