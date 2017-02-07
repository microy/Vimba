#ifndef OPTELECOMMAND_H
#define OPTELECOMMAND_H

#include <QDialog>
#include <QSlider>
#include <QTelecommand.h>
#include <fstream>

using namespace std;


class OpTelecommand : public QDialog
{
    Q_OBJECT
public:
    explicit OpTelecommand(QWidget *parent = 0);
    ~OpTelecommand();
    void LinkTelecommand(QTelecommand *t);
    void SaveValues();
    void ReadValues();

signals:

public slots:
    void SetTetaLent(int value);
    void SetTetaRapide(int value);
    void SetPhiLent(int value);
    void SetPhiRapide(int value);
    void SetZLent(int value);
    void SetZRapide(int value);
    void SetPhiMin();
    void SetPhiMax();
    void SetZMin();
    void SetZMax();


private:
    int pas=500;
    void SizeWinElements();
    int vtetal,vtetar,vphil,vphir,vZl,vZr;
    double bPhiMin, bPhiMax, bZMin, bZMax;

    QLabel *labelFond;
    QLabel *labelOp;

    MyLabel boutonOk;

    QSlider *m_TetaLentSlider;
    QSlider *m_TetaRapideSlider;
    QLabel *labeltextVitesse;
    QLabel *labeltextTeta;
    QLabel *labeltextTetaLent;
    QLabel *labeltextTetaValueLent;
    QLabel *labeltextTetaValueRapide;
    QLabel *labeltextTetaRapide;
    QLabel *labeltextTetaMin;
    QLabel *labeltextTetaMax;

    QSlider *m_PhiLentSlider;
    QSlider *m_PhiRapideSlider;
    QLabel *labeltextPhi;
    QLabel *labeltextPhiLent;
    QLabel *labeltextPhiValueLent;
    QLabel *labeltextPhiValueRapide;
    QLabel *labeltextPhiRapide;
    QLabel *labeltextPhiMin;
    QLabel *labeltextPhiMax;

    QSlider *m_ZLentSlider;
    QSlider *m_ZRapideSlider;
    QLabel *labeltextZ;
    QLabel *labeltextZLent;
    QLabel *labeltextZValueLent;
    QLabel *labeltextZValueRapide;
    QLabel *labeltextZRapide;
    QLabel *labeltextZMin;
    QLabel *labeltextZMax;


    QLabel *labeltextBorne;
    QLabel *labeltextTetaB;
    QLabel *labeltextTetaBmin;
    QLabel *labeltextTetaBmax;
    QLabel *labeltextPhiB;
    QLabel *labeltextPhiBmin;
    QLabel *labeltextPhiBmax;
    QLabel *labeltextZB;
    QLabel *labeltextZBmin;
    QLabel *labeltextZBmax;


    QWidget *panelOp;
    QWidget *panelOp2;
    QWidget *whiteLine;
    QWidget *whiteLine2;

    QLineEdit *LineEditTetaMin;
    QLineEdit *LineEditTetaMax;
    QLineEdit *LineEditPhiMin;
    QLineEdit *LineEditPhiMax;
    QLineEdit *LineEditZMin;
    QLineEdit *LineEditZMax;


    QTelecommand *m_t;

};

#endif // OPTELECOMMAND_H
