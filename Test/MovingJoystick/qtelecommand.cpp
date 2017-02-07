#include "qtelecommand.h"
#include <QThread>
#include <iomanip>


#include<iostream>
#include <QSound.h>
#include <QElapsedTimer>
#include <QShortcut>

using namespace std;
QSound bells("err.wav");


QTelecommand::QTelecommand(QWidget *parent) :
    QWidget(parent)
{

    panel = new QWidget(this);
    QPalette paletteM(QColor(100,120,135));
    panel->setPalette(paletteM);
    QGraphicsOpacityEffect *op=new QGraphicsOpacityEffect(this);
    op->setOpacity(0.75) ;
    panel->setAutoFillBackground(true);
    panel->setGraphicsEffect(op);
    panel->show();

    label = new QLabel(this);
    label->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/panelTelecommande.png"));
    label->show();

    //Création du boutonTetaP1
    boutonTetaP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP1Off.png"));
    boutonTetaP1.setParent(this);
    boutonTetaP1.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonTetaP1, SIGNAL(clicked()), this, SLOT(TetaP1Clicked()));
    QObject::connect(&boutonTetaP1, SIGNAL(released()), this, SLOT(TetaP1Unclicked()));
    boutonTetaP1.setDisabled(true);
    boutonTetaP1.show();

    //Création du boutonTetaP2
    boutonTetaP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP2Off.png"));
    boutonTetaP2.setParent(this);
    boutonTetaP2.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonTetaP2, SIGNAL(clicked()), this, SLOT(TetaP2Clicked()));
    QObject::connect(&boutonTetaP2, SIGNAL(released()), this, SLOT(TetaP2Unclicked()));
    boutonTetaP2.setDisabled(true);
    boutonTetaP2.show();

    //Création du boutonTetaM1
    boutonTetaM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM1Off.png"));
    boutonTetaM1.setParent(this);
    boutonTetaM1.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonTetaM1, SIGNAL(clicked()), this, SLOT(TetaM1Clicked()));
    QObject::connect(&boutonTetaM1, SIGNAL(released()), this, SLOT(TetaM1Unclicked()));
    boutonTetaM1.setDisabled(true);
    boutonTetaM1.show();

    //Création du boutonTetaM2
    boutonTetaM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM2Off.png"));
    boutonTetaM2.setParent(this);
    boutonTetaM2.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonTetaM2, SIGNAL(clicked()), this, SLOT(TetaM2Clicked()));
    QObject::connect(&boutonTetaM2, SIGNAL(released()), this, SLOT(TetaM2Unclicked()));
    boutonTetaM2.setDisabled(true);
    boutonTetaM2.show();

    //Création du boutonTetaP1
    boutonPhiP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1Off.png"));
    boutonPhiP1.setParent(this);
    boutonPhiP1.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonPhiP1, SIGNAL(clicked()), this, SLOT(PhiP1Clicked()));
    QObject::connect(&boutonPhiP1, SIGNAL(released()), this, SLOT(PhiP1Unclicked()));
    boutonPhiP1.setDisabled(true);
    boutonPhiP1.show();

    //Création du boutonPhiP2
    boutonPhiP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2Off.png"));
    boutonPhiP2.setParent(this);
    boutonPhiP2.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonPhiP2, SIGNAL(clicked()), this, SLOT(PhiP2Clicked()));
    QObject::connect(&boutonPhiP2, SIGNAL(released()), this, SLOT(PhiP2Unclicked()));
    boutonPhiP2.setDisabled(true);
    boutonPhiP2.show();

    //Création du boutonPhiM1
    boutonPhiM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1Off.png"));
    boutonPhiM1.setParent(this);
    boutonPhiM1.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonPhiM1, SIGNAL(clicked()), this, SLOT(PhiM1Clicked()));
    QObject::connect(&boutonPhiM1, SIGNAL(released()), this, SLOT(PhiM1Unclicked()));
    boutonPhiM1.setDisabled(true);
    boutonPhiM1.show();

    //Création du boutonPhiM2
    boutonPhiM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2Off.png"));
    boutonPhiM2.setParent(this);
    boutonPhiM2.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonPhiM2, SIGNAL(clicked()), this, SLOT(PhiM2Clicked()));
    QObject::connect(&boutonPhiM2, SIGNAL(released()), this, SLOT(PhiM2Unclicked()));
    boutonPhiM2.setDisabled(true);
    boutonPhiM2.show();

    //Création du boutonTPStop
    boutonTPStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOff.png"));
    boutonTPStop.setParent(this);
    boutonTPStop.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonTPStop, SIGNAL(clicked()), this, SLOT(TPStopClicked()));
    QObject::connect(&boutonTPStop, SIGNAL(released()), this, SLOT(TPStopUnclicked()));
    boutonTPStop.setDisabled(true);
    boutonTPStop.show();



    //Création du boutonZP1
    boutonZP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1Off.png"));
    boutonZP1.setParent(this);
    boutonZP1.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonZP1, SIGNAL(clicked()), this, SLOT(ZP1Clicked()));
    QObject::connect(&boutonZP1, SIGNAL(released()), this, SLOT(ZP1Unclicked()));
    boutonZP1.setDisabled(true);
    boutonZP1.show();

    //Création du boutonZP2
    boutonZP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2Off.png"));
    boutonZP2.setParent(this);
    boutonZP2.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonZP2, SIGNAL(clicked()), this, SLOT(ZP2Clicked()));
    QObject::connect(&boutonZP2, SIGNAL(released()), this, SLOT(ZP2Unclicked()));
    boutonZP2.setDisabled(true);
    boutonZP2.show();

    //Création du boutonZM1
    boutonZM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1Off.png"));
    boutonZM1.setParent(this);
    boutonZM1.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonZM1, SIGNAL(clicked()), this, SLOT(ZM1Clicked()));
    QObject::connect(&boutonZM1, SIGNAL(released()), this, SLOT(ZM1Unclicked()));
    boutonZM1.setDisabled(true);
    boutonZM1.show();

    //Création du boutonZM2
    boutonZM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2Off.png"));
    boutonZM2.setParent(this);
    boutonZM2.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonZM2, SIGNAL(clicked()), this, SLOT(ZM2Clicked()));
    QObject::connect(&boutonZM2, SIGNAL(released()), this, SLOT(ZM2Unclicked()));
    boutonZM2.setDisabled(true);
    boutonZM2.show();

    //Création du boutonZStop
    boutonZStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOff.png"));
    boutonZStop.setParent(this);
    boutonZStop.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonZStop, SIGNAL(clicked()), this, SLOT(ZStopClicked()));
    QObject::connect(&boutonZStop, SIGNAL(released()), this, SLOT(ZStopUnclicked()));
    boutonZStop.setDisabled(true);
    boutonZStop.show();

    //Création du bouton Go
    boutonGo.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonGooff.png"));
    boutonGo.setParent(this);
    QObject::connect(&boutonGo, SIGNAL(clicked()), this, SLOT(GalilGo()));
    boutonGo.show();


    //Création des 3 zones de saisi text
    QFont policePar2("Times", 9, QFont::Normal, false);
    lineEditTeta = new MyLineEdit();
    lineEditTeta->setParent(this);
    lineEditTeta->setStyleSheet("color: \"#7A7A7A\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    lineEditTeta->setFont(policePar2);
    QObject::connect(lineEditTeta, SIGNAL(textChanged(const QString &)), this, SLOT(SaveTeta()));
    QObject::connect(lineEditTeta, SIGNAL(clicked()), this, SLOT(TimerTetaStop()));
    QObject::connect(lineEditTeta, SIGNAL(keyPressed()), this, SLOT(TimerTetaStop()));
    lineEditTeta->setDisabled(true);

    lineEditPhi = new MyLineEdit();
    lineEditPhi->setParent(this);
    lineEditPhi->setStyleSheet("color: \"#7A7A7A\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    lineEditPhi->setFont(policePar2);
    QObject::connect(lineEditPhi, SIGNAL(textChanged(const QString &)), this, SLOT(SavePhi()));
    QObject::connect(lineEditPhi, SIGNAL(clicked()), this, SLOT(TimerPhiStop()));
    QObject::connect(lineEditPhi, SIGNAL(keyPressed()), this, SLOT(TimerPhiStop()));
    lineEditPhi->setDisabled(true);



    lineEditZ = new MyLineEdit();
    lineEditZ->setParent(this);
    lineEditZ->setStyleSheet("color: \"#7A7A7A\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    lineEditZ->setFont(policePar2);
    QObject::connect(lineEditZ, SIGNAL(textChanged(const QString &)), this, SLOT(SaveZ()));
    QObject::connect(lineEditZ, SIGNAL(clicked()), this, SLOT(TimerZStop()));
    QObject::connect(lineEditZ, SIGNAL(keyPressed()), this, SLOT(TimerZStop()));
    lineEditZ->setDisabled(true);


    //pour la mise à jour des valeurs lorsque l'on utilise les boutons
    timerTeta = new QTimer(this);
    timerTeta->setInterval(10);
    QObject::connect(timerTeta, SIGNAL(timeout()),this, SLOT(MajLineEditTeta()));

    timerPhi = new QTimer(this);
    timerPhi->setInterval(10);
    QObject::connect(timerPhi, SIGNAL(timeout()),this, SLOT(MajLineEditPhi()));

    timerZ = new QTimer(this);
    timerZ->setInterval(10);
    QObject::connect(timerZ, SIGNAL(timeout()),this, SLOT(MajLineEditZ()));

    timerTestPhiM = new QTimer(this);
    timerTestPhiM->setInterval(10);
    QObject::connect(timerTestPhiM, SIGNAL(timeout()),this, SLOT(TestMajPhiM()));
    timerTestPhiP = new QTimer(this);
    timerTestPhiP->setInterval(10);
    QObject::connect(timerTestPhiP, SIGNAL(timeout()),this, SLOT(TestMajPhiP()));
    timerTestZM = new QTimer(this);
    timerTestZM->setInterval(10);
    QObject::connect(timerTestZM, SIGNAL(timeout()),this, SLOT(TestMajZM()));
    timerTestZP = new QTimer(this);
    timerTestZP->setInterval(10);
    QObject::connect(timerTestZP, SIGNAL(timeout()),this, SLOT(TestMajZP()));

    SizeWinElements();

}

void QTelecommand::SizeWinElements()
//Permet de modifier la taille de chaque élément en fonction de la taille de la fenêtre (l,h)
{
    label->setGeometry(0,2,255,414);
    panel->setGeometry(0,10,255,414);

    int h=-24,l1=1,l2=-28;

    boutonTetaM1.setGeometry(61+l1,130+h,30,30);
    boutonTetaM2.setGeometry(28+l1,130+h,30,30);
    boutonTetaP1.setGeometry(119+l1,130+h,30,30);
    boutonTetaP2.setGeometry(152+l1,130+h,30,30);

    boutonPhiM1.setGeometry(90+l1,159+h,30,30);
    boutonPhiM2.setGeometry(90+l1,192+h,30,30);
    boutonPhiP1.setGeometry(90+l1,101+h,30,30);
    boutonPhiP2.setGeometry(90+l1,68+h,30,30);

    boutonTPStop.setGeometry(88+l1,128+h,30,30);

    boutonZM1.setGeometry(235+l2,157+h,30,30);
    boutonZM2.setGeometry(235+l2,192+h,30,30);
    boutonZP1.setGeometry(235+l2,103+h,30,30);
    boutonZP2.setGeometry(235+l2,68+h,30,30);

    boutonZStop.setGeometry(233+l2,128+h,30,30);

    boutonGo.setGeometry(185,283,54,112);
    lineEditTeta->setGeometry(65,283,105,30);
    lineEditPhi->setGeometry(65,324,105,30);
    lineEditZ->setGeometry(65,365,105,30);


}

void QTelecommand::TelecommandON()
{
    timerTeta->start();
    timerPhi->start();
    timerZ->start();

    m_OnOff=1;
    boutonTetaP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP1On.png"));
    boutonTetaP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP2On.png"));
    boutonTetaM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM1On.png"));
    boutonTetaM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM2On.png"));
    boutonPhiP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1On.png"));
    boutonPhiP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2On.png"));
    boutonPhiM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1On.png"));
    boutonPhiM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2On.png"));
    boutonTPStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOn.png"));
    boutonZP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1On.png"));
    boutonZP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2On.png"));
    boutonZM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1On.png"));
    boutonZM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2On.png"));
    boutonZStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOn.png"));
    boutonGo.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonGOon.png"));
    //fond->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/panelTelecommandeOn.png"));

    boutonTetaP1.setEnabled(true);
    boutonTetaP2.setEnabled(true);
    boutonTetaM1.setEnabled(true);
    boutonTetaM2.setEnabled(true);
    boutonPhiP1.setEnabled(true);
    boutonPhiP2.setEnabled(true);
    boutonPhiM1.setEnabled(true);
    boutonPhiM2.setEnabled(true);
    boutonTPStop.setEnabled(true);
    boutonZP1.setEnabled(true);
    boutonZP2.setEnabled(true);
    boutonZM1.setEnabled(true);
    boutonZM2.setEnabled(true);
    boutonZStop.setEnabled(true);
    boutonGo.setCursor(Qt::PointingHandCursor);
    lineEditTeta->setEnabled(true);
    lineEditPhi->setEnabled(true);
    lineEditZ->setEnabled(true);
    lineEditTeta->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
    lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
    lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
}

void QTelecommand::TelecommandOFF()
{
    timerTeta->stop();
    timerPhi->stop();
    timerZ->stop();

    m_OnOff=0;
    boutonTetaP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP1Off.png"));
    boutonTetaP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP2Off.png"));
    boutonTetaM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM1Off.png"));
    boutonTetaM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM2Off.png"));
    boutonPhiP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1Off.png"));
    boutonPhiP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2Off.png"));
    boutonPhiM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1Off.png"));
    boutonPhiM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2Off.png"));
    boutonTPStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOff.png"));
    boutonZP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1Off.png"));
    boutonZP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2Off.png"));
    boutonZM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1Off.png"));
    boutonZM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2Off.png"));
    boutonZStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOff.png"));
    boutonGo.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonGOoff.png"));
    //fond->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/panelTelecommandeOff.png"));

    boutonTetaP1.setDisabled(true);
    boutonTetaP2.setDisabled(true);
    boutonTetaM1.setDisabled(true);
    boutonTetaM2.setDisabled(true);
    boutonPhiP1.setDisabled(true);
    boutonPhiP2.setDisabled(true);
    boutonPhiM1.setDisabled(true);
    boutonPhiM2.setDisabled(true);
    boutonTPStop.setDisabled(true);
    boutonZP1.setDisabled(true);
    boutonZP2.setDisabled(true);
    boutonZM1.setDisabled(true);
    boutonZM2.setDisabled(true);
    boutonZStop.setDisabled(true);
    boutonGo.setCursor(Qt::ArrowCursor);
    lineEditTeta->setDisabled(true);
    lineEditPhi->setDisabled(true);
    lineEditZ->setDisabled(true);
    lineEditTeta->setStyleSheet("color: \"#7A7A7A\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    lineEditPhi->setStyleSheet("color: \"#7A7A7A\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    lineEditZ->setStyleSheet("color: \"#7A7A7A\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
}

void QTelecommand::Link(GCon &g)
{
    m_g=g;
}


void QTelecommand::Wait(float msec)
{
    QElapsedTimer timer;
    timer.start();

    while(timer.hasExpired(msec)==0)
        QCoreApplication::processEvents();
}

void QTelecommand::TetaP1Clicked()
{
    if(m_OnOff)
    {
        if(timerTeta->isActive()==0)  timerTeta->start();
        boutonTetaP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP1Clicked.png"));
        std::stringstream com; com<<"SPA="<<vitesse_theta_lente;
        GCmd(m_g,com.str().c_str());
        GCmd(m_g,"PRA=880000");
        GCmd(m_g,"BGA");
    }
}

void QTelecommand::TetaP1Unclicked()
{
    if(m_OnOff)
    {
        GCmd(m_g,"ST");
        boutonTetaP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP1On.png"));
        lineEditTeta->setFocus();
    }
}

void QTelecommand::TetaP2Clicked()
{
    if(m_OnOff)
    {
        if(timerTeta->isActive()==0)  timerTeta->start();
        boutonTetaP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP2Clicked.png"));
        std::stringstream com;  com<<"SPA="<<vitesse_theta_rapide;
        GCmd(m_g,com.str().c_str());
        GCmd(m_g,"PRA=880000");
        GCmd(m_g,"BGA");
    }
}

void QTelecommand::TetaP2Unclicked()
{
    if(m_OnOff)
    {
        GCmd(m_g,"ST");
        boutonTetaP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaP2On.png"));
        lineEditTeta->setFocus();
    }
}

void QTelecommand::TetaM1Clicked()
{
    if(m_OnOff)
    {
        if(timerTeta->isActive()==0)  timerTeta->start();
        boutonTetaM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM1Clicked.png"));
        std::stringstream com; com<<"SPA="<<vitesse_theta_lente;
        GCmd(m_g,com.str().c_str());
        GCmd(m_g,"PRA=-880000");
        GCmd(m_g,"BGA");
    }
}
void QTelecommand::TetaM1Unclicked()
{
    if(m_OnOff)
    {
        GCmd(m_g,"ST");
        boutonTetaM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM1On.png"));
        lineEditTeta->setFocus();
    }
}

void QTelecommand::TetaM2Clicked()
{
    if(m_OnOff)
    {
        if(timerTeta->isActive()==0)  timerTeta->start();
        boutonTetaM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM2Clicked.png"));
        std::stringstream com; com<<"SPA="<<vitesse_theta_rapide;
        GCmd(m_g,com.str().c_str());
        GCmd(m_g,"PRA=-880000");
        GCmd(m_g,"BGA");
    }
}
void QTelecommand::TetaM2Unclicked()
{
    if(m_OnOff)
    {
        GCmd(m_g,"ST");
        boutonTetaM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/TetaM2On.png"));
        lineEditTeta->setFocus();
    }
}

void QTelecommand::PhiP1Clicked()
{
    if(m_OnOff)
    {
        if(timerPhi->isActive()==0)  timerPhi->start();
        boutonPhiP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1Clicked.png"));
        std::stringstream com; com<<"SPD="<<vitesse_phi_lente;
        GCmd(m_g,com.str().c_str());

        timerTestPhiP->start();
        GalilGoPhi(*bPhiMax);
    }
}
void QTelecommand::PhiP1Unclicked()
{
    if(m_OnOff)
    {
        boutonPhiP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1On.png"));
        if(timerTestPhiP->isActive())
        {
            GCmd(m_g,"ST");
            timerTestPhiP->stop();
        }
        lineEditPhi->setFocus();
    }
}

void QTelecommand::PhiP2Clicked()
{
    if(m_OnOff)
    {
        if(timerPhi->isActive()==0)  timerPhi->start();
        boutonPhiP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2Clicked.png"));
        std::stringstream com; com<<"SPD="<<vitesse_phi_rapide;
        GCmd(m_g,com.str().c_str());

        timerTestPhiP->start();
        GalilGoPhi(*bPhiMax);
    }
}
void QTelecommand::PhiP2Unclicked()
{
    if(m_OnOff)
    {
        boutonPhiP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2On.png"));
        if(timerTestPhiP->isActive())
        {
            GCmd(m_g,"ST");
            timerTestPhiP->stop();
        }
        lineEditPhi->setFocus();
    }
}
void QTelecommand::PhiM1Clicked()
{
    if(m_OnOff)
    {
        if(timerPhi->isActive()==0)  timerPhi->start();
        boutonPhiM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1Clicked.png"));
        std::stringstream com; com<<"SPD="<<vitesse_phi_lente;
        GCmd(m_g,com.str().c_str());

        timerTestPhiM->start();
        GalilGoPhi(*bPhiMin);
    }
}
void QTelecommand::PhiM1Unclicked()
{
    if(m_OnOff)
    {
        boutonPhiM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1On.png"));
        if(timerTestPhiM->isActive())
        {
            GCmd(m_g,"ST");
            timerTestPhiM->stop();
        }
        lineEditPhi->setFocus();
    }
}

void QTelecommand::PhiM2Clicked()
{
    if(m_OnOff)
    {
        if(timerPhi->isActive()==0)  timerPhi->start();

        boutonPhiM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2Clicked.png"));
        std::stringstream com; com<<"SPD="<<vitesse_phi_rapide;
        GCmd(m_g,com.str().c_str());

        timerTestPhiM->start();
        GalilGoPhi(*bPhiMin);
    }
}
void QTelecommand::PhiM2Unclicked()
{
    if(m_OnOff)
    {
        boutonPhiM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2On.png"));
        if(timerTestPhiM->isActive())
        {
            GCmd(m_g,"ST");
            timerTestPhiM->stop();
        }
        lineEditPhi->setFocus();
    }
}

void QTelecommand::TPStopClicked()
{
    if(m_OnOff)
    {
        boutonTPStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopClicked.png"));
        GCmd(m_g,"ST");
    }
}
void QTelecommand::TPStopUnclicked()
{
    if(m_OnOff)
    {
        boutonTPStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOn.png"));
    }
}

void QTelecommand::ZP1Clicked()
{
    if(m_OnOff)
    {
        if(timerZ->isActive()==0)  timerZ->start();

        boutonZP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1Clicked.png"));
        std::stringstream com; com<<"SPB="<<vitesse_Z_lente;
        GCmd(m_g,com.str().c_str());

        timerTestZP->start();
        GalilGoZ(*bZMin);
    }
}
void QTelecommand::ZP1Unclicked()
{
    if(m_OnOff)
    {
        boutonZP1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP1On.png"));
        if(timerTestZP->isActive())
        {
            GCmd(m_g,"ST");
            timerTestZP->stop();
        }
        lineEditZ->setFocus();
    }
}

void QTelecommand::ZP2Clicked()
{
    if(m_OnOff)
    {
        if(timerZ->isActive()==0)  timerZ->start();

        boutonZP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2Clicked.png"));
        std::stringstream com; com<<"SPB="<<vitesse_Z_rapide;
        GCmd(m_g,com.str().c_str());

        timerTestZP->start();
        GalilGoZ(*bZMin);
    }
}
void QTelecommand::ZP2Unclicked()
{
    if(m_OnOff)
    {
        boutonZP2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiP2On.png"));
        if(timerTestZP->isActive())
        {
            GCmd(m_g,"ST");
            timerTestZP->stop();
        }
        lineEditZ->setFocus();
    }
}

void QTelecommand::ZM1Clicked()
{
    if(m_OnOff)
    {
        if(timerZ->isActive()==0)  timerZ->start();

        boutonZM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1Clicked.png"));
        std::stringstream com; com<<"SPB="<<vitesse_Z_lente;
        GCmd(m_g,com.str().c_str());

        timerTestZM->start();
        GalilGoZ(*bZMax);
    }
}
void QTelecommand::ZM1Unclicked()
{
    if(m_OnOff)
    {
        boutonZM1.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM1On.png"));
        if(timerTestZM->isActive())
        {
            GCmd(m_g,"ST");
            timerTestZM->stop();
         }
        lineEditZ->setFocus();
     }
}

void QTelecommand::ZM2Clicked()
{
    if(m_OnOff)
    {
        if(timerZ->isActive()==0)  timerZ->start();

        boutonZM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2Clicked.png"));
        std::stringstream com; com<<"SPB="<<vitesse_Z_rapide;
        GCmd(m_g,com.str().c_str());

        timerTestZM->start();
        GalilGoZ(*bZMax);
    }
}
void QTelecommand::ZM2Unclicked()
{
    if(m_OnOff)
    {
        boutonZM2.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/PhiM2On.png"));
        if(timerTestZM->isActive())
        {
            GCmd(m_g,"ST");
            timerTestZM->stop();
        }
        lineEditZ->setFocus();
    }
}

void QTelecommand::ZStopClicked()
{
    if(m_OnOff)
    {
        boutonZStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopClicked.png"));
        GCmd(m_g,"ST");
    }
}
void QTelecommand::ZStopUnclicked()
{
    if(m_OnOff)
    {
        boutonZStop.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/StopOn.png"));
    }
}


void QTelecommand::GalilGo()
{
    if(m_OnOff)
    {
        double thetaValue=lineEditTeta->text().toDouble();
        double phiValue=lineEditPhi->text().toDouble();
        double zValue=lineEditZ->text().toDouble();

        int thetaMiss=0;
        if(0>thetaValue)
        {
            bells.play();

            thetaMiss=1;
            thetaValue=0;
        }
        if(360<thetaValue)
        {
            bells.play();

            thetaMiss=1;
            thetaValue=360;
        }

        int thetaAfter=thetaValue*pas_unit_theta;
        int thetaBefore=ReadGalilTeta();
        int thetaMoove=(thetaAfter-thetaBefore);
        thetaMoove=thetaMoove%440000;


        int phiMiss=0;
        if(*bPhiMin>phiValue)
        {
            bells.play();

            phiMiss=1;
            phiValue=*bPhiMin;
        }
        if(*bPhiMax<phiValue)
        {
            bells.play();

            phiMiss=1;
            phiValue=*bPhiMax;
        }

        int phiAfter=(phiValue-ecartPhi)*pas_unit_phi*-1;
        int phiBefore=ReadGalilPhi();
        int phiMoove=(phiAfter-phiBefore);


        int zMiss=0;
        if(*bZMin>zValue)
        {
            bells.play();

            zMiss=1;
            zValue=*bZMin;
        }
        if(*bZMax<zValue)
        {
            bells.play();

            zMiss=1;
            zValue=*bZMax;
        }

        QString sTeta=" "+QString::number(thetaValue,'f',3);
        QString sPhi=" "+QString::number(phiValue,'f',3);
        QString sZ=" "+QString::number(zValue,'f',3);

        lineEditTeta->setText(sTeta);
        lineEditPhi->setText(sPhi);
        lineEditZ->setText(sZ);

        int zAfter=zValue*pas_unit_Z;
        int zBefore=ReadGalilZ();
        int zMoove=(zAfter-zBefore);


        if(thetaMiss)   lineEditTeta->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
        if(phiMiss)     lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
        if(zMiss)       lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
        lineEditTeta->repaint(); lineEditZ->repaint(); lineEditPhi->repaint();
        Wait(150);
        if(thetaMiss)   lineEditTeta->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
        if(phiMiss)     lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
        if(zMiss)       lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
        lineEditTeta->repaint(); lineEditZ->repaint(); lineEditPhi->repaint();
        Wait(150);
        if(thetaMiss)   lineEditTeta->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
        if(phiMiss)     lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
        if(zMiss)       lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
        lineEditTeta->repaint(); lineEditZ->repaint(); lineEditPhi->repaint();
        Wait(300);
        if(thetaMiss)   lineEditTeta->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
        if(phiMiss)     lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
        if(zMiss)       lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");


        //Mettre en vitesse rapide
        std::stringstream comA; comA<<"SPA="<<vitesse_theta_rapide;
        GCommand(m_g,comA.str().c_str(),buf, sizeof(buf), 0);

        std::stringstream comB; comB<<"SPB="<<vitesse_Z_rapide;
        GCommand(m_g,comB.str().c_str(),buf, sizeof(buf), 0);

        std::stringstream comD; comD<<"SPD="<<vitesse_phi_rapide;
        GCommand(m_g,comD.str().c_str(),buf, sizeof(buf), 0);


        //Appliquer position
        std::stringstream com; com<<"PRA="<<thetaMoove;
        GCmd(m_g,com.str().c_str());
        GCmd(m_g,"BGA");

        std::stringstream com2; com2<<"PRD="<<phiMoove;
        GCmd(m_g,com2.str().c_str());
        GCmd(m_g,"BGD");

        std::stringstream com3; com3<<"PRB="<<zMoove;
        GCmd(m_g,com3.str().c_str());
        GCmd(m_g,"BGB");


    }
}

void QTelecommand::GalilGoPhi(double phiValue)
{
    int pos=(phiValue-ecartPhi)*pas_unit_phi*-1;

    std::stringstream com; com<<"PAD="<<pos;
    GCmd(m_g,com.str().c_str());
    GCmd(m_g,"BGD");
}


void QTelecommand::GalilGoZ(double zValue)
{
    int pos=zValue*pas_unit_Z;

    std::stringstream com; com<<"PAB="<<pos;
    GCmd(m_g,com.str().c_str());
    GCmd(m_g,"BGB");
}

void QTelecommand::TestMajPhiM()
{
     if(lineEditPhi->text().toDouble()<*bPhiMin+0.001)
     {
         timerTestPhiM->stop();
         bells.play();

         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
         Wait(150);
         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
         Wait(150);
         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
         Wait(300);
         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
     }
}

void QTelecommand::TestMajPhiP()
{
     if(lineEditPhi->text().toDouble()>*bPhiMax-0.001)
     {
         timerTestPhiP->stop();
         bells.play();

         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
         Wait(150);
         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
         Wait(150);
         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
         Wait(300);
         lineEditPhi->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditPhi->repaint();
     }
}


void QTelecommand::TestMajZM()
{
     if(lineEditZ->text().toDouble()>*bZMax-0.01)
     {
         timerTestZM->stop();
         bells.play();

         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditZ->repaint();
         Wait(150);
         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditZ->repaint();
         Wait(150);
         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditZ->repaint();
         Wait(300);
         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditZ->repaint();
     }
}


void QTelecommand::TestMajZP()
{
     if(lineEditZ->text().toDouble()<*bZMin+0.01)
     {
         timerTestZP->stop();
         bells.play();

         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditZ->repaint();
         Wait(150);
         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditZ->repaint();
         Wait(150);
         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#FF0000\"; background-color: \"#425460\"");
         lineEditZ->repaint();
         Wait(300);
         lineEditZ->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
         lineEditZ->repaint();
     }
}

void QTelecommand::SaveTeta()
{
    tetaForGo=lineEditTeta->text().toDouble();
}

void QTelecommand::SavePhi()
{
    phiForGo=lineEditPhi->text().toDouble();
}

void QTelecommand::SaveZ()
{
    zForGo=lineEditZ->text().toDouble();
}


void QTelecommand::MajLineEditTeta()
{
    double f=ReadGalilTeta()/(double)pas_unit_theta;
    int i=(qRound(f));  //extraction de la partie entière
    float res=f-i;      //extraction de la partie décimale car % ne marche que sur int
    i=i%360;            //résultat compris entre -360 et 360 en int
    res+=i;             //résultat compris entre -360 et 360 avec décimale
    if(res<0)res+=360;  //résultat compris entre 0 et 360 avec décimale

    QString s=" "+QString::number(res,'f',3);
    lineEditTeta->setText(s);//->setText(QString::number(res));
}

int QTelecommand::ReadGalilTeta()
{
    int value;
    GCommand(m_g,"TPA",buf, sizeof(buf), 0);
    std::stringstream strValue; strValue << buf; strValue >> value;

return value;
}

void QTelecommand::MajLineEditPhi()
{
    double f=ReadGalilPhi()/(double)pas_unit_phi;
    double fReel=-f+ecartPhi;
    QString s=" "+QString::number(fReel,'f',3);
    lineEditPhi->setText(s);
}
int QTelecommand::ReadGalilPhi()
{
    int value;
    GCommand(m_g,"TPD",buf, sizeof(buf), 0);
    std::stringstream strValue; strValue << buf; strValue >> value;

return value;
}

void QTelecommand::MajLineEditZ()
{
    double f=ReadGalilZ()/(double)pas_unit_Z;
    QString s=" "+QString::number(f,'f',3);
    lineEditZ->setText(s);
}
int QTelecommand::ReadGalilZ()
{
    int value;
    GCommand(m_g,"TPB",buf, sizeof(buf), 0);
    std::stringstream strValue; strValue << buf; strValue >> value;

return value;
}

void QTelecommand::TimerPhiStop()
{
timerPhi->stop();
}
void QTelecommand::TimerTetaStop()
{
timerTeta->stop();
}
void QTelecommand::TimerZStop()
{
timerZ->stop();
}
