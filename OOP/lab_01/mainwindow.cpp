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

void MainWindow::on_scalingPushButton_clicked()
{
    label.draw();
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

void MainWindow::on_cleanPushButton_clicked()
{
    label.clean();
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
