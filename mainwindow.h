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
    void btnSPACEpressed();

    void btnAddipressed();
    void btnSouspressed();
    void btnMultpressed();
    void btnDivipressed();

    void btnINVpressed();
    void btnCOSpressed();
    void btnSINpressed();
    void btnTANpressed();
    void btnCOSHpressed();
    void btnSINHpressed();
    void btnTANHpressed();
    void btnLOGpressed();
    void btnLNpressed();
    void btnFACTOpressed();
    void btnSIGNpressed();
    void btnSQRpressed();
    void btnSQRTpressed();
    void btnCUBEpressed();
    void btnCOMPLEXEpressed();
    void btnPOWpressed();
    void btnMODpressed();

    void btnSWAPpressed();
    void btnSUMpressed();
    void btnMEANpressed();
    void btnCLEANpressed();
    void btnDUPpressed();
    void btnDROPpressed();
    void btnPOINTpressed();

    void affichage_scientifique();
    void affichage_standard();
    void btnAnnulerpressed();
    void envoi_pile();


};

#endif // MAINWINDOW_H
