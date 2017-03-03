# -*- coding:utf-8 -*-

#
# Interface to the Allied Vision Vimba SDK
#

# Inspired from :
#  - Allied Vision Vimba SDK (https://www.alliedvision.com/en/products/software.html)
#  - Pymba (https://github.com/morefigs/pymba)
#  - ROS (http://wiki.ros.org/avt_vimba_camera)

# External dependencies
import os
import ctypes as ct
import numpy as np

# The Vimba library
vimba = None

# Define the error type according to the error code
error_type = {
		0 : 	'VmbErrorSuccess',
		-1 : 	'VmbErrorInternalFault',
		-2 :	'VmbErrorApiNotStarted',
		-3 :	'VmbErrorNotFound',
		-4 :	'VmbErrorBadHandle',
		-5 :	'VmbErrorDeviceNotOpen',
		-6 :	'VmbErrorInvalidAccess',
		-7 :	'VmbErrorBadParameter',
		-8 :	'VmbErrorStructSize',
		-9 :	'VmbErrorMoreData',
		-10 :	'VmbErrorWrongType',
		-11 :	'VmbErrorInvalidValue',
		-12 :	'VmbErrorTimeout',
		-13 :	'VmbErrorOther',
		-14 :	'VmbErrorResources',
		-15 :	'VmbErrorInvalidCall',
		-16 :	'VmbErrorNoTL',
		-17 :	'VmbErrorNotImplemented',
		-18 :	'VmbErrorNotSupported',
		-19 :	'VmbErrorIncomplete'
}

# Initialize the Vimba library
def VmbStartup() :
	# Get Vimba installation directory
	vimba_path = '/' + '/'.join( os.environ.get( 'GENICAM_GENTL64_PATH' ).split( '/' )[ 1 : -3 ] )
	vimba_path += '/VimbaC/DynamicLib/x86_64bit/libVimbaC.so'
	# Load Vimba library
	global vimba
	vimba = ct.cdll.LoadLibrary( vimba_path )
	# Initialize the library
	error = vimba.VmbStartup()
	if error : print( 'Error: Cannot start Vimba ({}).'.format(error_type[error]) )
	# Send discovery packet to GigE cameras
	error = vimba.VmbFeatureCommandRun( ct.c_void_p( 1 ), 'GeVDiscoveryAllOnce' )
	if error : print( 'Error: Cannot discover GigabitEthernet camera ({}).'.format(error_type[error]) )

# Release the Vimba library
def VmbShutdown() :
	vimba.VmbShutdown()

# Vimba frame structure
class VmbFrame( ct.Structure ) :
	# VmbFrame structure fields
	_fields_ = [ ( 'buffer', ct.POINTER( ct.c_char ) ),
			( 'bufferSize', ct.c_uint32 ),
			( 'context', ct.c_void_p * 4 ),
			( 'receiveStatus', ct.c_int32 ),
			( 'receiveFlags', ct.c_uint32 ),
			( 'imageSize', ct.c_uint32 ),
			( 'ancillarySize', ct.c_uint32 ),
			( 'pixelFormat', ct.c_uint32 ),
			( 'width', ct.c_uint32 ),
			( 'height', ct.c_uint32 ),
			( 'offsetX', ct.c_uint32 ),
			( 'offsetY', ct.c_uint32 ),
			( 'frameID', ct.c_uint64 ),
			( 'timestamp', ct.c_uint64 ) ]
	# Convert the frame to a numpy array
	@property
	def image( self ) :
		return np.ndarray( buffer = self.buffer[ 0 : self.bufferSize ], dtype = np.uint8, shape = ( self.height, self.width ) )
	# Tell if the frame is valid
	@property
	def is_valid( self ) :
		return not self.receiveStatus

# Vimba camera
class VmbCamera( object ) :
	# Initialize the camera
	def __init__( self, camera_id ) :
		# Camera handle
		self.handle = ct.c_void_p()
		# Camera ID (serial number, IP address...)
		self.id = camera_id
		# Register the internal frame callback function
		self.vmb_frame_callback = ct.CFUNCTYPE( None, ct.c_void_p, ct.POINTER( VmbFrame ) )( self.VmbFrameCallback )
		# Initialize the frame buffer
		self.frame_buffer = []
	# Open the camera
	def Open( self ) :
		# Connect the camera
		error = vimba.VmbCameraOpen( self.id, 1, ct.byref( self.handle ) )
		if error : print( 'Error: Cannot open the camera ({}).'.format(error_type[error]) )
		# Adjust packet size automatically
		error = vimba.VmbFeatureCommandRun( self.handle, 'GVSPAdjustPacketSize' )
		if error : print( 'Error: Cannot adjust the packet size ({}).'.format(error_type[error]) )
		# Query image parameters
		tmp_value = ct.c_int()
		error = vimba.VmbFeatureIntGet( self.handle, 'Width', ct.byref( tmp_value ) )
		if error : print( 'Error: Cannot get the image width ({}).'.format(error_type[error]) )
		self.width = tmp_value.value
		error = vimba.VmbFeatureIntGet( self.handle, 'Height', ct.byref( tmp_value ) )
		if error : print( 'Error: Cannot get the image height ({}).'.format(error_type[error]) )
		self.height = tmp_value.value
		error = vimba.VmbFeatureIntGet( self.handle, 'PayloadSize', ct.byref( tmp_value ) )
		if error : print( 'Error: Cannot get the image payload size ({}).'.format(error_type[error]) )
		self.payloadsize = tmp_value.value
	# Close the camera
	def Close( self ) :
		error = vimba.VmbCameraClose( self.handle )
		if error : print( 'Error: Cannot close the camera ({}).'.format(error_type[error]) )
	# Start the acquisition
	def StartCapture( self, frame_callback, frame_buffer_size = 10 ) :
		# Register the external frame callback function
		self.frame_callback = frame_callback
		# Allocate and announce the frames
		for i in range( frame_buffer_size ) :
			# Allocate the frame accordingly
			self.frame_buffer.append( VmbFrame() )
			self.frame_buffer[i].buffer = ct.create_string_buffer( self.payloadsize )
			self.frame_buffer[i].bufferSize = ct.c_uint32( self.payloadsize )
			# Announce the frame
			error = vimba.VmbFrameAnnounce( self.handle, ct.byref( self.frame_buffer[i] ), ct.sizeof( self.frame_buffer[i] ) )
			if error : print( 'Error: Cannot announce the frame ({}).'.format(error_type[error]) )
		# Start capture engine
		error = vimba.VmbCaptureStart( self.handle )
		if error : print( 'Error: Cannot start the capture ({}).'.format(error_type[error]) )
		# Queue the frames
		for i in range( frame_buffer_size ) :
			error = vimba.VmbCaptureFrameQueue( self.handle, ct.byref( self.frame_buffer[i] ), self.vmb_frame_callback )
			if error : print( 'Error: Cannot queue the frame ({}).'.format(error_type[error]) )
		# Start acquisition
		error = vimba.VmbFeatureCommandRun( self.handle, 'AcquisitionStart' )
		if error : print( 'Error: Cannot start the acquisition ({}).'.format(error_type[error]) )
	# Stop the acquisition
	def StopCapture( self ) :
		# Stop acquisition
		error = vimba.VmbFeatureCommandRun( self.handle, 'AcquisitionStop' )
		if error : print( 'Error: Cannot stop the acquisition ({}).'.format(error_type[error]) )
		# Flush the frame queue
		error = vimba.VmbCaptureQueueFlush( self.handle )
		if error : print( 'Error: Cannot flush the frame queue ({}).'.format(error_type[error]) )
		# Stop capture engine
		error = vimba.VmbCaptureEnd( self.handle )
		if error : print( 'Error: Cannot end the capture ({}).'.format(error_type[error]) )
		# Revoke frames
		error = vimba.VmbFrameRevokeAll( self.handle )
		if error : print( 'Error: Cannot revoke the frames ({}).'.format(error_type[error]) )
		# Initialize the frame buffer
		self.frame_buffer = []
	# Function called by Vimba to receive the frame
	def VmbFrameCallback( self, camera, frame ) :
		# Check the frame
		if frame.contents.is_valid :
			# Call external frame callback function
			self.frame_callback( frame.contents )
		# Requeue the frame so it can be filled again
		error = vimba.VmbCaptureFrameQueue( camera, frame, self.vmb_frame_callback )
		if error : print( 'Error: Cannot requeue the frame ({}).'.format(error_type[error]) )

# Vimba stereo camera
class VmbStereoCamera( object ) :
	# Initialize the cameras
	def __init__( self, camera_left_id, camera_right_id ) :
		self.camera_left = VmbCamera( camera_left_id )
		self.camera_right = VmbCamera( camera_right_id )
	# Open the cameras
	def Open( self ) :
		self.camera_left.Open()
		self.camera_right.Open()
	# Close the cameras
	def Close( self ) :
		self.camera_left.Close()
		self.camera_right.Close()
	# Start synchronous acquisition
	def StartCapture( self, frame_callback ) :
		# Register the external image callback function
		self.frame_callback = frame_callback
		# Initialize the frames
		self.frame_left = None
		self.frame_right = None
		# Start acquisition
		self.camera_left.StartCapture( self.FrameCallbackLeft )
		self.camera_right.StartCapture( self.FrameCallbackRight )
	# Stop the acquisition
	def StopCapture( self ) :
		self.camera_left.StopCapture()
		self.camera_right.StopCapture()
	# Receive a frame from camera left
	def FrameCallbackLeft( self, frame ) :
		# Save the current frame
		self.frame_left = frame
		# Synchronize the frames
		self.Synchronize()
	# Receive a frame from camera right
	def FrameCallbackRight( self, frame ) :
		# Save the current frame
		self.frame_right = frame
		# Synchronize the frames
		self.Synchronize()
	# Synchronize the frames from both camera
	def Synchronize( self ) :
		# Wait for both frames
		if self.frame_left and self.frame_right :
			# Send the frames to the external program
			self.frame_callback( self.frame_left, self.frame_right )
			# Initialize the frames
			self.frame_left = None
			self.frame_right = None
