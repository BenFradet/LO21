#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pile.h"

namespace Ui {
class MainWindow;
}

class Pile;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Pile *P, QWidget *parent = 0);
    ~MainWindow();
    static QString getMode() {return mode;}
    static bool getComplexeMode() {return ComplexeMode;}
    static void setMode(QString s) { mode = s;}
    static void setComplexeMode(bool b) { ComplexeMode = b;}
    void closeEvent(QCloseEvent * event);
    
private:
    Ui::MainWindow *ui;
    Pile* p;
    static QString mode;
    static bool ComplexeMode;


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
    void btnRetablirpressed();
    void MODE_REELS();
    void MODE_RATIONNELS();
    void MODE_ENTIERS();
    void envoi_pile();
    void COMPLEXE_MODE(int b);

    void btnRAZpressed();
};

#endif // MAINWINDOW_H
