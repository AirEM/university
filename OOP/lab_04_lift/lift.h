#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTimer>

#include "liftstate.h"

class Lift : public QObject
{
    Q_OBJECT
public:
    QTimer DownTimer;
    QTimer UpTimer;

    explicit Lift(QObject *parent = nullptr);

public slots:
    // from LiftManager
    void RiseSlot(); // connected
    void DescendSlot(); // connected
    void WaitSlot(); // connected

private:
    LiftState currentState;
};

#endif // LIFT_H
