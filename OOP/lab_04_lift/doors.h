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

signals:
    void ChangeDoorsStateSignal(DoorsState); // connected

public slots:
    void OpenDoorsSlot(); // connected

private slots:
    void EndMovingTimerSlot(); // connected
    void EndWaitingTimerSlot(); // connected

private:
    DoorsState currentState;

    QTimer MovingTimer;
    QTimer WaitingTimer;
};

#endif // DOORS_H
