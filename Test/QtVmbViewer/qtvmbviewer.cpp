#include "qtvmbviewer.h"
#include <iostream>
#include <QShortcut>

// Constructor
QtVmbViewer::QtVmbViewer( QWidget *parent ) : QWidget( parent ) {

    // Set the Escape key to close the application
    QShortcut* q = new QShortcut( QKeySequence(Qt::Key_Escape), this, SLOT(close()) );
    // Create the camera
    camera = new VmbCamera( "50-0503323406" );
    // Connect the camera signal to get the received frame
    connect( camera, &VmbCamera::FrameReceived, this, &QtVmbViewer::GetFrame );
    // Open the camera
    camera->Open();
    // Start acquisition
    camera->StartCapture();
}

// Destructor
QtVmbViewer::~QtVmbViewer() {
    // Stop acquisition
    camera->StopCapture();
    // Close the camera
    camera->Close();
    // Delete the camera
    delete camera;
}

// Image callback
void QtVmbViewer::GetFrame( const VmbFrame_t* frame_pointer ) {
    std::cout << "-- Image received " << frame_pointer->frameID << std::endl;
}

