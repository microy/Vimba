#ifndef VMBCAMERA_H
#define VMBCAMERA_H

// Standard dependency
#include <string>
// Vimba SDK dependency
#include <VimbaC.h>

// Class to access a Gbe camera through Vimba SDK
class VmbCamera {
	// Public members
	public :
		// Construtor
	    VmbCamera( const char* camera_id );
		// Destructor
	    ~VmbCamera();

		// Open the camera
		void Open();
		// Close the camera
		void Close();
		// Start the acquisition
		void StartCapture();
		// Stop the acquisition
		void StopCapture();

	    // Handle to the camera
	    VmbHandle_t handle;
		// Identification number of the camera
		std::string id;
	    // Image parameters
	    VmbInt64_t width;
	    VmbInt64_t height;
	    VmbInt64_t payloadsize;
	    // Frame buffer
	    VmbFrame_t frames[10];

	    // Function called by Vimba to receive the frame
	    static void VMB_CALL FrameDoneCallback( const VmbHandle_t camera_handle, VmbFrame_t* frame_pointer );
};

#endif // VMBCAMERA_H
