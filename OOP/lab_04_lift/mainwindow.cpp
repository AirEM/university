#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->guimanager = new GuiManager;

    ui->setupUi(this);

    radioButVector.push_back(ui->radioButtonFirst);
    radioButVector.push_back(ui->radioButtonSecond);
    radioButVector.push_back(ui->radioButtonThird);
    radioButVector.push_back(ui->radioButtonFour);
    radioButVector.push_back(ui->radioButtonFifth);
    radioButVector.push_back(ui->radioButtonSixth);

    guimanager = new GuiManager;

    connect(ui->pushButtonFirst, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonSecond, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonThird, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonFour, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonFifth, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonSixth, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));

    connect(this, SIGNAL(FloorSelectionSignal(int)),
            guimanager, SLOT(FloorSelectionSlot(int)));

    connect(this->guimanager, SIGNAL(ChangeFloorSignal(int)),
            this, SLOT(ChangeFloorSlot(int)));

    connect(this->guimanager, SIGNAL(ChangeLiftStateSiglal(QString)),
            this, SLOT(ChangeLiftStateSlot(QString)));
    connect(this->guimanager, SIGNAL(ChangeDoorsStateSiglal(QString)),
            this, SLOT(ChangeDoorsStateSlot(QString)));

}

MainWindow::~MainWindow()
{
    delete guimanager;
    delete ui;
}


void MainWindow::FloorSelectionSlot()
{
    QPushButton* button = static_cast<QPushButton*>(sender());
    const int floorNumber = button->text()[0].digitValue();

    this->radioButVector.at(floorNumber - 1)->setChecked(true);

    emit FloorSelectionSignal(floorNumber);
}


void MainWindow::ChangeFloorSlot(int floor)
{
    this->ui->lcdNumber->display(floor);
    this->radioButVector.at(floor - 1)->setChecked(false);
}


void MainWindow::ChangeLiftStateSlot(QString state)
{
    this->ui->labelLiftState->setText(state);
}

void MainWindow::ChangeDoorsStateSlot(QString state)
{
    this->ui->labelDoorsState->setText(state);
}
