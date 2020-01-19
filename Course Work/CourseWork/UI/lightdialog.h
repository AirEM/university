#ifndef LIGHTDIALOG_H
#define LIGHTDIALOG_H

#include <QDialog>

#include "Command/addlightcommand.h"

#include "Facade/facade.h"

namespace Ui {
class LightDialog;
}

using facade::Facade;

using command::AddLightCommand;

class LightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LightDialog(QWidget *parent = nullptr);
    ~LightDialog();

    void setId(int);
    bool isCanseled();

private slots:
    void on_addPushButton_clicked();

    void on_canselPushButton_clicked();

private:
    Ui::LightDialog *_ui;

    int _id;
    bool _isCanseled;

    std::shared_ptr<Facade> _facade;
};

#endif // LIGHTDIALOG_H
