#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>

#include "guimanager.h"

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
    // to GuiManager
    void FloorSelectionSignal(int); // connected

private slots:
    // from Button
    void FloorSelectionSlot(); // connected

    // from GuiManager
    void ChangeFloorSlot(int); // connected

    // states
    void ChangeLiftStateSlot(QString); // connected
    void ChangeDoorsStateSlot(QString); // connected

private:
    Ui::MainWindow *ui;

    QVector<QRadioButton*> radioButVector;

    GuiManager* guimanager;
};

#endif // MAINWINDOW_H
