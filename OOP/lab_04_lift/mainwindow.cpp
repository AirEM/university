#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->liftmanager = new LiftManager;

    ui->setupUi(this);

    connect(ui->pushButtonFirst, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonSecond, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonThird, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonFour, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonFifth, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));
    connect(ui->pushButtonSixth, SIGNAL(clicked()), this, SLOT(FloorSelectionSlot()));

    radioButVector.push_back(ui->radioButtonFirst);
    radioButVector.push_back(ui->radioButtonSecond);
    radioButVector.push_back(ui->radioButtonThird);
    radioButVector.push_back(ui->radioButtonFour);
    radioButVector.push_back(ui->radioButtonFifth);
    radioButVector.push_back(ui->radioButtonSixth);

    connect(this, SIGNAL(FloorSelectionSignal(int)),
            liftmanager, SLOT(FloorSelectionSlot(int)));

    connect(liftmanager, SIGNAL(ChandgeDirectionSignal(Direction)),
            this, SLOT(ChandgeDirectionSlot(Direction)));

    connect(liftmanager, SIGNAL(ChandgeFloorSignal(int)),
            this, SLOT(ChangeFloorSlot(int)));

    connect(liftmanager, SIGNAL(ChangeLiftStateSignal(LiftState)),
            this, SLOT(ChangeLiftStateSlot(LiftState)));

    connect(liftmanager, SIGNAL(ChangeDoorsStateSignal(DoorsState)),
            this, SLOT(ChangeDoorsStateSlot(DoorsState)));
}

MainWindow::~MainWindow()
{
    delete liftmanager;
    delete ui;
}


void MainWindow::FloorSelectionSlot()
{
    QPushButton* button = static_cast<QPushButton*>(sender());
    const int floorNumber = button->text()[0].digitValue();

    this->radioButVector.at(floorNumber - 1)->setChecked(true);

    emit FloorSelectionSignal(floorNumber);
}

void MainWindow::ChandgeDirectionSlot(Direction d)
{
    switch (d)
    {
    case Direction::UP:
        this->ui->labelDirection->setText(QString("UP"));
        break;
    case Direction::DOWN:
        this->ui->labelDirection->setText(QString("DOWN"));
        break;
    case Direction::STOPED:
        this->ui->labelDirection->setText(QString("STOP"));
        break;

    }
}

void MainWindow::ChangeLiftStateSlot(LiftState state)
{
    switch (state)
    {
    case LiftState::RISE:
        this->ui->labelLiftState->setText(QString("Движение вверх"));
        break;
    case LiftState::DESCEND:
        this->ui->labelLiftState->setText(QString("Движение вниз"));
        break;
    case LiftState::ON_FLOOR:
        this->ui->labelLiftState->setText(QString("Прибытие на этаж"));
        break;
    case LiftState::WAIT:
        this->ui->labelLiftState->setText(QString("Ожидание"));
        break;
    case LiftState::UNDEFINED_WAITING:
        this->ui->labelLiftState->setText(QString("NONE"));
        break;

    }
}

void MainWindow::ChangeDoorsStateSlot(DoorsState state)
{
    switch (state)
    {
    case DoorsState::OPENING:
        this->ui->labelDoorsState->setText(QString("Открываются"));
        break;
    case DoorsState::OPENED:
        this->ui->labelDoorsState->setText(QString("Открыты"));
        break;
    case DoorsState::CLOSING:
        this->ui->labelDoorsState->setText(QString("Закрываются"));
        break;
    case DoorsState::CLOSED:
        this->ui->labelDoorsState->setText(QString("Закрыты"));
        break;

    }
}

void MainWindow::ChangeFloorSlot(int floor)
{
    this->ui->lcdNumber->display(floor);
    this->radioButVector.at(floor - 1)->setChecked(false);
}
