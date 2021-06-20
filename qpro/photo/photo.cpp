#include "photo.h"
#include "ui_photo.h"
#include <QDebug>

photo::photo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::photo)
{
    ui->setupUi(this);
}

photo::~photo()
{
    delete ui;
}

void photo::on_photoback_clicked()
{
    emit photo_change2_main_ui();
}


void photo::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"img",".","*.jpg *.png *.bmp");
    qDebug()<<file_name;
    QImage img;
    img.load(file_name);
    ui->photolabel->setPixmap(QPixmap::fromImage(img).scaled(ui->photolabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}




