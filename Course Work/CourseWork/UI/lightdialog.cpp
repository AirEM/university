#include "lightdialog.h"
#include "ui_lightdialog.h"

LightDialog::LightDialog(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::LightDialog),
    _facade(new Facade)
{
    _ui->setupUi(this);
}

LightDialog::~LightDialog()
{
    delete _ui;
}


void LightDialog::setId(int id)
{
    _id = id;
}


void LightDialog::on_addPushButton_clicked()
{
    auto x =_ui->xLineEdit->text().toFloat();
    auto y =_ui->yLineEdit->text().toFloat();
    auto z =_ui->zLineEdit->text().toFloat();

    auto intensity = _ui->intensityLineEdit->text().toFloat();

    command::AddLightCommand command_l(x, y, z, intensity, _id);
    _facade->execute(&command_l);

    this->close();
}
