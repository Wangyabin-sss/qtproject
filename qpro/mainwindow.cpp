#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置桌面背景
    setAutoFillBackground(true); //设置窗体自动填充背景
    QPalette palette;
    QPixmap pixmap(":/image/background.bmp");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    this->setPalette(palette); // 图片尺寸要和widget等大小 如果图片尺寸小  就会重复排列

    QObject::connect(&cam,SIGNAL(camera_change2_main_ui()),this,SLOT(ui_camera_hander()));
    QObject::connect(&pho,SIGNAL(photo_change2_main_ui()),this,SLOT(ui_photo_hander()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_camera_clicked()  //摄像头app
{
    this->hide();
    cam.show();
    cam.camthread.start();
}


void MainWindow::ui_camera_hander()
{
    cam.close();
    this->show();
}

void MainWindow::on_photo_clicked() //照片app
{
    this->hide();
    pho.show();
}

void MainWindow::ui_photo_hander()
{
    pho.close();
    this->show();
}




