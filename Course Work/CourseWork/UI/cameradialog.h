#ifndef CAMERADIALOG_H
#define CAMERADIALOG_H

#include "Command/movecameracommand.h"
#include "Command/rotatecameracommand.h"

#include "Facade/facade.h"

#include <QDialog>

namespace Ui {
class CameraDialog;
}

using command::MoveCameraCommand;
using command::RotateCameraCommand;

using facade::Facade;


class CameraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraDialog(QWidget *parent = nullptr);
    ~CameraDialog();

private slots:
    void on_canselPushButton_clicked();

    void on_changePushButton_clicked();

private:
    Ui::CameraDialog *_ui;

    std::shared_ptr<Facade> _facade;
};

#endif // CAMERADIALOG_H
