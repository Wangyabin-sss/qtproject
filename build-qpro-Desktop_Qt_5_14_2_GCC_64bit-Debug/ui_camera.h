/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QPushButton *camerabacktomain;
    QLabel *cameraframe;
    QPushButton *getoneframe;
    QPushButton *showgetframe;

    void setupUi(QWidget *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QString::fromUtf8("camera"));
        camera->resize(800, 480);
        camerabacktomain = new QPushButton(camera);
        camerabacktomain->setObjectName(QString::fromUtf8("camerabacktomain"));
        camerabacktomain->setGeometry(QRect(740, 10, 50, 25));
        cameraframe = new QLabel(camera);
        cameraframe->setObjectName(QString::fromUtf8("cameraframe"));
        cameraframe->setGeometry(QRect(20, 20, 701, 441));
        getoneframe = new QPushButton(camera);
        getoneframe->setObjectName(QString::fromUtf8("getoneframe"));
        getoneframe->setGeometry(QRect(740, 80, 50, 50));
        showgetframe = new QPushButton(camera);
        showgetframe->setObjectName(QString::fromUtf8("showgetframe"));
        showgetframe->setGeometry(QRect(740, 180, 50, 50));

        retranslateUi(camera);

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QWidget *camera)
    {
        camera->setWindowTitle(QCoreApplication::translate("camera", "Form", nullptr));
        camerabacktomain->setText(QCoreApplication::translate("camera", "\350\277\224\345\233\236", nullptr));
        cameraframe->setText(QCoreApplication::translate("camera", "cameraframe", nullptr));
        getoneframe->setText(QCoreApplication::translate("camera", "\346\212\223\346\213\215", nullptr));
        showgetframe->setText(QCoreApplication::translate("camera", "\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
