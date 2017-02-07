#! /usr/bin/env python
# -*- coding:utf-8 -*-

#
# Test application to display live images from an Allied Vision camera using Qt4
#

# External dependencies
import sys
import cv2
import numpy as np
from PySide import QtCore
from PySide import QtGui
import Vimba

# Class to display images from an Allied Vision camera
class QtVmbViewer( QtGui.QWidget ) :
	# Signal sent to update the image in the widget
	update_image = QtCore.Signal( np.ndarray )
	# Initialization
	def __init__( self, parent = None ) :
		# Initialise QWidget
		super( QtVmbViewer, self ).__init__( parent )
		# Set the window title
		self.setWindowTitle( 'StereoVision' )
		# Connect the signal to update the image
		self.update_image.connect( self.UpdateImage )
		# Widget to display the images from the cameras
		self.image_widget = QtGui.QLabel( self )
		self.image_widget.setScaledContents( True )
		# Widget layout
		self.layout = QtGui.QVBoxLayout( self )
		self.layout.addWidget( self.image_widget )
		self.layout.setSizeConstraint( QtGui.QLayout.SetFixedSize )
		# Set the Escape key to close the application
		QtGui.QShortcut( QtGui.QKeySequence( QtCore.Qt.Key_Escape ), self ).activated.connect( self.close )
		# Initialize Vimba
		Vimba.VmbStartup()
		# Initialize the camera
		self.camera = Vimba.VmbCamera( '50-0503323406' )
		# Open the camera
		self.camera.Open()
		# Start image acquisition
		self.camera.StartCapture(  self.ImageCallback  )
	# Receive the frame sent by the camera
	def ImageCallback( self, frame ) :
		# Check the frame
		if not frame.is_valid : return
		# Send the image to the widget
		self.update_image.emit( frame.image )
	# Process the given image
	def UpdateImage( self, image ) :
		# Resize image for display
		image = cv2.resize( image, None, fx=0.4, fy=0.4 )
		# Convert image color format from Grayscale to RGB
		image = cv2.cvtColor( image, cv2.COLOR_GRAY2RGB )
		# Create a Qt image
		qimage = QtGui.QImage( image, image.shape[1], image.shape[0], QtGui.QImage.Format_RGB888 )
		# Set the image to the Qt widget
		self.image_widget.setPixmap( QtGui.QPixmap.fromImage( qimage ) )
		# Update the widget
		self.image_widget.update()
	# Close the widgets
	def closeEvent( self, event ) :
		# Stop image acquisition
		self.camera.StopCapture()
		# Close the camera
		self.camera.Close()
		# Shutdown Vimba
		Vimba.VmbShutdown()
		# Close main application
		event.accept()

# Main application
application = QtGui.QApplication( sys.argv )
widget = QtVmbViewer()
widget.show()
sys.exit( application.exec_() )
