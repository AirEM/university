#include "doors.h"

Doors::Doors(QObject *parent) : QObject(parent)
{
    this->currentState = DoorsState::CLOSED;

    this->OpeningTimer.setSingleShot(true);
    this->ClosingTimer.setSingleShot(true);
    this->WaitingTimer.setSingleShot(true);

    connect(&OpeningTimer, SIGNAL(timeout()), this, SLOT(EndOpeningTimerSlot()));
    connect(&ClosingTimer, SIGNAL(timeout()), this, SLOT(EndClosingTimerSlot()));
    connect(&WaitingTimer, SIGNAL(timeout()), this, SLOT(EndWaitingTimerSlot()));
}

void Doors::OpenDoorsSlot()
{
    if (currentState == DoorsState::CLOSED)
    {
        this->currentState = DoorsState::OPENING;
        this->OpeningTimer.start(2000);
    }
}

void Doors::EndOpeningTimerSlot()
{
    if (this->currentState == DoorsState::OPENING)
    {
        this->currentState = DoorsState::OPENED;
        this->WaitingTimer.start(2000);
    }
}

void Doors::EndClosingTimerSlot()
{
    if (this->currentState == DoorsState::CLOSING)
        this->currentState = DoorsState::CLOSED;
}

void Doors::EndWaitingTimerSlot()
{
    if (this->currentState == DoorsState::OPENED)
    {
        this->currentState = DoorsState::CLOSING;
        this->ClosingTimer.start(2000);
    }
}
