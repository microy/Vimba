#include "qtvmbviewer.h"
#include <VimbaC.h>


QtVmbViewer::QtVmbViewer(QWidget *parent)
    : QWidget(parent)
{
    // Initialize Vimba
    VmbStartup();
}

QtVmbViewer::~QtVmbViewer()
{
    // Shutdown Vimba
    VmbShutdown();
}
