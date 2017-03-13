#! /usr/bin/env python
# -*- coding:utf-8 -*-

#
# Test application to display live images from an Allied Vision camera using OpenCV 3
#

# External dependencies
import cv2
import Vimba

# Image callback function
def ProcessImage( frame ) :
	# Check the frame
	if not frame.is_valid : return
	# Resize image for display
	image = cv2.resize( frame.image, None, fx=0.4, fy=0.4 )
	# Display the image
	cv2.imshow( camera.id, image )
	# Keyboard interruption
	if cv2.waitKey( 1 ) & 0xFF == 27 :
		global streaming
		streaming = False

# Initialize Vimba
Vimba.VmbStartup()
# Initialize the camera
camera = Vimba.VmbCamera( Vimba.VmbCamerasList()[0].cameraIdString )
# Open the camera
camera.Open()
# Start image acquisition
streaming = True
camera.StartCapture( ProcessImage )
# Streaming loop
while streaming : pass
# Stop image acquisition
camera.StopCapture()
# Close the camera
camera.Close()
# Shutdown Vimba
Vimba.VmbShutdown()
# Close OpenCV windows
cv2.destroyAllWindows()
