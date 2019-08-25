#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _facede(new Facade)
{
    _ui->setupUi(this);

    _ui->horizontalLayout->addWidget(&_label);

    // Добавление освещения
    // ===============================================================================
    int id_int = IdMaker::getLightID();

    QVariant id(id_int);
    _ui->lightComboBox->addItem(QString("Light_") + QString::number(-id_int), id);

    command::AddLightCommand command(0, 20,  20, 1.0, id_int);
    _facede->execute(&command);
    // ===============================================================================
}

MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::render()
{
    auto pixmap = _label.getPixmap();

    pixmap->fill();
    QPainter painter(pixmap);

    auto drawer = new QtDrawer(&painter);
    std::shared_ptr<BaseDrawer> p_drawer(drawer);

    command::RenderCommand r_command(_label.width(), _label.height(), p_drawer);
    _facede->execute(&r_command);

    _label.update();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    render();
}


void MainWindow::on_loadPushButton_clicked()
{
    /*
     *
     *      TODO - Лист
     * X,Y как в декартевой системе координат
     * Z смотрит на нас(требуется сделать переход отрицательных координат к положительным)
     * Перевод в меньшие координаты 10(пользователь) -> 1.0(система)
     *
     */

    // Диффузный цвет(Метриал)
    Material      ivory(Vector3d(0.6f,  0.3f, 0), Vector3d(0.4f, 0.4f, 0.3f),   50.);
    Material red_rubber(Vector3d(0.9f,  0.1f, 0), Vector3d(0.3f, 0.1f, 0.1f),   10.);

    // Создание сферы
//    command::AddSphereCommand command(-3, 0, -16, 2, ivory);
//    _facede->execute(&command);

    // Еще сферы
    command::AddSphereCommand command_1(-4, -2, -12, 2, red_rubber);
    _facede->execute(&command_1);

//    command::AddSphereCommand command_2(1.5, -0.5, -18, 3, red_rubber);
//    _facede->execute(&command_2);

//    command::AddSphereCommand command_3(-7,    5,   -18, 4, ivory);
//    _facede->execute(&command_3);


    // Создание куба
    Vector3d min_p(4, -4, -11);
    Vector3d max_p(6, -2, -13);
    command::AddCubeCommand command_cube(min_p, max_p, red_rubber);
    _facede->execute(&command_cube);


    // Создание конуса
    Vector3d centre_cone(0, 0, -12);
    command::AddConeCommand command_cone(centre_cone, 4, 2, red_rubber);
    _facede->execute(&command_cone);


    // Добавление освещения
    command::AddLightCommand command_l(-20, 20,  20, 1.0, 0);
    _facede->execute(&command_l);

    command::AddLightCommand command_l1(30, 50, -25, 1.2f, 0);
    _facede->execute(&command_l1);

    command::AddLightCommand command_l2(30, 20,  30, 1.0, 0);
    _facede->execute(&command_l2);



    // Отрисовка
    this->render();
}

void MainWindow::on_cleanPushButton_clicked()
{
    command::CleanCommand c_command;
    _facede->execute(&c_command);

    render();
}


void MainWindow::on_addLightPushButton_clicked()
{
    // Получение паматров из GUI

    auto x = _ui->xLineEdit->text().toFloat();
    auto y = _ui->xLineEdit->text().toFloat();
    auto z = _ui->xLineEdit->text().toFloat();

    auto intesity = _ui->intLineEdit->text().toFloat();

    // Генерирование ID объекта
    int id = IdMaker::getLightID();

    // Добавление объекта в GUI
    _ui->lightComboBox->addItem(QString("Light_") + QString::number(-id), QVariant(id));

    command::AddLightCommand command(x, y,  z, intesity, id);
    _facede->execute(&command);

    render();
}


void MainWindow::on_dellLightPushButton_clicked()
{
    int id = _ui->lightComboBox->currentData().toInt();
    _ui->lightComboBox->removeItem(_ui->lightComboBox->currentIndex());

    command::DeleteLightCommand command(id);
    _facede->execute(&command);

    render();
}

void MainWindow::on_renderPushButton_clicked()
{
    render();
}
