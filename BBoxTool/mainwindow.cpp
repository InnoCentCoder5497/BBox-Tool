#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSelectDir_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
                                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    ui->lblDirectory->setText(dir);
}

void MainWindow::on_btnStart_clicked()
{
    editwindow = new EditWindow(this, this->dir, this->classnameFile);
    editwindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(editwindow, SIGNAL(destroyed()), this, SLOT(show()));

    editwindow->show();
    this->hide();
}

void MainWindow::on_btnSelectClassFile_clicked()
{
    classnameFile = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home");
    ui->lblClassNameFile->setText(classnameFile);
}
