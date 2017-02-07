#include "apropos.h"



//Fenetre A propos
Apropos::Apropos(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("À propos");


    //Ecran fond
    labelImg = new QLabel(this);
    QPalette pal=QPalette(QColor(40,50,60));
    labelImg->setPalette(pal);
    labelImg->setAutoFillBackground(true);
    labelImg->show();

    labelImgN = new QLabel(this);
    QPalette palN=QPalette(QColor(20,30,40));
    labelImgN->setPalette(palN);
    labelImgN->setAutoFillBackground(true);
    labelImgN->show();

    labelImgB = new QLabel(this);
    QPalette palB=QPalette(QColor(255,255,255));
    labelImgB->setPalette(palB);
    labelImgB->setAutoFillBackground(true);
    labelImgB->show();


    QPixmap imgT(QCoreApplication::applicationDirPath() + "/image/EcranTitreAP.png");
    labelTitre = new QLabel(this);
    labelTitre->setPixmap(imgT);
    labelTitre->setParent(this);
    labelTitre->show();


    QFont policePar("Calibri", 20, QFont::Normal, false);
    labeltext = new QLabel(this);
    labeltext->setFont(policePar);
    labeltext->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">X-RTI</font>" "\n" , 0,0));


    QFont policePar2("Times", 9, QFont::Normal, false);
    labeltext2 = new QLabel(this);
    labeltext2->setFont(policePar2);
    labeltext2->setText(QApplication::translate("this", "<font color=\"#FFFFFF\">Gaëtan Le Goïc<br>gaetan.le-goic@u-bourgogne.fr<br><br>Arnaud Boucher<br>arnaud.boucher@u-bourgogne.fr<br><br>Université de Bourgogne - Le2i<br></font>", 0,0));

    labeltext3 = new QLabel(this);
    labeltext3->setFont(policePar2);
    QString url = QLatin1String("http://www.le2i-auxerre.fr/");
    QString tar = QLatin1String("_blank");
    QString cString="<a href="+url+"="+tar+"><font color=\"#99F6FF\">Site Web du Le2i Auxerre</font></a>";
    const char *c=cString.toStdString().c_str();
    labeltext3->setText(QApplication::translate("this", c, 0,0));


    connect(labeltext3, SIGNAL(linkActivated(QString)), this, SLOT(onLinkActivated(QString)));

}



void Apropos::onLinkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}


void Apropos::resizeEvent(QResizeEvent *event)
{
    labelTitre->setGeometry(50,40,246,246);
    labelImg->setGeometry(0,0,this->width(),this->height());
    labelImgN->setGeometry(0,30,this->width(),266);
    labelImgB->setGeometry(340,90,this->width()-320,1);
    labeltext->setGeometry(340,46,270,40);
    labeltext2->setGeometry(340,110,270,140);
    labeltext3->setGeometry(340,200,270,140);
}
