#include "mainwindow.h"
#include <QApplication>
#include <AsynchronousGrab.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 //   AsynchronousGrab aw;
 //       aw.show();

    MainWindow w;
    w.show();

    return a.exec();
}
