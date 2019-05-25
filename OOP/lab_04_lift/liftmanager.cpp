#include "liftmanager.h"

LiftManager::LiftManager(QObject *parent) : QObject(parent)
{
    this->currentFloor = 1;
    this->currentDirection = Direction::STOPED;

    this->lift = new Lift;
    this->doors = new Doors;

    connect(this, SIGNAL(RiseSignal()), lift, SLOT(RiseSlot()));
    connect(this, SIGNAL(DescendSignal()), lift, SLOT(DescendSlot()));
    connect(this, SIGNAL(WaitSignal()), lift, SLOT(WaitSlot()));
    connect(this, SIGNAL(UndefinedWaitingSignal()), lift, SLOT(UndefinedWaitingSlot()));

    connect(lift, SIGNAL(ChangeFloorSignal()), this, SLOT(ChangeFloorSlot()));
    connect(lift, SIGNAL(ChangeLiftStateSignal(LiftState)), this, SLOT(ChangeLiftStateSlot(LiftState)));

    connect(this, SIGNAL(OpenDoorsSignal()), doors, SLOT(OpenDoorsSlot()));
    connect(doors, SIGNAL(ChangeDoorsStateSignal(DoorsState)), this,
            SLOT(ChangeDoorsStateSlot(DoorsState)));

    connect(this, SIGNAL(NeedMoveSignal()), this, SLOT(NeedMoveSlot()));
}


void LiftManager::FloorSelectionSlot(int floor)
{
    this->existingFloors[floor  - 1] = 1;

    if (currentDirection == Direction::STOPED)
    {
        if (currentFloor < floor)
        {
            this->currentDirection = Direction::UP;
            emit RiseSignal();
            emit ChandgeDirectionSignal(Direction::UP);
        }
        else if (currentFloor == floor)
        {
            this->existingFloors[floor  - 1] = 0;
            emit ChandgeFloorSignal(currentFloor);
            emit WaitSignal();
            emit OpenDoorsSignal();
        }
        else
        {
            this->currentDirection = Direction::DOWN;
            emit DescendSignal();
            emit ChandgeDirectionSignal(Direction::DOWN);
        }
    }

}


void LiftManager::ChangeLiftStateSlot(LiftState state)
{
    emit ChangeLiftStateSignal(state);
}

void LiftManager::ChangeFloorSlot()
{
    bool isFloor = 0;

    if (this->currentDirection == Direction::UP)
        currentFloor++;
    else
        currentFloor--;


    emit ChandgeFloorSignal(currentFloor);

    // Проверка на нужный этаж

    isFloor = this->existingFloors[currentFloor - 1];
    this->existingFloors[currentFloor - 1] = 0;

    if (isFloor)
    {
        emit WaitSignal();
        emit OpenDoorsSignal();
    }
    else
        emit NeedMoveSignal();
}


void LiftManager::ChangeDoorsStateSlot(DoorsState state)
{
    emit ChangeDoorsStateSignal(state);

    if (state == DoorsState::CLOSED)
        emit NeedMoveSignal();
}



void LiftManager::NeedMoveSlot()
{
    if (this->currentDirection == Direction::UP)
    {
        if (need_up(currentFloor))
            emit RiseSignal();
        else if (need_down(currentFloor))
        {
            this->currentDirection = Direction::DOWN;
            emit ChandgeDirectionSignal(this->currentDirection);
            emit DescendSignal();
        }
        else
        {
            this->currentDirection = Direction::STOPED;
            emit ChandgeDirectionSignal(this->currentDirection);
            emit UndefinedWaitingSignal();
        }
    }
    else// if (this->currentDirection == Direction::DOWN)
    {
        if (need_down(currentFloor))
            emit DescendSignal();
        else if (need_up(currentFloor))
        {
            this->currentDirection = Direction::UP;
            emit ChandgeDirectionSignal(this->currentDirection);
            emit RiseSignal();
        }
        else
        {
            this->currentDirection = Direction::STOPED;
            emit ChandgeDirectionSignal(this->currentDirection);
            emit UndefinedWaitingSignal();
        }
    }

}



bool LiftManager::need_up(int floor)
{
    for (int i = floor; i <= numberFloors; i++)
        if (existingFloors[i - 1])
            return true;

    return false;
}

bool LiftManager::need_down(int floor)
{
    for (int i = floor; i > 0; i--)
        if (existingFloors[i - 1])
            return true;

    return false;
}
