#include "figuredialog.h"
#include "ui_figuredialog.h"

FigureDialog::FigureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FigureDialog),
    _facade(new Facade)
{
    ui->setupUi(this);
}

FigureDialog::~FigureDialog()
{
    delete ui;
}


void FigureDialog::setId(int id)
{
    _id = id;
}


void FigureDialog::on_addPushButton_clicked()
{
//    command::AddSphereCommand command(0, 0, 10, )
//    _facade->execute(&command_l);

    this->close();
}
