#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include<QMessageBox>

#include "renderarea.h"

#include "Facade/facade.h"

#include "Drawer/basedrawer.h"
#include "Drawer/qtdrawer.h"

#include "Object/Material/material.h"

#include "Command/addspherecommand.h"
#include "Command/addcubecommand.h"
#include "Command/addconecommand.h"
#include "Command/addlightcommand.h"

#include "Command/deletefigurecommand.h"
#include "Command/deletelightcommand.h"

#include "Command/cleancommand.h"
#include "Command/rendercommand.h"

#include "Command/movecameracommand.h"
#include "Command/rotatecameracommand.h"

#include "Proxy/proxy.h"


namespace Ui {
class MainWindow;
}

using facade::Facade;

using drawer::BaseDrawer;
using drawer::QtDrawer;

using object::Material;

using proxy::Proxy;
using geometry::Vector3d;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    //void on_loadPushButton_clicked();

    void on_cleanPushButton_clicked();

    void on_addLightPushButton_clicked();

    void on_dellLightPushButton_clicked();

    //void on_renderPushButton_clicked();

    void on_addFigurePushButton_clicked();

    void on_delFigurePushButton_clicked();

    void on_upPushButton_clicked();

    void on_downPushButton_clicked();

    void on_rightPushButton_clicked();

    void on_leftPushButton_clicked();

    void on_nearerPushButton_clicked();

    void on_furtherPushButton_clicked();

    void on_forwardPushButton_clicked();

    void on_backPushButton_clicked();

    void on_rotationLeftPushButton_clicked();

    void on_rotationRightPushButton_clicked();

    void on_cameraParamPushButton_clicked();

private:
    Ui::MainWindow *_ui;
    MainLabel _label;

    std::shared_ptr<Facade> _facade;
    std::shared_ptr<Proxy> _proxy;

    void resizeEvent(QResizeEvent *event) override;

    void render();

};

#endif // MAINWINDOW_H
