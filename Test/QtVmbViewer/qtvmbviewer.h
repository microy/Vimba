#ifndef QTVMBVIEWER_H
#define QTVMBVIEWER_H

#include <QWidget>
#include <VimbaC.h>


class QtVmbViewer : public QWidget
{
    Q_OBJECT

public:
    QtVmbViewer(QWidget *parent = 0);
    ~QtVmbViewer();

    // Handle to the camera
    VmbHandle_t camera_handle = NULL;
    // Image parameters
    VmbInt64_t width;
    VmbInt64_t height;
    VmbInt64_t payloadsize;
    // Frame buffer
    VmbFrame_t frames[10];
    // Function called by Vimba to receive the frame
    static void VMB_CALL FrameDoneCallback( const VmbHandle_t hCamera, VmbFrame_t * pFrame );

};

#endif // QTVMBVIEWER_H
