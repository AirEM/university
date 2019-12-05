#ifndef FIGUREDIALOG_H
#define FIGUREDIALOG_H

#include <QDialog>

#include "Command/addspherecommand.h"
#include "Command/addcubecommand.h"
#include "Command/addconecommand.h"

#include "Facade/facade.h"

#include "Object/Material/material.h"

namespace Ui {
class FigureDialog;
}

using command::AddSphereCommand;
using command::AddCubeCommand;
using command::AddConeCommand;

using facade::Facade;

using object::Material;
using geometry::Vector3d;

class FigureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FigureDialog(QWidget *parent = nullptr);
    ~FigureDialog();

    void setId(int);

    bool isCanseled();

private slots:
    void on_addPushButton_clicked();

    void on_canselPushButton_clicked();

private:
    Ui::FigureDialog *_ui;

    int _id;

    bool _isCanseled;

    std::shared_ptr<Facade> _facade;
};

#endif // FIGUREDIALOG_H
