#ifndef PHOTO_H
#define PHOTO_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class photo;
}

class photo : public QWidget
{
    Q_OBJECT

public:
    explicit photo(QWidget *parent = nullptr);
    ~photo();

signals:
    void photo_change2_main_ui();

private slots:
    void on_photoback_clicked();

    void on_pushButton_clicked();

private:
    Ui::photo *ui;
};

#endif // PHOTO_H
