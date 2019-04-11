#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->horizontalLayout->addWidget(&label);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadPushButton_clicked()
{
    QString QfileName;
    QByteArray byte_array;
    char *filename;
    int len;

    error err = SUCCESS;

    QfileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "", tr("Text Files (*.txt)"));

    byte_array = QfileName.toLocal8Bit();

    len = byte_array.length();
    filename = new char[len + 1];

    memcpy(filename, byte_array, len * sizeof(char));
    filename[len] = '\0';

    struct load_data l_data;
    l_data.filename = filename;

    union u_data data;
    data.l_data = &l_data;

    err = action(LOAD, data);

    delete []filename;

    if (err == SUCCESS)
        label.draw();
    else
        show_error(err);
}

void MainWindow::on_savePushButton_clicked()
{
    QString QfileName;
    QByteArray byte_array;
    char *filename;
    int len;

    error err = SUCCESS;

    QfileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "", tr("Text Files (*.txt)"));
    byte_array = QfileName.toLocal8Bit();

    len = QfileName.length();
    filename = new char[len + 1];

    memcpy(filename, byte_array, static_cast<size_t>(len));
    filename[len] = '\0';

    struct save_data s_data;
    s_data.filename = filename;

    union u_data data;
    data.s_data = &s_data;

    action(SAVE, data);

    delete []filename;

    show_error(err);
}

void MainWindow::on_cleanPushButton_clicked()
{
    label.clean();
}


void MainWindow::on_movePushButton_clicked()
{
    error err = SUCCESS;

    double dx = this->ui->dxLineEdit->text().toDouble();
    double dy = this->ui->dyLineEdit->text().toDouble();
    double dz = this->ui->dzLineEdit->text().toDouble();

    struct move_data m_data;
    m_data.dx = dx;
    m_data.dy = dy;
    m_data.dz = dz;

    union u_data data;
    data.m_data = &m_data;

    err = action(MOVE, data);

    label.draw();

    show_error(err);
}

void MainWindow::on_scalingPushButton_clicked()
{
    error err = SUCCESS;

    double kx = this->ui->kxLineEdit->text().toDouble();
    double ky = this->ui->kyLineEdit->text().toDouble();
    double kz = this->ui->kzLineEdit->text().toDouble();

    kx = kx == 0.0 ? 1 : kx;
    ky = ky == 0.0 ? 1 : ky;
    kz = kz == 0.0 ? 1 : kz;

    struct scale_data sc_data;
    sc_data.kx = kx;
    sc_data.ky = ky;
    sc_data.kz = kz;

    union u_data data;
    data.sc_data = &sc_data;

    err = action(SCALE, data);

    show_error(err);

    label.draw();
}

void MainWindow::on_rotationPushButton_clicked()
{
    error err = SUCCESS;

    double fi_x = this->ui->fixLineEdit->text().toDouble();
    double fi_y = this->ui->fiyLineEdit->text().toDouble();
    double fi_z = this->ui->fizLineEdit->text().toDouble();

    struct rotate_data r_data;
    r_data.fi_x = fi_x;
    r_data.fi_y = fi_y;
    r_data.fi_z = fi_z;

    union u_data data;
    data.r_data = &r_data;

    err = action(ROTATE, data);

    show_error(err);

    label.draw();
}


void MainWindow::show_error(error err)
{
    if (err != SUCCESS)
    {
        QMessageBox messageBox;
        QString mes = "Ошибка : ";

        switch (err)
        {
        case SUCCESS:
            break;
        case ERR_MODEL:
            mes +=  QString("Пустая модель");
            break;
        case ERR_FILE:
            mes += QString("Файл не открылся");
            break;
        case ERR_FILE_ACTION:
            mes += QString("Ошибка чтения/записи файла.");
            break;

        }
        messageBox.critical(nullptr, "Ошибка", mes);
    }
}
