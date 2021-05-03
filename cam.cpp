#include "cam.h"
#include "ui_cam.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

Cam::Cam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cam)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOpcionesMenu = new QMenu("Options", this);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);
    mCamera->start();
}

Cam::~Cam()
{
    mCamera->stop();
    delete ui;
}

void Cam::on_Capturer_clicked()
{
    auto filename = QFileDialog::getSaveFileName(this, "Capturer", "/", "Image (*.jpg;*.jpeg)");
    if(filename.isEmpty()) {
        return;
    }
    mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    QImageEncoderSettings imageEncoderSettings;
    imageEncoderSettings.setCodec("Camera/jpeg");
    imageEncoderSettings.setResolution(1920, 1080);
    mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
    mCamera->setCaptureMode(QCamera::CaptureStillImage);
    mCamera->start();
    mCamera->searchAndLock();
    mCameraImageCapture->capture(filename);
    mCamera->unlock();
}
