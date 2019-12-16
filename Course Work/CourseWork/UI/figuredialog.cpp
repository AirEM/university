#include "figuredialog.h"
#include "ui_figuredialog.h"

#include <exception>

FigureDialog::FigureDialog(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::FigureDialog),
    _facade(new Facade)
{
    _ui->setupUi(this);
    _isCanseled = false;

}

FigureDialog::~FigureDialog()
{
    delete _ui;
}


void FigureDialog::setId(int id)
{
    _id = id;
}

bool FigureDialog::isCanseled()
{
    return _isCanseled;
}


void FigureDialog::on_addPushButton_clicked()
{
    // 0 - вкладка сферы
    if (_ui->figureTabWidget->currentIndex() == 0)
    {
        auto x = _ui->xSphereLineEdit->text().toFloat();
        auto y = _ui->ySphereLineEdit->text().toFloat();
        auto z = _ui->zSphereLineEdit->text().toFloat();

        auto R = _ui->radiusSphereLineEdit->text().toInt();

        auto r = _ui->redSphereLineEdit->text().toFloat() / 255.0f;
        auto g = _ui->greenSphereLineEdit->text().toFloat() / 255.0f;
        auto b = _ui->blueSphereLineEdit->text().toFloat() / 255.0f;

        // Vector3d(0.5f,  0.5f, 0)
        Material base_material(Vector3d(r, g, b), Vector3d(r, g, b),   50);

        command::AddSphereCommand command(_id, x, y, z, static_cast<size_t>(R), base_material);
        _facade->execute(&command);
    }
    else if (_ui->figureTabWidget->currentIndex() == 1) {

        auto x = _ui->xCubeLineEdit->text().toFloat();
        auto y = _ui->yCubeLineEdit->text().toFloat();
        auto z = _ui->zCubeLineEdit->text().toFloat();

        auto edge = _ui->edgeCubeLineEdit->text().toInt();

        auto r = _ui->redCubeLineEdit->text().toFloat() / 255.0f;
        auto g = _ui->greenCubeLineEdit->text().toFloat() / 255.0f;
        auto b = _ui->blueCubeLineEdit->text().toFloat() / 255.0f;

        Material base_material(Vector3d(0.5f,  0.5f, 0), Vector3d(r, g, b),   50);

        Vector3d min_p(x, y, z);
        Vector3d max_p(x + edge, y + edge, z - edge);

        command::AddCubeCommand command(_id, min_p, max_p, base_material);
        _facade->execute(&command);

    }
    else if (_ui->figureTabWidget->currentIndex() == 2)
    {
        auto x = _ui->xConeLineEdit->text().toFloat();
        auto y = _ui->yConeLineEdit->text().toFloat();
        auto z = _ui->zConeLineEdit->text().toFloat();

        auto radius = _ui->radiusConeLineEdit->text().toInt();

        auto height = _ui->heightConeLineEdit->text().toInt();

        auto r = _ui->redConeLineEdit->text().toFloat() / 255.0f;
        auto g = _ui->greenConeLineEdit->text().toFloat() / 255.0f;
        auto b = _ui->blueConeLineEdit->text().toFloat() / 255.0f;

        Material base_material(Vector3d(0.5f,  0.5f, 0), Vector3d(r, g, b),   0.3f);

        Vector3d centre_cone(x, y + height, z);

        command::AddConeCommand command(_id, centre_cone, height, radius, base_material);
        _facade->execute(&command);
    }

    this->close();
}

void FigureDialog::on_canselPushButton_clicked()
{
    this->_isCanseled = true;
    this->close();
}
