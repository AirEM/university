#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _facede(new Facade)
{
    _ui->setupUi(this);


    _ui->horizontalLayout->addWidget(&_label);
}

MainWindow::~MainWindow()
{
    delete _ui;
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
    Material      ivory(Vector3d(0.6,  0.3, 0), Vector3d(0.4, 0.4, 0.3),   50.);
    Material red_rubber(Vector3d(0.9,  0.1, 0), Vector3d(0.3, 0.1, 0.1),   10.);

    // Создание сферы
    command::AddSphereCommand command(-3, 0, -16, 2, ivory);
    _facede->execute(&command);

    // Еще сферы
    command::AddSphereCommand command_1(4.0, -1, -12, 2, red_rubber);
    _facede->execute(&command_1);

    command::AddSphereCommand command_2(1.5, -0.5, -18, 3, red_rubber);
    _facede->execute(&command_2);

    command::AddSphereCommand command_3(-7,    5,   -18, 4, ivory);
    _facede->execute(&command_3);


    // Добавление освещения
    command::AddLightCommand command_l(-20, 20,  20, 1.0);
    _facede->execute(&command_l);

    command::AddLightCommand command_l1(30, 50, -25, 1.2);
    _facede->execute(&command_l1);

    command::AddLightCommand command_l2(30, 20,  30, 1.0);
    _facede->execute(&command_l2);


    // Отрисовка сферы
    // Отдельная функция
    auto pixmap = _label.getPixmap();

    QPainter painter(pixmap);
    pixmap->fill();

    auto drawer = new QtDrawer(&painter);
    std::shared_ptr<BaseDrawer> p_drawer(drawer);

    command::RenderCommand r_command(_label.width(), _label.height(), p_drawer);

    _facede->execute(&r_command);

    _label.update();




}

void MainWindow::on_savePushButton_clicked()
{
    QString QfileName;
    QByteArray byte_array;
    char *filename;
    int len;

//    error err = SUCCESS;

//    QfileName = QFileDialog::getSaveFileName(this, tr("Save File"),
//                                                    "", tr("Text Files (*.txt)"));
//    byte_array = QfileName.toLocal8Bit();

//    len = QfileName.length();
//    filename = new char[len + 1];

//    memcpy(filename, byte_array, static_cast<size_t>(len));
//    filename[len] = '\0';

//    struct save_data s_data;
//    s_data.filename = filename;

//    union u_data data;
//    data.s_data = &s_data;

//    action(SAVE, data);

//    delete []filename;

//    show_error(err);
}

void MainWindow::on_cleanPushButton_clicked()
{
    _label.clean();
}


void MainWindow::on_movePushButton_clicked()
{
//    error err = SUCCESS;

//    double dx = this->ui->dxLineEdit->text().toDouble();
//    double dy = this->ui->dyLineEdit->text().toDouble();
//    double dz = this->ui->dzLineEdit->text().toDouble();

//    struct move_data m_data;
//    m_data.dx = dx;
//    m_data.dy = dy;
//    m_data.dz = dz;

//    union u_data data;
//    data.m_data = &m_data;

//    err = action(MOVE, data);

//    label.draw();

//    show_error(err);
}

void MainWindow::on_scalingPushButton_clicked()
{
//    error err = SUCCESS;

//    double kx = this->ui->kxLineEdit->text().toDouble();
//    double ky = this->ui->kyLineEdit->text().toDouble();
//    double kz = this->ui->kzLineEdit->text().toDouble();

//    kx = kx == 0.0 ? 1 : kx;
//    ky = ky == 0.0 ? 1 : ky;
//    kz = kz == 0.0 ? 1 : kz;

//    struct scale_data sc_data;
//    sc_data.kx = kx;
//    sc_data.ky = ky;
//    sc_data.kz = kz;

//    union u_data data;
//    data.sc_data = &sc_data;

//    err = action(SCALE, data);

//    show_error(err);

//    label.draw();
}

void MainWindow::on_rotationPushButton_clicked()
{
//    error err = SUCCESS;

//    double fi_x = this->ui->fixLineEdit->text().toDouble();
//    double fi_y = this->ui->fiyLineEdit->text().toDouble();
//    double fi_z = this->ui->fizLineEdit->text().toDouble();

//    struct rotate_data r_data;
//    r_data.fi_x = fi_x;
//    r_data.fi_y = fi_y;
//    r_data.fi_z = fi_z;

//    union u_data data;
//    data.r_data = &r_data;

//    err = action(ROTATE, data);

//    show_error(err);

//    label.draw();
}

