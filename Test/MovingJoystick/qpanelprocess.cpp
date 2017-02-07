#include "qpanelprocess.h"

QPanelProcess::QPanelProcess(QWidget *parent) :
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
    label->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/image/panelTitre.png"));
    label->show();

    SizeWinElements();
}


void QPanelProcess::SizeWinElements()
//Permet de modifier la taille de chaque élément en fonction de la taille de la fenêtre (l,h)
{
    int x=this->width(),y=this->height();
    panel->setGeometry(0,0,x,y);
    label->setGeometry(x/2-250,y/2-166,500,333);
}
