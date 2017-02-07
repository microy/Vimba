
#include "mainwindow.h"
#include "ui_mainwindow.h"

GCon g = 0; //var used to refer to a unique connection
int a = 0;

#include<QCoreApplication>
#include<iostream>
#include<QtWidgets>
#include <QThread>
#include <sstream>
#include<QtMath>

#include <QCoreApplication>
//#include "VimbaCPP/Include/VimbaCPP.h"
#include <iostream>

//using namespace std;
//using namespace AVT::VmbAPI;
//#include "listcameras.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("X-RTI");


    QRect rec = QDesktopWidget().availableGeometry();
    int hauteur = rec.height();
    int largeur = rec.width();


    //Barre de menu
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QMenu *menuOption = menuBar()->addMenu("&Option");
    QMenu *menuAide = menuBar()->addMenu("&Aide");

    QAction *actionQuitter = new QAction("&Quitter", this);
        menuFichier->addAction(actionQuitter);
        connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
        actionQuitter->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/image/quitter.png"));

    actionopTelecommand = new QAction("&Configuration télécommande", this);
        menuOption->addAction(actionopTelecommand);
        connect(actionopTelecommand, SIGNAL(triggered()), this, SLOT(OpenOpTelecommand()));
        actionopTelecommand->setDisabled(true);
        //actionAPropos->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/image/quitter.png"));


    QAction *actionAPropos = new QAction("&A propos", this);
        menuAide->addAction(actionAPropos);
        connect(actionAPropos, SIGNAL(triggered()), this, SLOT(OpenApropos()));
        //actionAPropos->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/image/quitter.png"));


    //Ecran fond
    labelFond = new QLabel(this);
    labelFond->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/EcranFond.png"));
    labelFond->setParent(this);
    labelFond->show();

    //Panel Connection
    panelStatut = new QWidget(this);
    QPalette paletteM(QColor(100,120,135));
    panelStatut->setPalette(paletteM);
    QGraphicsOpacityEffect *op=new QGraphicsOpacityEffect(this);
    op->setOpacity(0.75) ;
    panelStatut->setAutoFillBackground(true);
    panelStatut->setGraphicsEffect(op);
    panelStatut->show();

    whiteLine = new QWidget(this);
    QPalette paletteW(QColor(255,255,255));
    whiteLine->setPalette(paletteW);
    whiteLine->setAutoFillBackground(true);
    whiteLine->show();


    //Barre d'état
    labelBarreEtat = new QLabel(this);
    QPalette pal=QPalette(QColor(214,221,239));
    labelBarreEtat->setPalette(pal);
    labelBarreEtat->setAutoFillBackground(true);
    labelBarreEtat->show();
    QFont policePar("Calibri", 9, QFont::Normal, false);
    labeltextBarreEtat = new QLabel(this);
    labeltextBarreEtat->setFont(policePar);
    labeltextBarreEtat->setText(QApplication::translate("this", "<font color=\"#000000\">Statut : &nbsp;&nbsp;&nbsp;Déconnecté</font>" "\n" , 0,0));


    //Création du bouton Connect
    boutonConnect.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonConnectStart.png"));
    boutonConnect.setParent(this);
    boutonConnect.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonConnect, SIGNAL(clicked()), this, SLOT(Connect()));
    boutonConnect.show();

    //Création du bouton GalilStatut
    galilStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/GalilStart.png"));
    galilStatut.setParent(this);
    QObject::connect(&galilStatut, SIGNAL(clicked()), this, SLOT(GalilMooveTest()));
    galilStatut.show();

    //Création du bouton LedStatut
    ledStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/LedStart.png"));
    ledStatut.setParent(this);
    QObject::connect(&ledStatut, SIGNAL(clicked()), this, SLOT(GalilLedTest()));
    ledStatut.show();

    //Création du bouton CamStatut
    camStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/CamStart.png"));
    camStatut.setParent(this);
    QObject::connect(&camStatut, SIGNAL(clicked()), this, SLOT(CamTest()));
    camStatut.show();

    //Création de la télécommande
    tCommand = new QTelecommand();
    tCommand->setParent(this);
    tCommand->show();

    //Création de panel du process
    processPanel = new QPanelProcess();
    processPanel->setParent(this);
    processPanel->show();

    aProposPanel = new Apropos(this);
    aProposPanel->hide();

    opTelecommandPanel = new OpTelecommand(this);
    opTelecommandPanel->hide();
//opTelecommandPanel->setWindowFlags(opTelecommandPanel->windowFlags() | Qt::Tool);

    panelOnglets = new QPanelOnglets();
    panelOnglets->setParent(this);
    panelOnglets->hide();

    SizeWinElements(largeur,hauteur);

}



MainWindow::~MainWindow()
{
    std::cout<<"CLOSE ..."<<std::endl;

    if(g!=0)   {std::cout<<"CLOSE GALIL"<<std::endl;GalilPositionZero();GClose(g);}

    //delete opTelecommandPanel;
    std::cout<<"CLOSE APPS"<<std::endl;
    delete ui;
}


//FONCTIONS D'INTERFACE
void MainWindow::SizeWinElements(int l, int h)
//Permet de modifier la taille de chaque élément en fonction de la taille de la fenêtre (l,h)
{
    l=1200;
    h=810;
    this->setFixedSize(l,h);
    labelFond->setGeometry(0,25,1920,1080);
    labelBarreEtat->setGeometry(0,h-25,l,25);
    labeltextBarreEtat->setGeometry(10,h-23,l,20);

    boutonConnect.setGeometry(l-255,50,235,65);
    whiteLine->setGeometry(l-255,130,235,1);

    tCommand->setGeometry(l-265,354,255,414);
    processPanel->setGeometry(10,40,l-290,h-80);

    panelStatut->setGeometry(l-265,40,255,309);
    ledStatut.setGeometry(l-255,213,235,58);
    camStatut.setGeometry(l-255,145,235,58);
    galilStatut.setGeometry(l-255,281,235,58);
    panelOnglets->setGeometry(10,40,910,730);


    processPanel->SizeWinElements();

}

void MainWindow::BoutonOff()
{
    boutonConnect.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonConnect.png"));
    ledStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/LedStart.png"));
    camStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/CamStart.png"));
    galilStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/GalilStart.png"));
    boutonConnect.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonConnectStart.png"));
    tCommand->TelecommandOFF();
    actionopTelecommand->setDisabled(true);
    panelOnglets->hide();
}

void MainWindow::BoutonOn()
{
    boutonConnect.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonConnectOnline.png"));
    tCommand->TelecommandON();
    actionopTelecommand->setEnabled(true);
    panelOnglets->show();
}



//FONCTIONS D'ACTIONS GALIL
void MainWindow::Connect()
//Se connecter/deconnecter à Galil
{
    setCursor(Qt::BusyCursor);
    boutonConnect.setCursor(Qt::BusyCursor);


    if (g==0)
    //pas de connection, alors on la crée
    {
        galilStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/GalilWait.png"));
        ledStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/LedWait.png"));
        camStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/CamWait.png"));
        boutonConnect.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonConnectWait.png"));

        galilStatut.repaint();
        ledStatut.repaint();
        camStatut.repaint();
        boutonConnect.repaint();

        labeltextBarreEtat->setText(QApplication::translate("this", "<font color=\"#000000\">Statut : &nbsp;&nbsp;&nbsp;Tentative de connection ...</font>" "\n" , 0,0));
        labeltextBarreEtat->repaint();
        QString statut=QString("<font color=\"#000000\">Statut :  ");



        //CONNECTION CAM
        //QThread::msleep(300);
        std::cout << "Tentative de connection a Vimba ..."<<std::endl;
        std::string camName=panelOnglets->Print();

        if (camName!="")
        {
            statut+=QString(" &nbsp;&nbsp;&nbsp;Vimba OK (10.129.61.102, ")+QString::fromStdString(camName)+QString(")");
            camStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/CamOnline.png"));
            camStatut.repaint();

            QGraphicsOpacityEffect *op=new QGraphicsOpacityEffect(this);
            op->setOpacity(1) ;
            processPanel->panel->setAutoFillBackground(true);
            processPanel->panel->setGraphicsEffect(op);
            processPanel->label->hide();
            panelOnglets->StartGrab();
        }
        else
        {
            statut+=QString(" &nbsp;&nbsp;&nbsp;Vimba ERREUR (aucune caméra détectée)");
            camStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/CamOffline.png"));
            camStatut.repaint();
        }



        //CONNECTION GALIL
        std::cout<<"Tentative de connection a Galil ..."<<std::endl;
        GReturn rc=GOpen("10.129.61.101 -d", &g); //Open a connection to Galil, store the identifier in g.

        if (rc == G_NO_ERROR)
        {
            InitGalil(g);

            tCommand->Link(g);
            opTelecommandPanel->LinkTelecommand(tCommand);
            ledStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/LedOnline.png"));
            ledStatut.repaint();
            QThread::msleep(300);

            galilStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/GalilOnline.png"));

            GInfo(g, buf, sizeof(buf));
            statut+=QString(" - Galil OK (%1)").arg(buf);
        }
        else
        {
            ledStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/LedOffline.png"));
            ledStatut.repaint();
            QThread::msleep(800);

            galilStatut.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/GalilOffline.png"));

            labeltextBarreEtat->setText(QApplication::translate("this", statut.toStdString().c_str() , 0,0));
            statut+=QString(" - Galil ERREUR (%1)").arg(rc);
        }




     //   if ((rc == G_NO_ERROR)&&(connect))
        {
            BoutonOn();
        }
     //   else
     //   {
            //BoutonOff();
      //      if(g!=0)                {g=0;GClose(g);     std::cout<<"Deconnexion Galil"<<std::endl;}
      //      boutonConnect.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonConnectOffline.png"));
      //  }

        statut+=QString("</font>");
        labeltextBarreEtat->setText(QApplication::translate("this", statut.toStdString().c_str() , 0,0));


    }
    else
    //une connection existe, on la ferme
    {
        std::cout<<"Deconnexion Galil"<<std::endl;
        labeltextBarreEtat->setText(QApplication::translate("this", "<font color=\"#000000\">Statut : &nbsp;&nbsp;&nbsp;Déconnecté</font>" "\n" , 0,0));

        GalilPositionZero();
        GClose(g);
        g=0;

        BoutonOff();
    }
    setCursor(Qt::ArrowCursor);
    boutonConnect.setCursor(Qt::ArrowCursor);


}


void MainWindow::InitGalil(GCon &g)
{
    tCommand->vitesse_Z_lente = 10000;
    tCommand->vitesse_Z_rapide = 40000;

    tCommand->vitesse_theta_lente = 15000;
    tCommand->vitesse_theta_rapide = 40000;

    tCommand->vitesse_phi_lente = 5000;
    tCommand->vitesse_phi_rapide = 15000;

    tCommand->pas_unit_phi = (2*232*1024)/(double)360;          // (2) signaux A et B, (232)  rapport de reduction  (1024) cts/rev du codeur
    tCommand->pas_unit_theta = 440000/(double)360;            // MO62PD : 4000 cts/rev   -->  1 tour <=> 440000 ps   --> 4,5° <=> 5500 ps
    tCommand->pas_unit_Z = 825000/(double)20;

    //initialisation des valeurs associées à l'axe Z
    GCmd(g,"SHB");  //alimentation moteur Z ON

    int OriginZ;
    GCommand(g,"TPB",buf, sizeof(buf), 0);  //Tell position axe Z
    stringstream strValue; strValue << buf; strValue >> OriginZ;


    //initialisation des valeurs associées aux axes phi et theta
    GCmd(g,"SHA");  //alimentation moteur A ON
    int OriginTheta;
    GCommand(g,"TPA",buf, sizeof(buf), 0);  //Tell position axe A
    stringstream strValue2; strValue2 << buf; strValue2 >> OriginTheta;


    GCmd(g,"SHD");  //alimentation moteur D ON
    int OriginPhi;
    GCommand(g,"TPD",buf, sizeof(buf), 0);  //Tell position axe D
    stringstream strValue3; strValue3 << buf; strValue3 >> OriginPhi;


    //initialisation entree sorties et parametres axes
    GCmd(g,"OP0");  //Set all Output to 0


    int epaisseur_cale = 18;
    double Ht_lat = epaisseur_cale + 17.5;   // (17.5 = demi-epaisseur arceau en mm)
    double Ht_axe_rot = 21.25; // cf CAO , hauteur de l'axe de rotation par rapport au plateau
    double H = Ht_lat - Ht_axe_rot;
    double R =  176.9;   // (rayon//interieu de l'arceau a l'endroit ou on place la cale
    double Angle_Phi_Origin = qRadiansToDegrees(qAtan(H/R));

    //Retour à l'origine  (si ce n'est pas deja le cas)
    GCommand(g,"TPD",buf, sizeof(buf), 0);
    stringstream strValue4; strValue4 << buf; strValue4 >> tCommand->pos_phi;

    GalilPositionZero();

    GCmd(g,"OP255");
    QThread::msleep(500);
    GCmd(g,"OP0");

}



void MainWindow::GalilPositionZero()
{
    //Déplacement à l'origine Z
    GCmd(g,"PAB=0");


    //Déplacement à l'origine theta
    int pos_A;
    GCommand(g,"TPA",buf, sizeof(buf), 0);
    stringstream strValue5; strValue5 << buf; strValue5 >> pos_A;


    int dep2Origin_theta = -(pos_A)%(int)(tCommand->pas_unit_theta*360);
    if (qAbs(dep2Origin_theta) > (tCommand->pas_unit_theta*360/2))
        dep2Origin_theta= tCommand->pas_unit_theta*360+ dep2Origin_theta;

    std::stringstream com4; com4<<"PRA="<<dep2Origin_theta;
    GCmd(g,com4.str().c_str());


    //Déplacement initial a la position phi =10°
    GCmd(g,"PAD=0");
    GCmd(g,"BGABD");

    QThread::msleep(qMax(qAbs(dep2Origin_theta/tCommand->vitesse_theta_rapide),qAbs(tCommand->pos_phi/tCommand->vitesse_phi_rapide)) +1);

    std::stringstream comA; comA<<"SPA="<<tCommand->vitesse_theta_rapide;
    GCommand(g,comA.str().c_str(),buf, sizeof(buf), 0);

    std::stringstream comB; comB<<"SPB="<<tCommand->vitesse_Z_rapide;
    GCommand(g,comB.str().c_str(),buf, sizeof(buf), 0);

    std::stringstream comD; comD<<"SPD="<<tCommand->vitesse_phi_rapide;
    GCommand(g,comD.str().c_str(),buf, sizeof(buf), 0);



    tCommand->lineEditTeta->setText(" 0.000");
    tCommand->lineEditPhi->setText(" 10.000");
    tCommand->lineEditZ->setText(" 0.000");
}



void MainWindow::GalilMooveTest()
//Galil Moove Test
{
    std::stringstream com; com<<"SPA="<<tCommand->vitesse_theta_lente;
    GCmd(g,com.str().c_str());
    GCmd(g,"PRA=10000");
    GCmd(g,"BGA");
}


void MainWindow::GalilLedTest()
//Galil LED Test
{
    GCmd(g,"OP255");
    QThread::msleep(500);
    GCmd(g,"OP0");
}


void MainWindow::CamTest()
//Cam Test
{
    std::cout << "/// Vimba API List Cameras Example ///"<<std::endl;
    panelOnglets->Print();

}

void MainWindow::OpenApropos()
{
    aProposPanel->setFixedSize(640,330);
    aProposPanel->show();
}


void MainWindow::OpenOpTelecommand()
{
    opTelecommandPanel->setFixedSize(700,680);
    opTelecommandPanel->show();
}

