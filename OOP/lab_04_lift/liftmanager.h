#ifndef LIFTMANAGER_H
#define LIFTMANAGER_H

#include <QObject>

#include "direction.h"
#include "doors.h"
#include "lift.h"

class LiftManager : public QObject
{
    Q_OBJECT
public:
    explicit LiftManager(QObject *parent = nullptr);

signals:
    // to Lift
    void RiseSignal(); // connected
    void DescendSignal(); // connected
    void WaitSignal(); // connected
    void UndefinedWaitingSignal(); // connected

    // to Doors
    void OpenDoorsSignal(); // connected

    // to GUI
    void ChandgeDirectionSignal(Direction); // connected
    void ChangeLiftStateSignal(LiftState); // connected
    void ChangeDoorsStateSignal(DoorsState); // connected
    void ChandgeFloorSignal(int); // connected

    // to this
    void NeedMoveSignal(); // connected


public slots:
    // from GUI
    void FloorSelectionSlot(int); // connected

    // from Lift
    void ChangeFloorSlot(); // connected
    void ChangeLiftStateSlot(LiftState); // connected

    // from Doors
    //void DoorsClosedSlot();
    void ChangeDoorsStateSlot(DoorsState); // cconnected

private slots:
    void NeedMoveSlot(); // connected


private:

    bool need_up(int);
    bool need_down(int);

    Lift* lift;
    Doors* doors;

    int currentFloor;
    Direction currentDirection;

    const static int numberFloors = 6;
    int existingFloors[numberFloors] = {0};
};

#endif // LIFTMANAGER_H
