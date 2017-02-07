#ifndef QPANELONGLETS_H
#define QPANELONGLETS_H

#include <QWidget>
#include<QLabel>
#include<QTabWidget>
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>


#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

//#include <VimbaCPP.h>
//#include <VimbaSystem.h>
#include "AVT/program/Common/StreamSystemInfo.h"
#include <AsynchronousGrab.h>

using namespace AVT::VmbAPI;



class QPanelOnglets : public QWidget
{
    Q_OBJECT
public:
    explicit QPanelOnglets(QWidget *parent = 0);
    void StartGrab();
    static std::string Print();
    AsynchronousGrab* aw;

signals:

public slots:


private:
   // void closeEvent(QCloseEvent *);
    QLabel *labelImg;
    QLabel *labelImgN;
    QLabel *labelImgB;
    QLabel *labeltext;

    int *m_aideOpen;
    QTabWidget *onglets;

};

#endif // QPANELONGLETS_H
