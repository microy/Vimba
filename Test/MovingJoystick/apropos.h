#ifndef APROPOS_H
#define APROPOS_H

#include <QDialog>
#include <QLabel>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>

class Apropos : public QDialog
{
    Q_OBJECT
public:
    explicit Apropos(QWidget *parent = 0);
    void closeEvent(QCloseEvent *) {this->hide();}

public slots:
    void onLinkActivated(const QString &link);

private:
    void resizeEvent(QResizeEvent *event);

    QLabel *labelImg;
    QLabel *labelImgN;
    QLabel *labelImgB;
    QLabel *labeltext;
    QLabel *labeltext2;
    QLabel *labeltext3;
    QLabel *labelTitre;
};

#endif // APROPOS_H

