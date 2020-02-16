#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList imgShapes = {"256 x 256", "512 x 512", "416 x 416", "227 x 227"};
    for(auto& i : imgShapes){
        ui->cbImageSizeSelector->addItem(i);
    }
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

}
