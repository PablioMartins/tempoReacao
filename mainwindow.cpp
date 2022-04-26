#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this,
            SIGNAL(teclaPress(QKeyEvent*)),
            ui->drawjogo,
            SLOT(keyPress(QKeyEvent*)));

    ui->drawjogo->drawinit();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    emit teclaPress(tecla);
}

