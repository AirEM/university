#ifndef LIFTMANAGER_H
#define LIFTMANAGER_H

#include <QObject>
#include <QQueue>

#include "managerstate.h"
#include "doors.h"
#include "lift.h"

class LiftManager : public QObject
{
    Q_OBJECT
public:
    explicit LiftManager(QObject *parent = nullptr);
    ~LiftManager();

    int get_floor() const;

    Lift* lift;
    Doors* doors;

signals:
    // to Lift
    void RiseSignal(); // connected
    void DescendSignal(); // connected
    void WaitSignal(); // connected

    // to Doors
    void OpenDoorsSignal(); // connected


public slots:
    void FloorUpSlot(); // connected
    void FloorDownSlot(); // connected
    void WaitDoorsSlot(); // connected
    void WaitSlot(int); // connected

private:

    void action();

    void wait();
    void move_up();
    void move_down();

    int currentFloor;
    ManagerState currentState;

    const static int numberFloors = 6;
    QQueue<int> queue;
};

#endif // LIFTMANAGER_H
