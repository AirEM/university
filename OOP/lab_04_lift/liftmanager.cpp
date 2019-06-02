#include "liftmanager.h"

LiftManager::LiftManager(QObject *parent) : QObject(parent)
{
    this->lift = new Lift;
    this->doors = new Doors;

    this->currentFloor = 1;
    this->currentState = ManagerState::WAIT;

    // signals to Lift
    connect(this, SIGNAL(RiseSignal()), lift, SLOT(RiseSlot()));
    connect(this, SIGNAL(DescendSignal()), lift, SLOT(DescendSlot()));
    connect(this, SIGNAL(WaitSignal()), lift, SLOT(WaitSlot()));

    // signals from Lift
    connect(&(lift->UpTimer), SIGNAL(timeout()), this, SLOT(FloorUpSlot()));
    connect(&(lift->DownTimer), SIGNAL(timeout()), this, SLOT(FloorDownSlot()));

    // signal to Doors
    connect(this, SIGNAL(OpenDoorsSignal()), doors, SLOT(OpenDoorsSlot()));

    // signal from Doors
    connect(&(doors->ClosingTimer), SIGNAL(timeout()), this, SLOT(WaitDoorsSlot()));
}

LiftManager::~LiftManager()
{
    delete lift;
    delete doors;
}


void LiftManager::FloorUpSlot()
{
    currentFloor++;
    action();
}

void LiftManager::FloorDownSlot()
{
    currentFloor--;
    action();
}

void LiftManager::WaitDoorsSlot()
{
    if (currentState == ManagerState::WAIT_DOORS)
        action();
}

void LiftManager::WaitSlot(int floor)
{
    queue.enqueue(floor);

    if (currentState == ManagerState::WAIT)
    {
        if (currentFloor < floor)
        {
            this->currentState = ManagerState::UP;
            emit RiseSignal();
        }
        else if (currentFloor == floor)
        {
            wait();
        }
        else
        {
            this->currentState = ManagerState::DOWN;
            emit DescendSignal();
        }
    }
}


void LiftManager::action()
{
    if (queue.isEmpty() && currentState == ManagerState::WAIT_DOORS)
        currentState = ManagerState::WAIT;
    else
    {
        int floor = queue.last();

        if (currentFloor < floor)
            move_up();
        else if (currentFloor == floor)
            wait();
        else
            move_down();
        }
}


void LiftManager::wait()
{
    if (currentState == ManagerState::UP ||
            currentState == ManagerState::DOWN ||
            currentState == ManagerState::WAIT)
    {
        queue.dequeue();
        this->currentState = ManagerState::WAIT_DOORS;
        emit WaitSignal();
        emit OpenDoorsSignal();
    }
}

void LiftManager::move_up()
{
    if (currentState == ManagerState::UP ||
            currentState == ManagerState::WAIT ||
            currentState == ManagerState::WAIT_DOORS)
    {
        this->currentState = ManagerState::UP;
        emit RiseSignal();
    }
}

void LiftManager::move_down()
{
    if (currentState == ManagerState::DOWN ||
            currentState == ManagerState::WAIT ||
            currentState == ManagerState::WAIT_DOORS)
    {
        this->currentState = ManagerState::DOWN;
        emit DescendSignal();
    }
}


int LiftManager::get_floor() const
{
    return currentFloor;
}
