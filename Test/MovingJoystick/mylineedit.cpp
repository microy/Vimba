#include "mylineedit.h"

MyLineEdit::MyLineEdit() :
    QLineEdit()
{
}


void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    emit keyPressed();
    QLineEdit::keyPressEvent(event);
}

void MyLineEdit::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }

    QLineEdit::mousePressEvent(event);
}

void MyLineEdit::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit released();
    }

    QLineEdit::mouseReleaseEvent(event);
}
