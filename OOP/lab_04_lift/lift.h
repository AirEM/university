#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTimer>

#include "liftstate.h"

class Lift : public QObject
{
    Q_OBJECT
public:
    explicit Lift(QObject *parent = nullptr);

signals:
    // to LiftManager
    void ChangeFloorSignal(); // connected
    void ChangeLiftStateSignal(LiftState); // connected

public slots:
    // from LiftManager
    void RiseSlot(); // connected
    void DescendSlot(); // connected
    void WaitSlot(); // connected
    void UndefinedWaitingSlot(); // connected

private slots:
    // from Timer
    void EndMoveTimerSlot(); // connected;

private:
    LiftState currentState;

    QTimer MoveTimer;
};

#endif // LIFT_H
