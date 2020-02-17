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
#include <QMouseEvent>
#include <QRectF>
#include <QGraphicsRectItem>
#include <cstdlib>
#include <QListWidgetItem>


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

    QStringList file_extensions = {"*.jpg", "*.png", "*.jpeg" };
    QDirIterator it(this->selectedDir, file_extensions, QDir::Files);
    while (it.hasNext()) {
        list << it.next();
    }
    ui->lstFilesList->addItems(list);

    // Load Scene on Graphics view
    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    ui->gvMainImageView->setScene(scene);
    ui->gvMainImageView->setDragMode(QGraphicsView::RubberBandDrag);

    // Variables
}

EditWindow::~EditWindow()
{
    delete ui;
}

bool EditWindow::eventFilter(QObject *target, QEvent *event)
{
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(5);

    if (target == scene)
    {
        if (event->type() == QEvent::GraphicsSceneMousePress)
        {
            s_origin = ui->gvMainImageView->mapFromGlobal(QCursor::pos());
            s_relativeOrigin = ui->gvMainImageView->mapToScene(s_origin);
        }
        else if (event->type() == QEvent::GraphicsSceneMouseMove){
            e_origin = ui->gvMainImageView->mapFromGlobal(QCursor::pos());
            e_relativeOrigin = ui->gvMainImageView->mapToScene(e_origin);
        }
        else if (event->type() == QEvent::GraphicsSceneMouseRelease){
            imgRect = cv::Rect(s_relativeOrigin.rx(), s_relativeOrigin.ry() ,
                               abs(s_relativeOrigin.rx() - e_relativeOrigin.rx()), abs(s_relativeOrigin.ry() - e_relativeOrigin.ry()));
            cv::rectangle(image, imgRect, cv::Scalar(0, 255, 0));

            disImage->setPixmap(QPixmap::fromImage(QImage(image.data, image.cols, image.rows, QImage::Format_RGB888)));

        }
    }
    return QMainWindow::eventFilter(target, event);
}


void EditWindow::on_btnReset_clicked()
{
    imgPath = ui->lstFilesList->currentItem()->text();
    imageLoader(imgPath);
}

void EditWindow::on_btnNext_clicked()
{
    int cRow = ui->lstFilesList->currentRow();
    if(cRow + 1 <= list.count() - 1){
        ui->lstFilesList->setCurrentRow(cRow + 1);
        imgPath = ui->lstFilesList->currentItem()->text();
        imageLoader(imgPath);
    }
}

void EditWindow::on_lstFilesList_itemClicked(QListWidgetItem *item)
{
    imgPath = item->text();
    imageLoader(imgPath);
}

void EditWindow::imageLoader(QString path){
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    scene->clear();
    ui->gvMainImageView->update();
    ui->statusbar->showMessage("Current File: " + path);
    image = cv::imread(path.toLocal8Bit().constData(), 1);
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    cv::resize(image, image, cv::Size(this->shape, this->shape));
    disImage = scene->addPixmap(QPixmap::fromImage(QImage(image.data,image.cols, image.rows, QImage::Format_RGB888)));
    scene->addRect(disImage->boundingRect(), outlinePen);
}

void EditWindow::on_btnPrev_clicked()
{
    int cRow = ui->lstFilesList->currentRow();
    if(cRow - 1 > -1){
        ui->lstFilesList->setCurrentRow(cRow - 1);
        imgPath = ui->lstFilesList->currentItem()->text();
        imageLoader(imgPath);
    }
}
