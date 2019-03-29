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

    QString QfileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "", tr("Text Files (*.txt)"));
    QByteArray ba = QfileName.toLocal8Bit();

    int n = QfileName.length();
    char *filename = new char[n];

    memcpy(filename, ba, static_cast<size_t>(n));

    struct load_data l_data;
    l_data.filename = filename;

    union u_data data;
    data.l_data = &l_data;

    action(LOAD, data);

    delete []filename;

    label.draw();
}

void MainWindow::on_savePushButton_clicked()
{
    QString QfileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "", tr("Text Files (*.txt)"));
    QByteArray ba = QfileName.toLocal8Bit();

    int n = QfileName.length();
    char *filename = new char[n];

    memcpy(filename, ba, static_cast<size_t>(n));

    struct save_data s_data;
    s_data.filename = filename;

    union u_data data;
    data.s_data = &s_data;

    action(SAVE, data);

    delete []filename;
}

void MainWindow::on_cleanPushButton_clicked()
{
    label.clean();
}


void MainWindow::on_movePushButton_clicked()
{
    double dx = this->ui->dxLineEdit->text().toDouble();
    double dy = this->ui->dyLineEdit->text().toDouble();
    double dz = this->ui->dzLineEdit->text().toDouble();

    struct move_data m_data;
    m_data.dx = dx;
    m_data.dy = dy;
    m_data.dz = dz;

    union u_data data;
    data.m_data = &m_data;

    action(MOVE, data);

    label.draw();
}

void MainWindow::on_scalingPushButton_clicked()
{
    double kx = this->ui->kxLineEdit->text().toDouble();
    double ky = this->ui->kyLineEdit->text().toDouble();
    double kz = this->ui->kzLineEdit->text().toDouble();

    struct scale_data sc_data;
    sc_data.kx = kx;
    sc_data.ky = ky;
    sc_data.kz = kz;

    union u_data data;
    data.sc_data = &sc_data;

    action(SCALE, data);

    label.draw();
}

void MainWindow::on_rotationPushButton_clicked()
{
    double fix = this->ui->fixLineEdit->text().toDouble();
    double fiy = this->ui->fiyLineEdit->text().toDouble();
    double fiz = this->ui->fizLineEdit->text().toDouble();

    struct rotate_data r_data;
    r_data.fix = fix;
    r_data.fiy = fiy;
    r_data.fiz = fiz;

    union u_data data;
    data.r_data = &r_data;

    action(ROTATE, data);

    label.draw();
}
