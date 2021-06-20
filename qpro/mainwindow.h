#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera/camera.h"
#include "photo/photo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_camera_clicked();
    void ui_camera_hander();

    void on_photo_clicked();
    void ui_photo_hander();

private:
    Ui::MainWindow *ui;
    camera cam;
    photo pho;
};
#endif // MAINWINDOW_H
