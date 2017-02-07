#ifndef DEF_MYLABEL
#define DEF_MYLABEL

#include <QLabel>
#include <QMouseEvent>


class MyLabel: public QLabel
{
    Q_OBJECT

public:
    MyLabel();


signals:
    void clicked();
    void released();

protected:
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);


};
#endif
