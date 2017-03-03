#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QPointer>
#include <QCamera>
#include <QLabel>
#include <QCameraViewfinder>
#include <QPushButton>
#include <QTimer>
#include <QCameraImageCapture>

class Camera : public QWidget
{
    Q_OBJECT

public:
    void show();
    Camera(QWidget *parent = 0);
private:
    QPointer<QCamera> _camera;
    QPointer<QCameraViewfinder> _cameraViewer;
    QPointer<QLabel> _labelTimer;
    QPointer<QTimer> _timer;
    QPointer<QCameraImageCapture> _imageCapture;
    QPointer<QLabel> _qLabelImage;
    void timer();
    int randInt(int low, int high);
    double _dRand;
protected slots:
    void updateTimer();
};

#endif // CAMERA_H
