#ifndef FIGUREDIALOG_H
#define FIGUREDIALOG_H

#include <QDialog>

#include "Command/addspherecommand.h"
#include "Command/addcubecommand.h"
#include "Command/addconecommand.h"

#include "Facade/facade.h"

namespace Ui {
class FigureDialog;
}

using facade::Facade;

using command::AddSphereCommand;
using command::AddCubeCommand;
using command::AddConeCommand;

class FigureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FigureDialog(QWidget *parent = nullptr);
    ~FigureDialog();

    void setId(int);

private slots:
    void on_addPushButton_clicked();

private:
    Ui::FigureDialog *ui;

    int _id;

    std::shared_ptr<Facade> _facade;
};

#endif // FIGUREDIALOG_H
