#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _facade(new Facade),
    _proxy(new Proxy)
{
    _ui->setupUi(this);

    _ui->horizontalLayout->addWidget(&_label);

    // Добавление освещения(в центр)
    int id = _proxy->CreateMainLight();
    _ui->lightComboBox->addItem(QString("Light_") + QString::number(id), QVariant(id));

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
    _facade->execute(&r_command);

    _label.update();
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    render();
}


void MainWindow::on_addFigurePushButton_clicked()
{
    int id = _proxy->CreateFigure();

    if (id != -1)
    {
        _ui->figureComboBox->addItem(QString("Figure_") + QString::number(id), QVariant(id));

        render();
    }
}

void MainWindow::on_delFigurePushButton_clicked()
{
    int id = _ui->figureComboBox->currentData().toInt();
    _ui->figureComboBox->removeItem(_ui->figureComboBox->currentIndex());

    command::DeleteFigureCommand command(id);
    _facade->execute(&command);

    render();
}


void MainWindow::on_addLightPushButton_clicked()
{
    int id = _proxy->CreateLight();

    if (id != -1)
    {
        _ui->lightComboBox->addItem(QString("Light_") + QString::number(id), QVariant(id));

        render();
    }
}

void MainWindow::on_dellLightPushButton_clicked()
{
    int id = _ui->lightComboBox->currentData().toInt();
    _ui->lightComboBox->removeItem(_ui->lightComboBox->currentIndex());

    command::DeleteLightCommand command(id);
    _facade->execute(&command);

    render();
}


void MainWindow::on_cleanPushButton_clicked()
{
    command::CleanCommand c_command;
    _facade->execute(&c_command);

    render();
}


void MainWindow::on_renderPushButton_clicked()
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
     *
     * Сейчас - правая тройка векторов: у - вверх, х - вправо, z - на нас(в пользователя)
     *
     * НУжно сделать либо:  ось Z в другою сторону(плохо, тройка векторов перестает быть правой)
     *                      ось X и Z развренуть (тройка векторов остается правой. но странная сс получается)
     *
     * Определить новое место для центра, сейчас оно в камере
     *
     */

    // Диффузный цвет(Метриал)
//    Material      ivory(Vector3d(0.6f,  0.3f, 0), Vector3d(0.4f, 0.4f, 0.3f),   50.);
//    Material red_rubber(Vector3d(0.9f,  0.1f, 0), Vector3d(0.3f, 0.1f, 0.1f),   10.);

//    Material      ivory_1(Vector3d(0.6f,  0.3f, 0), Vector3d(1.0f, 0.0f, 0.0f),   50.);
//    Material red_rubber_2(Vector3d(0.5f,  0.5f, 0), Vector3d(1, 1, 1),   100.);

    // Создание сферы
//    command::AddSphereCommand command(-3, 0, -16, 2, ivory);
//    _facede->execute(&command);

//    // Еще сферы
//    command::AddSphereCommand command_1(0, -4, -2, -12, 2, red_rubber_2);
//    _facade->execute(&command_1);

//    command::AddSphereCommand command_2(1.5, -0.5, -18, 3, red_rubber);
//    _facede->execute(&command_2);

//    command::AddSphereCommand command_3(-7,    5,   -18, 4, ivory);
//    _facede->execute(&command_3);


//    // Создание куба
//    Vector3d min_p(4, -4, -11);
//    Vector3d max_p(6, -2, -13);
//    command::AddCubeCommand command_cube(0, min_p, max_p, red_rubber);
//    _facade->execute(&command_cube);


//    // Создание конуса
//    Vector3d centre_cone(0, 0, -12);
//    command::AddConeCommand command_cone(0, centre_cone, 4, 2, red_rubber);
//    _facade->execute(&command_cone);


//    // Добавление освещения
//    command::AddLightCommand command_l(-20, 20,  20, 1.0, 0);
//    _facade->execute(&command_l);

//    command::AddLightCommand command_l1(30, 50, -25, 1.2f, 0);
//    _facade->execute(&command_l1);

//    command::AddLightCommand command_l2(30, 20,  30, 1.0, 0);
//    _facade->execute(&command_l2);



    // Отрисовка
    this->render();
}
