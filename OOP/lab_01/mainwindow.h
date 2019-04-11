#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include<QMessageBox>

#include "renderarea.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_loadPushButton_clicked();

    void on_savePushButton_clicked();

    void on_cleanPushButton_clicked();

    void on_movePushButton_clicked();

    void on_scalingPushButton_clicked();

    void on_rotationPushButton_clicked();

    void show_error(error);

private:
    Ui::MainWindow *ui;
    MainLabel label;

};

#endif // MAINWINDOW_H
