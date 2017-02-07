#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T16:15:44
#
#-------------------------------------------------


RC_FILE += icon.rc
QT      += core gui serialport multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#Bib pour la cam
DEFINES += AVT_VMBAPI_CPP_EXPORTS
DEFINES += AVT_VMBAPI_CPP_LIB  __ELF__

INCLUDEPATH += D:\Logiciels\Qt\Tools\Vimba_2.0
INCLUDEPATH += D:\Logiciels\Qt\Tools\Vimba_2.0\VimbaCPP\Include
INCLUDEPATH += D:\Logiciels\Qt\Tools\Vimba_2.0\VimbaImageTransform\Include
LIBS += -LD:\Logiciels\Qt\Tools\Vimba_2.0\AVT\build-program-Desktop_Qt_5_7_0_MinGW_32bit-Debug\debug -lVimbaCPP
LIBS += -LD:\Logiciels\Qt\Tools\Vimba_2.0\VimbaImageTransform\Bin\Win32 -lVimbaImageTransform



#Bib pour le plateau
INCLUDEPATH += D:\Logiciels\Qt\Tools\Galil\gclib\include
LIBS += -LD:\Logiciels\Qt\Tools\Galil\gclib\lib\dynamic\x86 -lgclib -lgclibo



TARGET = MovingJoystick
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        mylabel.cpp \
    qtelecommand.cpp \
    qpanelprocess.cpp \
    apropos.cpp \
    optelecommand.cpp \
    qpanelonglets.cpp \
    mylineedit.cpp \
ApiController.cpp \
AsynchronousGrab.cpp \
CameraObserver.cpp \
FrameObserver.cpp




HEADERS  += mainwindow.h \
        mylabel.h \
    qtelecommand.h \
    qpanelprocess.h \
    apropos.h \
    optelecommand.h \
    qpanelonglets.h \
    mylineedit.h \
ApiController.h \
AsynchronousGrab.h \
CameraObserver.h \
FrameObserver.h


FORMS    += mainwindow.ui \
    res/AsynchronousGrab.ui

RESOURCES += \
    res/AsynchronousGrab.qrc




















#RC_FILE += icon.rc
#QT      += core gui serialport multimedia
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




#Bib pour la cam
#DEFINES += AVT_VMBAPI_CPP_EXPORTS
#DEFINES += AVT_VMBAPI_CPP_LIB  __ELF__

#INCLUDEPATH += D:\Logiciels\Qt\Tools\Vimba_2.0
#INCLUDEPATH += D:\Logiciels\Qt\Tools\Vimba_2.0\VimbaCPP\Include
#INCLUDEPATH += D:\Logiciels\Qt\Tools\Vimba_2.0\VimbaImageTransform\Include
#LIBS += -LD:\Logiciels\Qt\Tools\Vimba_2.0\AVT\build-program-Desktop_Qt_5_7_0_MinGW_32bit-Debug\debug -lVimbaCPP
#LIBS += -LD:\Logiciels\Qt\Tools\Vimba_2.0\VimbaImageTransform\Bin\Win32 -lVimbaImageTransform



#Bib pour le plateau
#INCLUDEPATH += D:\Logiciels\Qt\Tools\Galil\gclib\include
#LIBS += -LD:\Logiciels\Qt\Tools\Galil\gclib\lib\dynamic\x86 -lgclib -lgclibo




#TARGET = MovingJoystick
#TEMPLATE = app


#SOURCES += main.cpp\
#        mainwindow.cpp \
#        mylabel.cpp \
#    qtelecommand.cpp \
#    qpanelprocess.cpp \
#    apropos.cpp \
#    optelecommand.cpp \
#    qpanelonglets.cpp \
#    mylineedit.cpp \
#ApiController.cpp \
#AsynchronousGrab.cpp \
#CameraObserver.cpp \
#FrameObserver.cpp




#HEADERS  += mainwindow.h \
#        mylabel.h \
#    qtelecommand.h \
#    qpanelprocess.h \
#    apropos.h \
#    optelecommand.h \
#    qpanelonglets.h \
#    mylineedit.h \
#ApiController.h \
#AsynchronousGrab.h \
#CameraObserver.h \
#FrameObserver.h

#FORMS    += mainwindow.ui \
#    res/AsynchronousGrab.ui

#RESOURCES += \
#    res/AsynchronousGrab.qrc
