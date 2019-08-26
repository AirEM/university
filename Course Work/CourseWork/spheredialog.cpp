#include "spheredialog.h"
#include "ui_spheredialog.h"

SphereDialog::SphereDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SphereDialog)
{
    ui->setupUi(this);
}

SphereDialog::~SphereDialog()
{
    delete ui;
}

void SphereDialog::on_addPushButton_clicked()
{

}
