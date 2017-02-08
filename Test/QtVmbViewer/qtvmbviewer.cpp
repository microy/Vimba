#include "qtvmbviewer.h"
#include <iostream>

using std::cout;
using std::endl;

QtVmbViewer::QtVmbViewer( QWidget *parent ) : QWidget( parent )
{
    // Initialize Vimba
    VmbStartup();
    // Send discovery packet to GigE cameras
    VmbFeatureCommandRun( gVimbaHandle, "GeVDiscoveryAllOnce" );
    // Connect the camera
    VmbCameraOpen( "50-0503323406", VmbAccessModeFull, &camera_handle );
    // Adjust packet size automatically
    VmbFeatureCommandRun( camera_handle, "GVSPAdjustPacketSize" );
    // Get image parameters
    VmbFeatureIntGet( camera_handle, "Width", &width );
    VmbFeatureIntGet( camera_handle, "Height", &height );
    VmbFeatureIntGet( camera_handle, "PayloadSize", &payloadsize );
    // Initialize the frame buffer
    for( int i=0; i<10 ; ++i ) {
        // Allocate accordingly
        frames[i].buffer = malloc( payloadsize );
        frames[i].bufferSize = payloadsize;
        // Anounce the frame
        VmbFrameAnnounce( camera_handle, &frames[i], sizeof( VmbFrame_t ) );
    }
    // Start capture engine
    VmbCaptureStart( camera_handle );
    // Queue frames and register callback
    for( int i=0; i<10; ++i ) {
        VmbCaptureFrameQueue( camera_handle, &frames[i], &FrameDoneCallback );
    }
    // Start acquisition
    VmbFeatureCommandRun( camera_handle, "AcquisitionStart" );
}

// The callback that gets executed on every filled frame
void VMB_CALL QtVmbViewer::FrameDoneCallback( const VmbHandle_t hCamera, VmbFrame_t * pFrame )
{
    if ( VmbFrameStatusComplete == pFrame -> receiveStatus ) {
        cout << "Frame successfully received" << endl;
    }
    else {
        cout << "Error receiving frame" << endl;
    }
    VmbCaptureFrameQueue( hCamera , pFrame , &FrameDoneCallback );
}

QtVmbViewer::~QtVmbViewer()
{
    // Stop acquisition
    VmbFeatureCommandRun( camera_handle, "AcquisitionStop" );
    // Flush the frame queue
    VmbCaptureQueueFlush( camera_handle );
    // Stop capture engine
    VmbCaptureEnd( camera_handle );
    // Revoke the frames
    VmbFrameRevokeAll( camera_handle );
    // Free the frame buffer
    for( int i=0; i<10 ; ++i ) {
        free( frames[i].buffer );
    }
    // Close the camera
    VmbCameraClose( camera_handle );
    // Shutdown Vimba
    VmbShutdown();
}
