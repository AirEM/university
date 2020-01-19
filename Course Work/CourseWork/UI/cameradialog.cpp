#include "cameradialog.h"
#include "ui_cameradialog.h"

CameraDialog::CameraDialog(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::CameraDialog),
    _facade(new Facade)
{
    _ui->setupUi(this);
}

CameraDialog::~CameraDialog()
{
    delete _ui;
}

void CameraDialog::on_canselPushButton_clicked()
{
    this->close();
}


void CameraDialog::on_changePushButton_clicked()
{
    auto x = _ui->xLineEdit->text().toFloat();
    auto y = _ui->yLineEdit->text().toFloat();
    auto z = _ui->zLineEdit->text().toFloat();

    auto xRotate = _ui->xRotateLineEdit->text().toFloat();
    auto yRotate = _ui->yRotateLineEdit->text().toFloat();

    command::MoveCameraCommand moveCommand(x, y, z);
    _facade->execute(&moveCommand);

    command::RotateCameraCommand rotateCommand(xRotate, yRotate);
    _facade->execute(&rotateCommand);

    this->close();
}
