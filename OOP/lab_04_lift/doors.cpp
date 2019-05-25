#include "doors.h"

Doors::Doors(QObject *parent) : QObject(parent)
{
    this->currentState = DoorsState::CLOSED;

    this->MovingTimer.setSingleShot(true);
    this->WaitingTimer.setSingleShot(true);

    connect(&MovingTimer, SIGNAL(timeout()), this, SLOT(EndMovingTimerSlot()));
    connect(&WaitingTimer, SIGNAL(timeout()), this, SLOT(EndWaitingTimerSlot()));
}

void Doors::OpenDoorsSlot()
{
    this->currentState = DoorsState::OPENING;
    emit ChangeDoorsStateSignal(this->currentState);
    this->MovingTimer.start(2000);
}


void Doors::EndMovingTimerSlot()
{
    if (this->currentState == DoorsState::OPENING)
    {
        this->currentState = DoorsState::OPENED;
        this->WaitingTimer.start(2000);
    }
    else
        this->currentState = DoorsState::CLOSED;

    emit ChangeDoorsStateSignal(this->currentState);
}

void Doors::EndWaitingTimerSlot()
{
    if (this->currentState == DoorsState::OPENED)
    {
        this->currentState = DoorsState::CLOSING;
        emit ChangeDoorsStateSignal(this->currentState);
        this->MovingTimer.start(2000);
    }
}
