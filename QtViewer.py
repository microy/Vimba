#! /usr/bin/env python
# -*- coding:utf-8 -*-

#
# Test application to display live images from an Allied Vision camera using Qt4
#

# External dependencies
import sys
import numpy as np
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5 import QtWidgets
import Vimba

# Class to display images from an Allied Vision camera
class QtVmbViewer( QtWidgets.QWidget ) :
	# Signal sent to update the image in the widget
	update_image = QtCore.pyqtSignal()
	# Initialization
	def __init__( self, parent = None ) :
		# Initialise QWidget
		super( QtVmbViewer, self ).__init__( parent )
		# Set the window title
		self.setWindowTitle( 'StereoVision' )
		# Connect the signal to update the image
		self.update_image.connect( self.UpdateImage )
		# Widget to display the images from the cameras
		self.image_widget = QtWidgets.QLabel( self )
		self.image_widget.setScaledContents( True )
		# Widget layout
		self.layout = QtWidgets.QVBoxLayout( self )
		self.layout.addWidget( self.image_widget )
		self.layout.setSizeConstraint( QtWidgets.QLayout.SetFixedSize )
		# Set the Escape key to close the application
		QtWidgets.QShortcut( QtGui.QKeySequence( QtCore.Qt.Key_Escape ), self ).activated.connect( self.close )
		# Initialize Vimba
		Vimba.VmbStartup()
		# Initialize the camera
		self.camera = Vimba.VmbCamera( '50-0503323406' )
		# Open the camera
		self.camera.Open()
		# Create a QImage to store the image from the camera
		self.image = QtGui.QImage( self.camera.width, self.camera.height, QtGui.QImage.Format_Indexed8 )
		# Create a indexed color table
		self.image.setColorCount(256)
		for i in range( 256 ) : self.image.setColor( i, QtGui.qRgb(i, i, i) )
		# Start image acquisition
		self.camera.StartCapture(  self.ImageCallback  )
	# Receive the frame sent by the camera
	def ImageCallback( self, frame ) :
		# Get the pointer of the Qt image data
		image_pointer = self.image.bits()
		image_pointer.setsize( frame.bufferSize )
		# Store the camera frame buffer in the Qt image
		image_pointer[ 0 : frame.bufferSize ] = frame.buffer[ 0 : frame.bufferSize ]
		# Update the image in the widget
		self.update_image.emit()
	# Process the given image
	def UpdateImage( self ) :
		# Set the image to the Qt widget
		self.image_widget.setPixmap( QtGui.QPixmap.fromImage( self.image ).scaled( self.camera.width*0.3, self.camera.height*0.3, QtCore.Qt.KeepAspectRatio ) )
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
application = QtWidgets.QApplication( sys.argv )
widget = QtVmbViewer()
widget.show()
sys.exit( application.exec_() )
