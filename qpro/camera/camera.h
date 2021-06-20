#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QThread>
#include <iostream>
#include <string>
#include <QTimer>

namespace Ui {
class camera;
}

class CameraThread : public QThread
{
    Q_OBJECT
protected:
    void run();
public:
    void stop();
signals:
    void camerashowimage(QImage);
private:
    int flag;
};

class camera : public QWidget
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = nullptr);
    ~camera();

signals:
    void change2_camera_ui();

private slots:
    void on_camerabacktomain_clicked();

    void on_getoneframe_clicked();

    void on_showgetframe_clicked();

    void camshowimage(QImage);

    void timerupdata();

private:
    Ui::camera *ui;
    unsigned char saveflag;
    int showimg;
    unsigned int imgnum;
    QString path;
public:
    CameraThread camthread;
};

#endif // CAMERA_H
