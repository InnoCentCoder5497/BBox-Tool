#include "editwindow.h"
#include "ui_editwindow.h"

#include <QDirIterator>
#include <QGraphicsScene>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QEvent>
#include <QDebug>


EditWindow::EditWindow(QWidget *parent, QString dir, QString shape) :
    QMainWindow(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
    ui->lblDirectoryName->setText(dir);
    ui->lblSelectedImageSize->setText(shape);

    this->selectedDir = dir;
    this->shape = shape.split(" ")[0].toInt();

    // Populate Directory list
    lstModel = new QStringListModel(this);
    QStringList list;
    QStringList file_extensions = {"*.jpg", "*.png", "*.jpeg" };
    QDirIterator it(this->selectedDir, file_extensions, QDir::Files);
    while (it.hasNext()) {
        list << it.next();
    }
    lstModel->setStringList(list);
    ui->listAllFiles->setModel(lstModel);

    // Load Scene on Graphics view
    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    ui->gvMainImageView->setScene(scene);
    ui->gvMainImageView->size().setWidth(this->shape);
    ui->gvMainImageView->size().setHeight(this->shape);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_listAllFiles_clicked(const QModelIndex &index)
{
    scene->clear();
    ui->gvMainImageView->update();

    cv::Mat image = cv::imread(index.data(Qt::DisplayRole).toString().toLocal8Bit().constData(), 1);

    ui->lblCurrentSelection->setText(index.data(Qt::DisplayRole).toString());
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    cv::resize(image, image, cv::Size(this->shape, this->shape));
    scene->addPixmap(QPixmap::fromImage(QImage(image.data,image.cols, image.rows, QImage::Format_RGB888)));
}
