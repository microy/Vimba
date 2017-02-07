#include "MyLabel.h"
#include "iostream"

//création d'un bouton clickable
MyLabel::MyLabel(): QLabel()
{

}




void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }

    QLabel::mousePressEvent(event);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit released();
    }

    QLabel::mouseReleaseEvent(event);
}
