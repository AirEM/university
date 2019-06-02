#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

#include "doorsstate.h"

class Doors : public QObject
{
    Q_OBJECT
public:
    explicit Doors(QObject *parent = nullptr);

    QTimer OpeningTimer;
    QTimer ClosingTimer;
    QTimer WaitingTimer;

public slots:
    // from LiftManager
    void OpenDoorsSlot(); // connected

private slots:
    // from LiftTimers
    void EndOpeningTimerSlot(); // connected
    void EndClosingTimerSlot(); // connected
    void EndWaitingTimerSlot(); // connected

private:
    DoorsState currentState;
};

#endif // DOORS_H
