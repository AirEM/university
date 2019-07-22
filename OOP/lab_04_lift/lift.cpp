#include "lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    this->currentState = LiftState::WAIT;

    this->UpTimer.setSingleShot(true);
    this->DownTimer.setSingleShot(true);
}


void Lift::RiseSlot()
{
    if (currentState == LiftState::WAIT ||
            currentState == LiftState::RISE)
    {
        this->currentState = LiftState::RISE;
        this->UpTimer.start(2000);
    }

}

void Lift::DescendSlot()
{
    if (currentState == LiftState::WAIT ||
            currentState == LiftState::DESCEND)
    {
        this->currentState = LiftState::DESCEND;
        this->DownTimer.start(2000);
    }
}

void Lift::WaitSlot()
{
    this->currentState = LiftState::WAIT;
}
