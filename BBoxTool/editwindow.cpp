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
    if(!QDir(selectedDir + "/output").exists()){
        QDir().mkdir(selectedDir + "/output");
    }
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

            img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
            img = img.rgbSwapped();
            disImage = scene->addPixmap(QPixmap::fromImage(img));

            // TODO : add class options and image width height to make expected string
            bbox_coordinate_string ="(" + QString::number(s_relativeOrigin.rx()) +  "," + QString::number(s_relativeOrigin.ry()) + ")"
                    + "->" +
                    "(" + QString::number(e_relativeOrigin.rx()) +  "," + QString::number(e_relativeOrigin.ry()) + ")\n";
            bbox_file->write(bbox_coordinate_string.toLocal8Bit());
            bboxitem = new QListWidgetItem(bbox_coordinate_string);
            ui->lstBoundingBox->count();
            ui->lstBoundingBox->insertItem(ui->lstBoundingBox->count() + 1, bboxitem);
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
    ui->lstBoundingBox->clear();
    if(bbox_file != nullptr){
        bbox_file->close();
        bbox_file = nullptr;
    }
    imgPath = item->text();
    imgName = imgPath.split("/")[imgPath.split("/").size() - 1];
    imgName = imgName.split(".")[0];
    imageLoader(imgPath);
    if(!QFile::exists(selectedDir + "/output/" + imgName + ".txt")){
        bbox_file = new QFile(selectedDir + "/output/" + imgName + ".txt");
        if (!bbox_file->open(QIODevice::ReadWrite | QIODevice::Append)){
            qDebug() << "File not opening";
            return;
        }
    }
    else {
        bbox_file = new QFile(selectedDir + "/output/" + imgName + ".txt");
        if (!bbox_file->open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << "File not opening";
            return;
        }
        stream = new QTextStream(bbox_file);
        while (!stream->atEnd()) {
            QString line = stream->readLine();
            QRegExp separator("[(,)]");
            coordFromFile = line.split(separator);
            bboxitem = new QListWidgetItem(line);

            // TODO : Convert coordinate from normalized to original

            ui->lstBoundingBox->count();
            ui->lstBoundingBox->insertItem(ui->lstBoundingBox->count() + 1, bboxitem);\

            imgRect = cv::Rect(coordFromFile[1].toInt(), coordFromFile[2].toInt() ,
                               abs(coordFromFile[1].toInt() - coordFromFile[4].toInt()), abs(coordFromFile[2].toInt() - coordFromFile[5].toInt()));
            cv::rectangle(image, imgRect, cv::Scalar(0, 255, 0));

            img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
            img = img.rgbSwapped();
            disImage = scene->addPixmap(QPixmap::fromImage(img));
        }
    }
}

void EditWindow::imageLoader(QString path){
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    scene->clear();
    ui->statusbar->showMessage("Current File: " + path);
    image = cv::imread(path.toLocal8Bit().constData(), 1);

    img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    img = img.rgbSwapped();

    disImage = scene->addPixmap(QPixmap::fromImage(img));
    scene->addRect(disImage->boundingRect(), outlinePen);
    ui->gvMainImageView->setSceneRect(0, 0, img.width(), img.height());
    ui->gvMainImageView->update();
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
