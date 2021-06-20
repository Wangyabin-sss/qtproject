/********************************************************************************
** Form generated from reading UI file 'photo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTO_H
#define UI_PHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_photo
{
public:
    QPushButton *photoback;
    QLabel *photolabel;
    QPushButton *pushButton;

    void setupUi(QWidget *photo)
    {
        if (photo->objectName().isEmpty())
            photo->setObjectName(QString::fromUtf8("photo"));
        photo->resize(800, 480);
        photoback = new QPushButton(photo);
        photoback->setObjectName(QString::fromUtf8("photoback"));
        photoback->setGeometry(QRect(740, 10, 50, 25));
        photolabel = new QLabel(photo);
        photolabel->setObjectName(QString::fromUtf8("photolabel"));
        photolabel->setGeometry(QRect(20, 20, 691, 441));
        pushButton = new QPushButton(photo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 90, 50, 50));

        retranslateUi(photo);

        QMetaObject::connectSlotsByName(photo);
    } // setupUi

    void retranslateUi(QWidget *photo)
    {
        photo->setWindowTitle(QCoreApplication::translate("photo", "Form", nullptr));
        photoback->setText(QCoreApplication::translate("photo", "\350\277\224\345\233\236", nullptr));
        photolabel->setText(QCoreApplication::translate("photo", "photo", nullptr));
        pushButton->setText(QCoreApplication::translate("photo", "\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class photo: public Ui_photo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTO_H
