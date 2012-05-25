#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Pile *P, QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Pile* p;

private slots:

    void btn0pressed();
    void btn1pressed();
    void btn2pressed();
    void btn3pressed();
    void btn4pressed();
    void btn5pressed();
    void btn6pressed();
    void btn7pressed();
    void btn8pressed();
    void btn9pressed();
    void btnAnnulerpressed();

    void affichage_scientifique();
    void affichage_standard();

    void envoi_pile();


};

#endif // MAINWINDOW_H
