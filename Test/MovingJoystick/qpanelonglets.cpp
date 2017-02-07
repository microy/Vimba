#include "qpanelonglets.h"


QPanelOnglets::QPanelOnglets(QWidget *parent) :
    QWidget(parent)
{
  /*  QLabel *labelImgF = new QLabel(this);
    QPalette pal=QPalette(QColor(40,50,60));
    labelImgF->setPalette(pal);
    labelImgF->setAutoFillBackground(true);
    labelImgF->show();
    labelImgF->setGeometry(0,0,609,400);

    QPixmap imgF(QCoreApplication::applicationDirPath() + "/image/EcranTitreAide.png");
    labelImg = new QLabel(this);
    labelImg->setPixmap(imgF);
    labelImg->setAutoFillBackground(true);
    labelImg->show();
    labelImg->setGeometry(0,0,620,432);*/


    // 1 : Créer le QTabWidget
    onglets = new QTabWidget(this);
    onglets->setGeometry(0, 0, 910, 730);


    // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;


    // 3 : Créer le contenu des pages de widgets
    QFile fichier(QCoreApplication::applicationDirPath() + "/form/onglets.txt");
    QString style;
    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fichier);
        style=in.readAll();
    }
    onglets->setStyleSheet(style);

    // Page 1
    QLabel *labelt = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">Valsal|Metrie est une application permettant la visualisation en 3D d'un ensemble de coupes parallèles contigües.</font>" "\n" , 0,0), page1);
    labelt->setGeometry(30,19,433,100);
    labelt->setAlignment(Qt::AlignJustify);
    labelt->setWordWrap(true);
  //  labelt->resize(433,100);
 /*   QLabel *labelt0 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">En plus de cette visualisation, il vous est possible d'obtenir une segmentation 3D d'un organe, ainsi qu'un ensemble de mesures vous permettant d'évaluer au mieux la santé des tissus visualisés.</font>" "\n" , 0,0), page1);
    labelt0->setGeometry(30,59,433,100);
    labelt0->setAlignment(Qt::AlignJustify);
    labelt0->setWordWrap(true);
    labelt0->resize(433,100);

    QPixmap imgA1(QCoreApplication::applicationDirPath() + "/image/Aide1.png");
    QLabel *label1 = new QLabel(page1);
    label1->setPixmap(imgA1);
    label1->setGeometry((503-331)/2,126,331,183);
    label1->show();*/







    // Page 2
    QPixmap imgA2(QCoreApplication::applicationDirPath() + "/image/boutonOuvrir.png");
    QLabel *label2 = new QLabel(page2);
    label2->setPixmap(imgA2);
    label2->setGeometry(25,15,140,140);
    label2->show();
    QLabel *labelt2 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">Cliquer sur ce bouton pour ouvrir un ensemble d'images formant un volume, c'est à dire, une suite de coupes contigües issues de l'examen d'un patient.<br><br>Pour sélectionner plusieurs fichiers, maintenir le bouton Shift du clavier enfoncé durant la sélection.</font>" "\n" , 0,0), page2);
    labelt2->setGeometry(185,23,270,130);
    labelt2->setAlignment(Qt::AlignJustify);
    labelt2->setWordWrap(true);
    labelt2->resize(285,130);


    QPixmap imgA3(QCoreApplication::applicationDirPath() + "/image/boutonAnalyse.png");
    QLabel *label3 = new QLabel(page2);
    label3->setPixmap(imgA3);
    label3->setGeometry(25,170,140,140);
    label3->show();
    QLabel *labelt3 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">Cliquer sur ce bouton pour obtenir une assistance au diagnostic. Il vous sera demandé de cliquer sur un organe, la segmentation et l'analyse de la forme obtenue est ensuite automatique.<br><br>Les résultats vous seront présentés dans la partie \"Analyses\" de l'application." "\n" , 0,0), page2);
    labelt3->setGeometry(185,185,270,130);
    labelt3->setAlignment(Qt::AlignJustify);
    labelt3->setWordWrap(true);
    labelt3->resize(285,130);


    // Page 3
    int h0=10;
    int w0=-10;
    int w1=-0;

    QLabel *labelImgLine = new QLabel(page3);
    QPalette palLine=QPalette(QColor(104,98,108));
    labelImgLine->setPalette(palLine);
    labelImgLine->setAutoFillBackground(true);
    labelImgLine->show();
    labelImgLine->setGeometry(251,0,1,360);


    QLabel *labelt4 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">Commandes en 3D" "\n" , 0,0), page3);
    labelt4->setGeometry(36+w0,25+h0,290,20);
    QLabel *labelt07 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Zoom " "\n" , 0,0), page3);
    labelt07->setGeometry(130+w0,88+h0,290,20);
    QPixmap imgA06(QCoreApplication::applicationDirPath() + "/image/SourisDroite.png");
    QLabel *label06 = new QLabel(page3);
    label06->setPixmap(imgA06);
    label06->setGeometry(35+w0,78+h0,35,35);
    label06->show();

    QLabel *labelt08 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Rotation" "\n" , 0,0), page3);
    labelt08->setGeometry(130+w0,136+h0,290,20);
    QPixmap imgA07(QCoreApplication::applicationDirPath() + "/image/SourisGauche.png");
    QLabel *label07 = new QLabel(page3);
    label07->setPixmap(imgA07);
    label07->setGeometry(35+w0,126+h0,35,35);
    label07->show();

    QLabel *labelt09 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Rotation plane" "\n" , 0,0), page3);
    labelt09->setGeometry(130+w0,184+h0,290,20);
    QPixmap imgA08(QCoreApplication::applicationDirPath() + "/image/SourisGauche.png");
    QLabel *label08 = new QLabel(page3);
    label08->setPixmap(imgA08);
    label08->setGeometry(35+w0,174+h0,35,35);
    label08->show();
    QLabel *labeltP01 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">+" "\n" , 0,0), page3);
    labeltP01->setGeometry(68+w0,184+h0,20,20);
    QPixmap imgA09(QCoreApplication::applicationDirPath() + "/image/Ctrl.png");
    QLabel *label09 = new QLabel(page3);
    label09->setPixmap(imgA09);
    label09->setGeometry(78+w0,166+h0,75,75);
    label09->show();

    QLabel *labelt00 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Translation" "\n" , 0,0), page3);
    labelt00->setGeometry(130+w0,232+h0,290,20);
    QPixmap imgA00(QCoreApplication::applicationDirPath() + "/image/SourisGauche.png");
    QLabel *label00 = new QLabel(page3);
    label00->setPixmap(imgA00);
    label00->setGeometry(35+w0,222+h0,35,35);
    label00->show();
    QLabel *labeltP02 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">+" "\n" , 0,0), page3);
    labeltP02->setGeometry(68+w0,232+h0,20,20);
    QPixmap imgA01(QCoreApplication::applicationDirPath() + "/image/Shift.png");
    QLabel *label01 = new QLabel(page3);
    label01->setPixmap(imgA01);
    label01->setGeometry(78+w0,215+h0,75,75);
    label01->show();


    QLabel *labelt6 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">Commandes en 2D" "\n" , 0,0), page3);
    labelt6->setGeometry(276+w1,25+h0,290,20);
    QLabel *labelt7 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Zoom " "\n" , 0,0), page3);
    labelt7->setGeometry(370+w1,88+h0,290,20);
    QPixmap imgA6(QCoreApplication::applicationDirPath() + "/image/SourisDroite.png");
    QLabel *label6 = new QLabel(page3);
    label6->setPixmap(imgA6);
    label6->setGeometry(275+w1,78+h0,35,35);
    label6->show();

    QLabel *labelt8 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Translation" "\n" , 0,0), page3);
    labelt8->setGeometry(370+w1,136+h0,200,20);
    QPixmap imgA7(QCoreApplication::applicationDirPath() + "/image/SourisGauche.png");
    QLabel *label7 = new QLabel(page3);
    label7->setPixmap(imgA7);
    label7->setGeometry(275+w1,126+h0,35,35);
    label7->show();



    QLabel *labelt9 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">: &nbsp;Navigation" "\n" , 0,0), page3);
    labelt9->setGeometry(370+w1,184+h0,290,20);
    QPixmap imgA8(QCoreApplication::applicationDirPath() + "/image/SourisMilieu.png");
    QLabel *label8 = new QLabel(page3);
    label8->setPixmap(imgA8);
    label8->setGeometry(275+w1,174+h0,35,35);
    label8->show();
    QLabel *labeltP2 = new QLabel(QApplication::translate("this", "<font color=\"#FFFFFF\">+" "\n" , 0,0), page3);
    labeltP2->setGeometry(308+w1,184+h0,20,20);



    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Configuration");
    onglets->addTab(page2, " Acquisition ");
    onglets->addTab(page3, " Traitement ");

    onglets->setCurrentIndex(0);
    onglets->hide();
}


void QPanelOnglets::StartGrab()
{
    aw = new AsynchronousGrab();
    aw->setParent(this);
    aw->setGeometry(0,-10,890,710);
    aw->show();
}


void PrintCameraInfo( const CameraPtr &camera )
{
    std::string strID;
    std::string strName;
    std::string strModelName;
    std::string strSerialNumber;
    std::string strInterfaceID;

    VmbErrorType err = camera->GetID( strID );
    err = camera->GetName( strName );
    err = camera->GetModel( strModelName );
    err = camera->GetSerialNumber( strSerialNumber );
    err = camera->GetInterfaceID( strInterfaceID );
    std::cout   << "/// Camera Name    : " << strName           << "\n"
                << "/// Model Name     : " << strModelName      <<  "\n"
                << "/// Camera ID      : " << strID             <<  "\n"
                << "/// Serial Number  : " << strSerialNumber   <<  "\n"
                << "/// @ Interface ID : " << strInterfaceID    << std::endl;
}


std::string QPanelOnglets::Print()
{
    VimbaSystem&    sys =  VimbaSystem::GetInstance(); // Get a reference to the VimbaSystem singleton
    std::cout<<"Vimba Version v"<<sys<<std::endl;      // Print out version of Vimba
    VmbErrorType    err = sys.Startup();               // Initialize the Vimba API
    CameraPtrVector cameras;                           // A vector of std::shared_ptr<AVT::VmbAPI::Camera> objects
    std::string camName="";


    if( VmbErrorSuccess == err )
    {
        err = sys.GetCameras( cameras );            // Fetch all cameras known to Vimba
        if( VmbErrorSuccess == err )
        {
            std::cout << "Cameras found: " << cameras.size() << std::endl;
            //connect=cameras.size();

            std::for_each( cameras.begin(), cameras.end(), PrintCameraInfo );
            if(cameras.size()!=0)
                cameras.at(0)->GetName(camName);
        }
        else
            std::cout << "err2" << std::endl;

     //   sys.Shutdown();                             // Close Vimba
    }
    else
        std::cout << "err1" << std::endl;

    sys.Shutdown();

return camName;
}



