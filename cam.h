#ifndef CAM_H
#define CAM_H

#include <QDialog>

namespace Ui {
class Cam;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class Cam : public QDialog
{
    Q_OBJECT

public:
    explicit Cam(QWidget *parent = nullptr);
    ~Cam();

private slots:
    void on_Capturer_clicked();

private:
    Ui::Cam *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpcionesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
};

#endif // CAM_H
