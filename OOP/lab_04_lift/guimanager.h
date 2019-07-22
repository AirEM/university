#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <QObject>

#include "liftmanager.h"

class GuiManager : public QObject
{
    Q_OBJECT
public:
    GuiManager();
    ~GuiManager();

signals:
    // to LiftManager
    void FloorSelectionSignal(int); // connected

    // to GUI
    void ChangeFloorSignal(int); // connected
    void ChangeLiftStateSiglal(QString); // connected
    void ChangeDoorsStateSiglal(QString); // connected

private slots:
    // from Gui
    void FloorSelectionSlot(int); // connected

    void ChangeFloorSlot(); // connected

    // from Lift
    void RiseSlot(); // connected
    void DescendSlot(); // connected
    void WaitSlot(); // connected

//    // from Doors
    void OpeningSlot(); // openeing connected
    void OpenedSlot();  // opened connected
    void ClosingSlot(); // closing connected
    void ClosedSlot();  // closed connected

private:
    LiftManager* liftmanager;

};

#endif // GUIMANAGER_H
