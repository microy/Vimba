#ifndef QTVMBVIEWER_H
#define QTVMBVIEWER_H

#include <QWidget>
#include "VmbCamera.h"

class QtVmbViewer : public QWidget
{
    Q_OBJECT

public:
    QtVmbViewer(QWidget *parent = 0);
    ~QtVmbViewer();

    // Allied Vision camera
    VmbCamera* camera;
};

#endif // QTVMBVIEWER_H
