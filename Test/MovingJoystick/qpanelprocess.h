#ifndef QPANELPROCESS_H
#define QPANELPROCESS_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QCoreApplication>

class QPanelProcess : public QWidget
{
    Q_OBJECT
public:
    explicit QPanelProcess(QWidget *parent = 0);
    void SizeWinElements();
    QLabel *label;
    QWidget *panel;

signals:

public slots:


private:


};

#endif // QPANELPROCESS_H
