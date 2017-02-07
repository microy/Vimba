#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gclib.h"
#include "gclibo.h"


#include <iostream> //std::cout
#include <string> //to_string, string, etc.

#define GALIL_EXAMPLE_OK G_NO_ERROR //return code for correct code execution
#define GALIL_EXAMPLE_ERROR -100 //return code for error in example code



#include <MyLabel.h>
#include <QTelecommand.h>
#include <OpTelecommand.h>
#include <QPanelProcess.h>
#include <QDesktopWidget>

#include<QSerialPort>
#include<QSerialPortInfo>
#include<QDebug>
#include<APropos.h>
#include<QPanelOnglets.h>
#include <QMainWindow>

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void SizeWinElements(int l, int h);
    void BoutonOff();
    void BoutonOn();
    void InitGalil(GCon &g);
    void GalilPositionZero();

    QWidget *panelStatut;
    QWidget *whiteLine;
    OpTelecommand *opTelecommandPanel;
    QAction *actionopTelecommand;


//Elements graphiques
    QLabel *labelFond;         //Image de fond de l'interface
    QLabel *labelBarreEtat;    //Barre d'état de l'interface
    QLabel *labeltextBarreEtat;//Texte barre d'état
    QTelecommand *tCommand;
    QPanelProcess *processPanel;
    Apropos *aProposPanel;
    QPanelOnglets *panelOnglets;

//Liste des boutons
    MyLabel boutonConnect;

    MyLabel ledStatut;
    MyLabel camStatut;
    MyLabel galilStatut;

    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 1;
    QString arduino_port_name;
    bool arduino_is_available;

//Valeurs Galil
    char buf[1024]; //traffic buffer



public slots:
//Liste des actions effectués par nos boutons
    void Connect();         //action ON/OFF de boutonConnect
    void GalilMooveTest();      //action du boutonMoove Pressed
    void GalilLedTest();
    void CamTest();

    void OpenApropos();
    void OpenOpTelecommand();

};

#endif // MAINWINDOW_H



