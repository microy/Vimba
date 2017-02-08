#include "VmbCamera.h"
#include <iostream>

using std::cout;
using std::endl;

// Construtor
VmbCamera::VmbCamera( const char* camera_id ) : id( camera_id ) {
    // Initialize Vimba
    VmbStartup();
    // Send discovery packet to GigE cameras
    VmbFeatureCommandRun( gVimbaHandle, "GeVDiscoveryAllOnce" );
}

// Destructor
VmbCamera::~VmbCamera() {
    // Shutdown Vimba
    VmbShutdown();
}

// Open the camera
void VmbCamera::Open() {
    // Connect to the camera
    VmbCameraOpen( id, VmbAccessModeFull, &handle );
    // Adjust packet size automatically
    VmbFeatureCommandRun( handle, "GVSPAdjustPacketSize" );
    // Get image parameters
    VmbFeatureIntGet( handle, "Width", &width );
    VmbFeatureIntGet( handle, "Height", &height );
    VmbFeatureIntGet( handle, "PayloadSize", &payloadsize );
}

// Close the camera
void VmbCamera::Close {
	// Close the camera
    VmbCameraClose( handle );
}

// Start acquisition
void VmbCamera::StartCapture() {
    // Initialize the frame buffer
    for( int i=0; i<10 ; ++i ) {
        // Allocate accordingly
        frames[i].buffer = malloc( payloadsize );
        frames[i].bufferSize = payloadsize;
        // Announce the frame
        VmbFrameAnnounce( handle, &frames[i], sizeof( VmbFrame_t ) );
    }
    // Start capture engine
    VmbCaptureStart( handle );
    // Queue frames and register callback
    for( int i=0; i<10; ++i ) {
        VmbCaptureFrameQueue( handle, &frames[i], &FrameDoneCallback );
    }
    // Start acquisition
    VmbFeatureCommandRun( handle, "AcquisitionStart" );
}

// Stop acquisition
void VmbCamera::StopCapture() {
	// Stop acquisition
	VmbFeatureCommandRun( handle, "AcquisitionStop" );
	// Flush the frame queue
	VmbCaptureQueueFlush( handle );
	// Stop capture engine
	VmbCaptureEnd( handle );
	// Revoke the frames
	VmbFrameRevokeAll( handle );
	// Free the frame buffer
	for( int i=0; i<10 ; ++i ) {
		free( frames[i].buffer );
	}
}

// The callback that gets executed on every filled frame
void VMB_CALL VmbCamera::FrameDoneCallback( const VmbHandle_t camera_handle, VmbFrame_t* frame_pointer ) {
	// Check frame status
    if ( frame_pointer->receiveStatus == VmbFrameStatusComplete ) {
        cout << "Frame successfully received" << endl;
    }
    else {
        cout << "Error receiving frame" << endl;
    }
	// Requeue the frame
    VmbCaptureFrameQueue( camera_handle , frame_pointer , &FrameDoneCallback );
}
