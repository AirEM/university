#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>

#include "liftmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    // to LiftManager
    void FloorSelectionSignal(int); // connected

private slots:
    // from Button
    void FloorSelectionSlot(); // connected

    // from LiftManager
    void ChandgeDirectionSlot(Direction); // connected
    void ChangeLiftStateSlot(LiftState); // connected
    void ChangeDoorsStateSlot(DoorsState); // connected
    void ChangeFloorSlot(int); // connected

public slots:

private:
    Ui::MainWindow *ui;

    QVector<QRadioButton*> radioButVector;

    LiftManager* liftmanager;
};

#endif // MAINWINDOW_H
