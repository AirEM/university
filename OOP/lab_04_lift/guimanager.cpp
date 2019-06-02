#include "guimanager.h"

GuiManager::GuiManager()
{
    liftmanager = new LiftManager;

    // from Doors
    connect(this->liftmanager, SIGNAL(OpenDoorsSignal()), this, SLOT(OpeningSlot())); // opening
    connect(&(this->liftmanager->doors->OpeningTimer), SIGNAL(timeout()), this, SLOT(OpenedSlot())); // opened
    connect(&(this->liftmanager->doors->WaitingTimer), SIGNAL(timeout()), this, SLOT(ClosingSlot())); // closing
    connect(&(this->liftmanager->doors->ClosingTimer), SIGNAL(timeout()), this, SLOT(ClosedSlot())); // closed

    // to LiftManager
    connect(this, SIGNAL(FloorSelectionSignal(int)), liftmanager, SLOT(WaitSlot(int)));

    // from LiftManager

    // floor number
    connect(&(this->liftmanager->lift->UpTimer), SIGNAL(timeout()), this, SLOT(ChangeFloorSlot()));
    connect(&(this->liftmanager->lift->DownTimer), SIGNAL(timeout()), this, SLOT(ChangeFloorSlot()));

    // lift state
    connect(liftmanager, SIGNAL(RiseSignal()), this, SLOT(RiseSlot()));
    connect(liftmanager, SIGNAL(DescendSignal()), this, SLOT(DescendSlot()));
    connect(liftmanager, SIGNAL(WaitSignal()), this, SLOT(WaitSlot()));
}

GuiManager::~GuiManager()
{
    delete liftmanager;
}

void GuiManager::FloorSelectionSlot(int floor)
{
    emit FloorSelectionSignal(floor);
}


void GuiManager::ChangeFloorSlot()
{
    emit ChangeFloorSignal(liftmanager->get_floor());
}


void GuiManager::RiseSlot()
{
    emit ChangeLiftStateSiglal(QString("Движение вверх"));
}

void GuiManager::DescendSlot()
{
    emit ChangeLiftStateSiglal(QString("Движение вниз"));
}

void GuiManager::WaitSlot()
{
    emit ChangeLiftStateSiglal(QString("Ожидание"));
}


void GuiManager::OpeningSlot() // openeing
{
    emit ChangeDoorsStateSiglal(QString("Открываются"));
}
void GuiManager::OpenedSlot()  // opened
{
    emit ChangeDoorsStateSiglal(QString("Открыты"));
}

void GuiManager::ClosingSlot() // closing
{
    emit ChangeDoorsStateSiglal(QString("Закрываются"));
}

void GuiManager::ClosedSlot()  // closed
{
    emit ChangeDoorsStateSiglal(QString("Закрыты"));
}
