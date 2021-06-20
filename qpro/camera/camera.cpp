#include "camera.h"
#include "ui_camera.h"
#include <opencv.hpp>
#include <imgproc.hpp>
#include <core.hpp>

camera::camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);
    saveflag=0;showimg=-1;imgnum=0;path="/home/ubuntu/Desktop/qt/qtproject/qpro/image/usr/getimg"; //变量初始化
    QObject::connect(&camthread,SIGNAL(camerashowimage(QImage)),this,SLOT(camshowimage(QImage))); //将video0图像获取线程里的信号与显示函数绑定
}

camera::~camera()
{
    delete ui;
}

void camera::on_camerabacktomain_clicked()  //返回主界面按钮
{
    camthread.stop();
    emit camera_change2_main_ui();
}

void camera::on_getoneframe_clicked()   // 抓拍照片
{
    saveflag=1;
}

void camera::on_showgetframe_clicked() //显示最近一次抓拍
{
    if(imgnum==0)  //判断那个是当前抓拍
        showimg=0;
    else
        showimg=imgnum-1;
    QImage imgjpg;
    int i=imgjpg.load(path+QString::number(showimg)+".jpg");
    if(i!=0)
        ui->cameraframe->setPixmap(QPixmap::fromImage(imgjpg).scaled(ui->cameraframe->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    else
        std::cout<<"图片不存在"<<std::endl;
    ui->showgetframe->setText(QString::number(showimg));
}

void camera::camshowimage(QImage img)
{
    if(showimg!=-1)
    {
        QTimer::singleShot(1500, this, SLOT(timerupdata())); //图片显示1.5秒
    }
    else
    {
        ui->cameraframe->setPixmap(QPixmap::fromImage(img).scaled(ui->cameraframe->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation)); //显示图像帧
        if(saveflag==1)
        {
            saveflag=0;
            img.save(path+QString::number(imgnum)+".jpg","JPG");
            imgnum++;
            if(imgnum>20) //控制抓拍照片数量
                imgnum=0;
        }
    }

}

void camera::timerupdata()
{
    showimg=-1;
}

void CameraThread::run()
{
    flag=1;
    cv::VideoCapture cap(0);
    if(!cap.isOpened()){
        std::cout<<"摄像头打开失败"<<std::endl;
        return;
    }
    else{
        std::cout<<"摄像头打开成功"<<std::endl;
    }

    cv::Mat frame;
    QImage imgout;
    while (1)
    {
        cap >> frame;
        cv::cvtColor(frame,frame,cv::COLOR_BGR2RGB);
        imgout =QImage((const unsigned char*)(frame.data),
                        frame.cols, frame.rows,
                        frame.cols*frame.channels(),
                        QImage::Format_RGB888);
        if(flag==0) //写在信号之前防止异常信号产生，调用stop后不会产生信号
            break;
        emit camerashowimage(imgout);
    }
    return;
}

void CameraThread::stop()
{
    flag=0;
}
