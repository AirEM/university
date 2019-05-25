#include "lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    this->currentState = LiftState::UNDEFINED_WAITING;

    this->MoveTimer.setSingleShot(true);

    connect(&MoveTimer, SIGNAL(timeout()), this, SLOT(EndMoveTimerSlot()));
}


void Lift::RiseSlot()
{
    this->currentState = LiftState::RISE;
    emit ChangeLiftStateSignal(this->currentState);
    this->MoveTimer.start(2000);

}

void Lift::DescendSlot()
{
    this->currentState = LiftState::DESCEND;
    emit ChangeLiftStateSignal(this->currentState);
    this->MoveTimer.start(2000);
}

void Lift::WaitSlot()
{
    this->currentState = LiftState::WAIT;
    emit ChangeLiftStateSignal(this->currentState);
}

void Lift::UndefinedWaitingSlot()
{
    this->currentState = LiftState::UNDEFINED_WAITING;
    emit ChangeLiftStateSignal(this->currentState);
}


void Lift::EndMoveTimerSlot()
{
    emit ChangeFloorSignal();
}
