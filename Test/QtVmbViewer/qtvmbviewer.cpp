#include "qtvmbviewer.h"


QtVmbViewer::QtVmbViewer( QWidget *parent ) : QWidget( parent )
{
    // Create the camera
    camera = new VmbCamera( "50-0503323406" );
    // Open the camera
    camera->Open();
    // Start acquisition
    camera->StartCapture();
}

QtVmbViewer::~QtVmbViewer()
{
    // Stop acquisition
    camera->StopCapture();
    // Close the camera
    camera->Close();
    // Delete the camera
    delete camera;
}
