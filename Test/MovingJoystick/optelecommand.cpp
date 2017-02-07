#include "optelecommand.h"
#include "QApplication"

OpTelecommand::OpTelecommand(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("Configuration télécommande");

    //Ecran fond
    labelFond = new QLabel(this);
    labelFond->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/EcranFond.png"));
    labelFond->setParent(this);
    labelFond->show();

    //Icone
    labelOp = new QLabel(this);
    labelOp->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/option.png"));
    labelOp->setParent(this);
    labelOp->show();

    //Création du bouton Connect
    boutonOk.setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/boutonOk.png"));
    boutonOk.setParent(this);
    boutonOk.setCursor(Qt::PointingHandCursor);
    QObject::connect(&boutonOk, SIGNAL(clicked()), this, SLOT(close()));
    boutonOk.show();

    //Panel Vitesse
    panelOp = new QWidget(this);
    QPalette paletteM(QColor(100,120,135));
    panelOp->setPalette(paletteM);
    QGraphicsOpacityEffect *op=new QGraphicsOpacityEffect(this);
    op->setOpacity(0.75) ;
    panelOp->setAutoFillBackground(true);
    panelOp->setGraphicsEffect(op);
    panelOp->show();



    // Création des sliders theta
    m_TetaLentSlider = new QSlider(Qt::Horizontal, this);
    m_TetaLentSlider->setMinimum(0);
    m_TetaLentSlider->setMaximum(50000/(pas));
    m_TetaLentSlider->setTickPosition(QSlider::TicksRight);
    m_TetaLentSlider->setTickInterval(10000/pas);


    m_TetaRapideSlider = new QSlider(Qt::Horizontal, this);
    m_TetaRapideSlider->setMinimum(0);
    m_TetaRapideSlider->setMaximum(50000/(pas*2));
    m_TetaRapideSlider->setTickPosition(QSlider::TicksRight);
    m_TetaRapideSlider->setTickInterval(10000/(pas*2));


    QFont policePar("Times", 8, QFont::Normal, false);
    QFont policePar2("Times", 9, QFont::Bold, false);
    QFont policePar3("Times", 11, QFont::Normal, false);

    labeltextVitesse = new QLabel(this);
    labeltextVitesse->setFont(policePar);
    labeltextVitesse->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Configuration des axes</font>" "\n" , 0,0));

    labeltextTeta = new QLabel(this);
    labeltextTeta->setFont(policePar);
    labeltextTeta->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Axe &theta;</font>" "\n" , 0,0));

    labeltextTetaLent = new QLabel(this);
    labeltextTetaLent->setFont(policePar);
    labeltextTetaLent->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Vitesse lente</font>" "\n" , 0,0));

    labeltextTetaRapide = new QLabel(this);
    labeltextTetaRapide->setFont(policePar);
    labeltextTetaRapide->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Vitesse rapide</font>" "\n" , 0,0));

    labeltextTetaValueLent = new QLabel(this);
    labeltextTetaValueLent->setFont(policePar2);

    labeltextTetaValueRapide = new QLabel(this);
    labeltextTetaValueRapide->setFont(policePar2);

    labeltextTetaMin = new QLabel(this);
    labeltextTetaMin->setFont(policePar);
    labeltextTetaMin->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">0</font>" "\n" , 0,0));

    labeltextTetaMax = new QLabel(this);
    labeltextTetaMax->setFont(policePar);
    labeltextTetaMax->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">50000</font>" "\n" , 0,0));

    QObject::connect(m_TetaLentSlider, SIGNAL(valueChanged(int)), this, SLOT(SetTetaLent(int)));
    QObject::connect(m_TetaRapideSlider, SIGNAL(valueChanged(int)), this, SLOT(SetTetaRapide(int)));


    // Création des sliders phi
    m_PhiLentSlider = new QSlider(Qt::Horizontal, this);
    m_PhiLentSlider->setMinimum(0);
    m_PhiLentSlider->setMaximum(20000/pas);
    m_PhiLentSlider->setTickPosition(QSlider::TicksRight);
    m_PhiLentSlider->setTickInterval(5000/pas);


    m_PhiRapideSlider = new QSlider(Qt::Horizontal, this);
    m_PhiRapideSlider->setMinimum(0);
    m_PhiRapideSlider->setMaximum(20000/(pas*2));
    m_PhiRapideSlider->setTickPosition(QSlider::TicksRight);
    m_PhiRapideSlider->setTickInterval(5000/(pas*2));


    labeltextPhi = new QLabel(this);
    labeltextPhi->setFont(policePar);
    labeltextPhi->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Axe φ</font>" "\n" , 0,0));

    labeltextPhiLent = new QLabel(this);
    labeltextPhiLent->setFont(policePar);
    labeltextPhiLent->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Vitesse lente</font>" "\n" , 0,0));

    labeltextPhiRapide = new QLabel(this);
    labeltextPhiRapide->setFont(policePar);
    labeltextPhiRapide->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Vitesse rapide</font>" "\n" , 0,0));

    labeltextPhiValueLent = new QLabel(this);
    labeltextPhiValueLent->setFont(policePar2);

    labeltextPhiValueRapide = new QLabel(this);
    labeltextPhiValueRapide->setFont(policePar2);

    labeltextPhiMin = new QLabel(this);
    labeltextPhiMin->setFont(policePar);
    labeltextPhiMin->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">0</font>" "\n" , 0,0));

    labeltextPhiMax = new QLabel(this);
    labeltextPhiMax->setFont(policePar);
    labeltextPhiMax->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">20000</font>" "\n" , 0,0));

    QObject::connect(m_PhiLentSlider, SIGNAL(valueChanged(int)), this, SLOT(SetPhiLent(int)));
    QObject::connect(m_PhiRapideSlider, SIGNAL(valueChanged(int)), this, SLOT(SetPhiRapide(int)));



    // Création des sliders Z
    m_ZLentSlider = new QSlider(Qt::Horizontal, this);
    m_ZLentSlider->setMinimum(0);
    m_ZLentSlider->setMaximum(50000/(pas));
    m_ZLentSlider->setTickPosition(QSlider::TicksRight);
    m_ZLentSlider->setTickInterval(10000/pas);


    m_ZRapideSlider = new QSlider(Qt::Horizontal, this);
    m_ZRapideSlider->setMinimum(0);
    m_ZRapideSlider->setMaximum(50000/(pas*2));
    m_ZRapideSlider->setTickPosition(QSlider::TicksRight);
    m_ZRapideSlider->setTickInterval(10000/(pas*2));


    labeltextZ = new QLabel(this);
    labeltextZ->setFont(policePar);
    labeltextZ->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Axe Z</font>" "\n" , 0,0));

    labeltextZLent = new QLabel(this);
    labeltextZLent->setFont(policePar);
    labeltextZLent->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Vitesse lente</font>" "\n" , 0,0));

    labeltextZRapide = new QLabel(this);
    labeltextZRapide->setFont(policePar);
    labeltextZRapide->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Vitesse rapide</font>" "\n" , 0,0));

    labeltextZValueLent = new QLabel(this);
    labeltextZValueLent->setFont(policePar2);

    labeltextZValueRapide = new QLabel(this);
    labeltextZValueRapide->setFont(policePar2);

    labeltextZMin = new QLabel(this);
    labeltextZMin->setFont(policePar);
    labeltextZMin->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">0</font>" "\n" , 0,0));

    labeltextZMax = new QLabel(this);
    labeltextZMax->setFont(policePar);
    labeltextZMax->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">50000</font>" "\n" , 0,0));

    QObject::connect(m_ZLentSlider, SIGNAL(valueChanged(int)), this, SLOT(SetZLent(int)));
    QObject::connect(m_ZRapideSlider, SIGNAL(valueChanged(int)), this, SLOT(SetZRapide(int)));


    //Panel Borne
    panelOp2 = new QWidget(this);
    panelOp2->setPalette(paletteM);
    QGraphicsOpacityEffect *op2=new QGraphicsOpacityEffect(this);
    op2->setOpacity(0.75) ;
    panelOp2->setAutoFillBackground(true);
    panelOp2->setGraphicsEffect(op2);
    panelOp2->show();

    labeltextBorne = new QLabel(this);
    labeltextBorne->setFont(policePar);
    labeltextBorne->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Configuration des bornes de déplacement</font>" "\n" , 0,0));


    labeltextTetaB = new QLabel(this);
    labeltextTetaB->setFont(policePar);
    labeltextTetaB->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Bornes &theta;</font>" "\n" , 0,0));

    labeltextTetaBmin = new QLabel(this);
    labeltextTetaBmin->setFont(policePar);
    labeltextTetaBmin->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Min</font>" "\n" , 0,0));

    labeltextTetaBmax = new QLabel(this);
    labeltextTetaBmax->setFont(policePar);
    labeltextTetaBmax->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Max</font>" "\n" , 0,0));

    labeltextPhiB = new QLabel(this);
    labeltextPhiB->setFont(policePar);
    labeltextPhiB->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Bornes φ</font>" "\n" , 0,0));

    labeltextPhiBmin = new QLabel(this);
    labeltextPhiBmin->setFont(policePar);
    labeltextPhiBmin->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Min</font>" "\n" , 0,0));

    labeltextPhiBmax = new QLabel(this);
    labeltextPhiBmax->setFont(policePar);
    labeltextPhiBmax->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Max</font>" "\n" , 0,0));

    labeltextZB = new QLabel(this);
    labeltextZB->setFont(policePar);
    labeltextZB->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Bornes Z</font>" "\n" , 0,0));

    labeltextZBmin = new QLabel(this);
    labeltextZBmin->setFont(policePar);
    labeltextZBmin->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Min</font>" "\n" , 0,0));

    labeltextZBmax = new QLabel(this);
    labeltextZBmax->setFont(policePar);
    labeltextZBmax->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Max</font>" "\n" , 0,0));

    whiteLine = new QWidget(this);
    QPalette paletteW(QColor(255,255,255));
    whiteLine->setPalette(paletteW);
    whiteLine->setAutoFillBackground(true);

    whiteLine2 = new QWidget(this);
    whiteLine2->setPalette(paletteW);
    whiteLine2->setAutoFillBackground(true);


    LineEditTetaMin = new QLineEdit(this);
    LineEditTetaMin->setStyleSheet("color: \"#DDDDDD\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    LineEditTetaMin->setFont(policePar3);
    LineEditTetaMin->setDisabled(true);
    LineEditTetaMin->setText("∞");

    LineEditTetaMax = new QLineEdit(this);
    LineEditTetaMax->setStyleSheet("color: \"#DDDDDD\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    LineEditTetaMax->setFont(policePar3);
    LineEditTetaMax->setDisabled(true);
    LineEditTetaMax->setText("∞");


    LineEditPhiMin = new QLineEdit(this);
    LineEditPhiMin->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
   // LineEditPhiMin->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    QObject::connect(LineEditPhiMin, SIGNAL(textChanged(const QString &)), this, SLOT(SetPhiMin()));
    LineEditPhiMin->setFont(policePar);
    LineEditPhiMin->setEnabled(true);

    LineEditPhiMax = new QLineEdit(this);
    LineEditPhiMax->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
    //LineEditPhiMax->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    QObject::connect(LineEditPhiMax, SIGNAL(textChanged(const QString &)), this, SLOT(SetPhiMax()));
    LineEditPhiMax->setFont(policePar);
    LineEditPhiMax->setEnabled(true);


    LineEditZMin = new QLineEdit(this);
    LineEditZMin->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
    //LineEditZMin->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    QObject::connect(LineEditZMin, SIGNAL(textChanged(const QString &)), this, SLOT(SetZMin()));
    LineEditZMin->setFont(policePar);
    LineEditZMin->setEnabled(true);

    LineEditZMax = new QLineEdit(this);
    LineEditZMax->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#9CB7BC\"; background-color: \"#425460\"");
    //LineEditZMax->setStyleSheet("color: \"#FFFFFF\"; border: 1px solid \"#7A7A7A\"; background-color: \"#696969\"");
    QObject::connect(LineEditZMax, SIGNAL(textChanged(const QString &)), this, SLOT(SetZMax()));
    LineEditZMax->setFont(policePar);
    LineEditZMax->setEnabled(true);



    SizeWinElements();
    ReadValues();
}


OpTelecommand::~OpTelecommand()
{
    SaveValues();
}


void OpTelecommand::LinkTelecommand(QTelecommand *t)
{
    m_t=t;

    m_t->vitesse_theta_lente=vtetal;
    m_t->vitesse_theta_rapide=vtetar;
    m_t->vitesse_phi_lente=vphil;
    m_t->vitesse_phi_rapide=vphir;
    m_t->vitesse_Z_lente=vZl;
    m_t->vitesse_Z_rapide=vZr;

    m_t->bPhiMin=&bPhiMin;
    m_t->bPhiMax=&bPhiMax;
    m_t->bZMin=&bZMin;
    m_t->bZMax=&bZMax;


    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_theta_lente<<"</font> \n";
    labeltextTetaValueLent->setText(QApplication::translate("this", st.str().c_str() , 0,0));
    m_TetaLentSlider->setValue(m_t->vitesse_theta_lente/pas);

    std::stringstream st2; st2<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_theta_rapide<<"</font> \n";
    labeltextTetaValueRapide->setText(QApplication::translate("this", st2.str().c_str() , 0,0));
    m_TetaRapideSlider->setValue(m_t->vitesse_theta_rapide/(pas*2));

    std::stringstream st3; st3<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_phi_lente<<"</font> \n";
    labeltextPhiValueLent->setText(QApplication::translate("this", st3.str().c_str() , 0,0));
    m_PhiLentSlider->setValue(m_t->vitesse_phi_lente/pas);

    std::stringstream st4; st4<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_phi_rapide<<"</font> \n";
    labeltextPhiValueRapide->setText(QApplication::translate("this", st4.str().c_str() , 0,0));
    m_PhiRapideSlider->setValue(m_t->vitesse_phi_rapide/(pas*2));

    std::stringstream st5; st5<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_Z_lente<<"</font> \n";
    labeltextZValueLent->setText(QApplication::translate("this", st5.str().c_str() , 0,0));
    m_ZLentSlider->setValue(m_t->vitesse_Z_lente/pas);

    std::stringstream st6; st6<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_Z_rapide<<"</font> \n";
    labeltextZValueRapide->setText(QApplication::translate("this", st6.str().c_str() , 0,0));
    m_ZRapideSlider->setValue(m_t->vitesse_Z_rapide/(pas*2));



}

void OpTelecommand::SizeWinElements()
{
    labelFond->setGeometry(0, 0, 800, 800);
    labelOp->setGeometry(10, 10, 80, 80);
    panelOp->setGeometry(100, 10, 500, 470);
    panelOp2->setGeometry(100, 490, 500, 180);

    labeltextVitesse->setGeometry(120, 30, 250, 20);

    int hTeta=60;
    m_TetaLentSlider->setGeometry(240, 58+hTeta, 260, 20);
    m_TetaRapideSlider->setGeometry(240, 88+hTeta, 260, 20);

    labeltextTeta->setGeometry(120, 30+hTeta, 150, 20);
    labeltextTetaLent->setGeometry(120, 57+hTeta, 90, 20);
    labeltextTetaValueLent->setGeometry(535, 57+hTeta, 60, 20);
    labeltextTetaRapide->setGeometry(120, 84+hTeta, 90, 20);
    labeltextTetaValueRapide->setGeometry(535, 84+hTeta, 60, 20);
    labeltextTetaMin->setGeometry(242, 111+hTeta, 90, 20);
    labeltextTetaMax->setGeometry(475, 111+hTeta, 90, 20);


    int hPhi=190;
    m_PhiLentSlider->setGeometry(240, 58+hPhi, 260, 20);
    m_PhiRapideSlider->setGeometry(240, 88+hPhi, 260, 20);

    labeltextPhi->setGeometry(120, 30+hPhi, 150, 20);
    labeltextPhiLent->setGeometry(120, 57+hPhi, 90, 20);
    labeltextPhiValueLent->setGeometry(535, 57+hPhi, 60, 20);
    labeltextPhiRapide->setGeometry(120, 84+hPhi, 90, 20);
    labeltextPhiValueRapide->setGeometry(535, 84+hPhi, 60, 20);
    labeltextPhiMin->setGeometry(242, 111+hPhi, 90, 20);
    labeltextPhiMax->setGeometry(475, 111+hPhi, 90, 20);


    int hZ=320;
    m_ZLentSlider->setGeometry(240, 58+hZ, 260, 20);
    m_ZRapideSlider->setGeometry(240, 88+hZ, 260, 20);

    labeltextZ->setGeometry(120, 30+hZ, 150, 20);
    labeltextZLent->setGeometry(120, 57+hZ, 90, 20);
    labeltextZValueLent->setGeometry(535, 57+hZ, 60, 20);
    labeltextZRapide->setGeometry(120, 84+hZ, 90, 20);
    labeltextZValueRapide->setGeometry(535, 84+hZ, 60, 20);
    labeltextZMin->setGeometry(242, 111+hZ, 90, 20);
    labeltextZMax->setGeometry(475, 111+hZ, 90, 20);


    int hBorne=495;
    labeltextBorne->setGeometry(120, 15+hBorne, 250, 20);
    labeltextTetaB->setGeometry(120, 80+hBorne, 60, 20);
    labeltextTetaBmin->setGeometry(250, 80+hBorne, 40, 20);
    LineEditTetaMin->setGeometry(290, 80+hBorne, 70, 20);
    labeltextTetaBmax->setGeometry(430, 80+hBorne, 60, 20);
    LineEditTetaMax->setGeometry(470, 80+hBorne, 70, 20);

    labeltextPhiB->setGeometry(120, 110+hBorne, 130, 20);
    labeltextPhiBmin->setGeometry(250, 110+hBorne, 60, 20);
    LineEditPhiMin->setGeometry(290, 110+hBorne, 70, 20);
    labeltextPhiBmax->setGeometry(430, 110+hBorne, 60, 20);
    LineEditPhiMax->setGeometry(470, 110+hBorne, 70, 20);

    labeltextZB->setGeometry(120, 140+hBorne, 130, 20);
    labeltextZBmin->setGeometry(250, 140+hBorne, 60, 20);
    LineEditZMin->setGeometry(290, 140+hBorne, 70, 20);
    labeltextZBmax->setGeometry(430, 140+hBorne, 60, 20);
    LineEditZMax->setGeometry(470, 140+hBorne, 70, 20);

    whiteLine->setGeometry(110, 60, 480, 1);
    whiteLine2->setGeometry(110, 50+hBorne, 480, 1);

    boutonOk.setGeometry(610,590,80,80);
}


void OpTelecommand::SetTetaLent(int value)
{
    m_t->vitesse_theta_lente=vtetal=value*pas;
    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_theta_lente<<"</font> \n";
    labeltextTetaValueLent->setText(QApplication::translate("this", st.str().c_str() , 0,0));
}

void OpTelecommand::SetTetaRapide(int value)
{
    m_t->vitesse_theta_rapide=vtetar=value*pas*2;
    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_theta_rapide<<"</font> \n";
    labeltextTetaValueRapide->setText(QApplication::translate("this", st.str().c_str() , 0,0));
}

void OpTelecommand::SetPhiLent(int value)
{
    m_t->vitesse_phi_lente=vphil=value*pas;
    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_phi_lente<<"</font> \n";
    labeltextPhiValueLent->setText(QApplication::translate("this", st.str().c_str() , 0,0));
}

void OpTelecommand::SetPhiRapide(int value)
{
    m_t->vitesse_phi_rapide=vphir=value*pas*2;
    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_phi_rapide<<"</font> \n";
    labeltextPhiValueRapide->setText(QApplication::translate("this", st.str().c_str() , 0,0));
}

void OpTelecommand::SetZLent(int value)
{
    m_t->vitesse_Z_lente=vZl=value*pas;
    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_Z_lente<<"</font> \n";
    labeltextZValueLent->setText(QApplication::translate("this", st.str().c_str() , 0,0));
}

void OpTelecommand::SetZRapide(int value)
{
    m_t->vitesse_Z_rapide=vZr=value*pas*2;
    std::stringstream st; st<<"<font color=\"#FFFFFF\">"<<m_t->vitesse_Z_rapide<<"</font> \n";
    labeltextZValueRapide->setText(QApplication::translate("this", st.str().c_str() , 0,0));
}


void OpTelecommand::SetPhiMin()    {    bPhiMin=LineEditPhiMin->text().toDouble();   }
void OpTelecommand::SetPhiMax()    {    bPhiMax=LineEditPhiMax->text().toDouble();   }
void OpTelecommand::SetZMin()      {    bZMin=LineEditZMin->text().toDouble();   }
void OpTelecommand::SetZMax()      {    bZMax=LineEditZMax->text().toDouble();   }



void OpTelecommand::SaveValues()
{
    ofstream fichier("saveValues.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    if(fichier)  // si l'ouverture a réussi
    {
        fichier << vtetal << " " << vtetar << " " <<vphil << " " << vphir << " " << vZl << " " << vZr << " " << bPhiMin << " " << bPhiMax << " " << bZMin << " " << bZMax;
        fichier.close();  // on referme le fichier
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}


void OpTelecommand::ReadValues()
{
    ifstream fichier("saveValues.txt", ios::in);  //déclaration du flux et ouverture du fichier

    if(fichier)  // si l'ouverture a réussi
    {
        fichier >> vtetal >> vtetar >> vphil >> vphir >> vZl >> vZr >> bPhiMin >> bPhiMax >> bZMin >> bZMax;
        fichier.close();  // on referme le fichier

        LineEditPhiMin->setText(QString::number(bPhiMin));
        LineEditPhiMax->setText(QString::number(bPhiMax));
        LineEditZMin->setText(QString::number(bZMin));
        LineEditZMax ->setText(QString::number(bZMax));
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}

