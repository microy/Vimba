#ifndef QTELECOMMAND_H
#define QTELECOMMAND_H

#include "gclib.h"
#include "gclibo.h"
#include <QWidget>
#include <QLineEdit>
#include <mylabel.h>
#include <mylineedit.h>
#include <QCoreApplication>
#include <QApplication>
#include <iostream> //std::cout
#include <QGraphicsOpacityEffect>
#include <sstream>
#include <QTimer>
//#include <iostream> //std::cout
//#include <string> //to_string, string, etc.

class QTelecommand : public QWidget
{
    Q_OBJECT
public:

    void keyPressEvent(QKeyEvent* event)
    {
        if (event->type()==QEvent::KeyPress)
        {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if((key->key()==16777220)||(key->key()==Qt::Key_Enter))
                {    GalilGo();   }
        }
    }

    //Ecart entre a position intial et réalité
    int ecartTheta=0;
    int ecartPhi=10;
    int ecartZ=0;

    explicit QTelecommand(QWidget *parent = 0);
    void TelecommandON();
    void TelecommandOFF();
    void Link(GCon &g);

    int vitesse_Z_lente;
    int vitesse_Z_rapide;

    int vitesse_theta_lente;
    int vitesse_theta_rapide;

    int vitesse_phi_lente;
    int vitesse_phi_rapide;

    double pas_unit_phi;          // (2) signaux A et B, (232)  rapport de reduction  (1024) cts/rev du codeur
    double pas_unit_theta;            // MO62PD : 4000 cts/rev   -->  1 tour <=> 440000 ps   --> 4,5° <=> 5500 ps
    double pas_unit_Z;            // MO62PD : 4000 cts/rev   -->  1 tour <=> 440000 ps   --> 4,5° <=> 5500 ps
    int pos_phi;

    MyLineEdit *lineEditTeta;
    MyLineEdit *lineEditPhi;
    MyLineEdit *lineEditZ;

    double *bPhiMin, *bPhiMax, *bZMin, *bZMax;



private:
    void Wait(float msec);

    int ReadGalilTeta();
    int ReadGalilPhi();
    int ReadGalilZ();

    void GalilGoPhi(double phiValue);
    void GalilGoZ(double zValue);


    QWidget *panel;
    QLabel *label;
    int m_OnOff=0;
    GCon m_g;

    //Liste des boutons
    MyLabel boutonTetaP1;
    MyLabel boutonTetaP2;
    MyLabel boutonTetaM1;
    MyLabel boutonTetaM2;

    MyLabel boutonPhiP1;
    MyLabel boutonPhiP2;
    MyLabel boutonPhiM1;
    MyLabel boutonPhiM2;

    MyLabel boutonTPStop;


    MyLabel boutonZP1;
    MyLabel boutonZP2;
    MyLabel boutonZM1;
    MyLabel boutonZM2;

    MyLabel boutonZStop;

    MyLabel boutonGo;
    QTimer *timerTeta;
    QTimer *timerPhi;
    QTimer *timerZ;
    QTimer *timerTestPhiM;
    QTimer *timerTestPhiP;
    QTimer *timerTestZM;
    QTimer *timerTestZP;

    double teta,phi,z,tetaForGo,phiForGo,zForGo;

    void SizeWinElements();
    char buf[1024]; //traffic buffer

    double testMajPhiValue=-100;

signals:

public slots:
    void TetaP1Clicked();
    void TetaP2Clicked();
    void TetaM1Clicked();
    void TetaM2Clicked();
    void PhiP1Clicked();
    void PhiP2Clicked();
    void PhiM1Clicked();
    void PhiM2Clicked();
    void TPStopClicked();
    void TetaP1Unclicked();
    void TetaP2Unclicked();
    void TetaM1Unclicked();
    void TetaM2Unclicked();
    void PhiP1Unclicked();
    void PhiP2Unclicked();
    void PhiM1Unclicked();
    void PhiM2Unclicked();
    void TPStopUnclicked();

    void ZP1Clicked();
    void ZP2Clicked();
    void ZM1Clicked();
    void ZM2Clicked();
    void ZP1Unclicked();
    void ZP2Unclicked();
    void ZM1Unclicked();
    void ZM2Unclicked();
    void ZStopClicked();
    void ZStopUnclicked();

    void GalilGo();
    void SaveTeta();
    void SavePhi();
    void SaveZ();

    void MajLineEditTeta();
    void MajLineEditPhi();
    void MajLineEditZ();

    void TestMajPhiM();
    void TestMajPhiP();

    void TestMajZM();
    void TestMajZP();

    void TimerTetaStop();
    void TimerPhiStop();
    void TimerZStop();

};

#endif // QTELECOMMAND_H
