#include "editwindow.h"
#include "ui_editwindow.h"

#include <QDirIterator>
#include <QEvent>
#include <QDebug>
#include <cstdlib>

EditWindow::EditWindow(QWidget *parent, QString dir, QString cnFile) :
    QMainWindow(parent),
    ui(new Ui::EditWindow)
{
    // Basic construction of mainwindow
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
    // initialize selected directory
    ui->lblDirectoryName->setText(dir);
    this->selectedDir = dir;
    this->classnameFile = cnFile;

    classFile = new QFile(this->classnameFile);
    if (!classFile->open(QIODevice::ReadOnly)){
        qDebug() << "File not opening";
    }
    QStringList cNames;
    stream = new QTextStream(classFile);
    while (!stream->atEnd()) {
        // get line
        QString line = stream->readLine();
        cNames.append(line);
    }
    classFile->close();
    ui->cbClassSelected->addItems(cNames);


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

    // Create output directory if not exists in current cirectory
    if(!QDir(selectedDir + "/output").exists()){
        QDir().mkdir(selectedDir + "/output");
    }

    tempFile = new QFile(selectedDir + "/output/temp.txt");
    if (!tempFile->open(QIODevice::ReadWrite | QIODevice::Append)){
        qDebug() << "File not opening";
    }
    tempStream = new QTextStream(tempFile);
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
        // get initial coordinates
        if (event->type() == QEvent::GraphicsSceneMousePress)
        {
            s_origin = ui->gvMainImageView->mapFromGlobal(QCursor::pos());
            s_relativeOrigin = ui->gvMainImageView->mapToScene(s_origin);
        }
        //get final coordinate and stuff
        else if (event->type() == QEvent::GraphicsSceneMouseRelease){
            e_origin = ui->gvMainImageView->mapFromGlobal(QCursor::pos());
            e_relativeOrigin = ui->gvMainImageView->mapToScene(e_origin);

            // Draw rectangle
            drawrect(s_relativeOrigin.rx(), s_relativeOrigin.ry(), e_relativeOrigin.rx(), e_relativeOrigin.ry());

            // get center point, width, height of bbox in normalized form
            float cx = ((s_relativeOrigin.rx() + e_relativeOrigin.rx()) / 2) / img.width();
            float cy = ((s_relativeOrigin.ry() + e_relativeOrigin.ry()) / 2) / img.height();
            float bw = (abs(e_relativeOrigin.rx() - s_relativeOrigin.rx())) / img.width();
            float bh = (abs(e_relativeOrigin.ry() - s_relativeOrigin.ry())) / img.height();

            // string to display on right list for bboxes
            bbox_coordinate_string ="(" + QString::number(s_relativeOrigin.rx()) +  "," + QString::number(s_relativeOrigin.ry()) + ")"
                    + "->" +
                    "(" + QString::number(e_relativeOrigin.rx()) +  "," + QString::number(e_relativeOrigin.ry()) + ")\n";
            // adding string to list
            bboxitem = new QListWidgetItem(bbox_coordinate_string);
            ui->lstBoundingBox->insertItem(ui->lstBoundingBox->count() + 1, bboxitem);

            // string to write to output file
            bbox_rw_string = QString::number(ui->cbClassSelected->currentIndex()) + " " + QString::number(cx) + " " + QString::number(cy) + " " + QString::number(bw) + " " + QString::number(bh) + "\n";
            // writing to file
            bbox_file->write(bbox_rw_string.toLocal8Bit());
            bbox_file->flush();
        }
    }
    return QMainWindow::eventFilter(target, event);
}

// Reset all bboxes
void EditWindow::on_btnReset_clicked()
{
    // reload image
    imgPath = ui->lstFilesList->currentItem()->text();
    bbox_file->resize(0);
    ui->lstBoundingBox->clear();
    imageLoader(imgPath);
}

// Get next image
void EditWindow::on_btnNext_clicked()
{
    ui->lstBoundingBox->clear();
    if(bbox_file != nullptr){
        bbox_file->close();
        bbox_file = nullptr;
    }
    int cRow = ui->lstFilesList->currentRow();
    if(cRow + 1 <= list.count() - 1){
        ui->lstFilesList->setCurrentRow(cRow + 1);
        imgPath = ui->lstFilesList->currentItem()->text();
        imgName = imgPath.split("/")[imgPath.split("/").size() - 1];
        imgName = imgName.split(".")[0];
        // load image
        imageLoader(imgPath);
        // create or read annot file
        create_and_read_annot_file(selectedDir + "/output/" + imgName + ".txt");
    }
}

// get previous image
void EditWindow::on_btnPrev_clicked()
{
    ui->lstBoundingBox->clear();
    if(bbox_file != nullptr){
        bbox_file->close();
        bbox_file = nullptr;
    }
    int cRow = ui->lstFilesList->currentRow();
    if(cRow - 1 > -1){
        ui->lstFilesList->setCurrentRow(cRow - 1);
        imgPath = ui->lstFilesList->currentItem()->text();
        imgName = imgPath.split("/")[imgPath.split("/").size() - 1];
        imgName = imgName.split(".")[0];
        // load image
        imageLoader(imgPath);
        // create or read annot file
        create_and_read_annot_file(selectedDir + "/output/" + imgName + ".txt");
    }
}

void EditWindow::denormalize_and_dra_rectangle(QStringList coordLine)
{
    // denormalize coordinates
    int x1 = (coordLine[1].toFloat() - coordLine[3].toFloat() / 2) * img.width();
    int y1 = (coordLine[2].toFloat() - coordLine[4].toFloat() / 2) * img.height();
    int x2 = (coordLine[1].toFloat() + coordLine[3].toFloat() / 2) * img.width();
    int y2 = (coordLine[2].toFloat() + coordLine[4].toFloat() / 2) * img.height();
    // display on bbox list
    bbox_coordinate_string = "(" + QString::number(x1) + "," + QString::number(x1) + ") -> (" + QString::number(x2) + "," + QString::number(y2) + ")";
    bboxitem = new QListWidgetItem(bbox_coordinate_string);
    ui->lstBoundingBox->insertItem(ui->lstBoundingBox->count() + 1, bboxitem);
    // draw rectangle
    drawrect(x1, y1, x2, y2);
}

// List item clicked
void EditWindow::on_lstFilesList_itemClicked(QListWidgetItem *item)
{
    // clear bbox list and close previous file
    ui->lstBoundingBox->clear();
    if(bbox_file != nullptr){
        bbox_file->close();
        bbox_file = nullptr;
    }
    // get image path and name
    imgPath = item->text();
    imgName = imgPath.split("/")[imgPath.split("/").size() - 1];
    imgName = imgName.split(".")[0];
    // load image
    imageLoader(imgPath);
    // create or read annot file
    create_and_read_annot_file(selectedDir + "/output/" + imgName + ".txt");
}

// all file handling
void EditWindow::create_and_read_annot_file(QString filePath)
{
    bbox_file = new QFile(filePath);
    if(!QFile::exists(filePath)){
        if (!bbox_file->open(QIODevice::ReadWrite | QIODevice::Append)){
            qDebug() << "File not opening";
            return;
        }
    }
    // file exist then load previous bbox and show them
    else {
        if (!bbox_file->open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << "File not opening";
            return;
        }
        // get text stream
        stream = new QTextStream(bbox_file);
        // iterate over file
        while (!stream->atEnd()) {
            // get line
            QString line = stream->readLine();
            coordFromFile = line.split(" ");
            denormalize_and_dra_rectangle(coordFromFile);
        }
    }
}

// Image loader
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

// Rectangle drawing
void EditWindow::drawrect(int x1, int y1, int x2, int y2)
{
    imgRect = cv::Rect(x1, y1, abs(x1 - x2), abs(y1 - y2));
    cv::rectangle(image, imgRect, cv::Scalar(0, 255, 0));

    img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    img = img.rgbSwapped();
    disImage = scene->addPixmap(QPixmap::fromImage(img));
}

void EditWindow::on_btnDeleteBbox_clicked()
{
    stream->seek(0);
    int linenumber = 0;
    // iterate over file
    while (!stream->atEnd()) {
        QString line = stream->readLine();
        if(linenumber != ui->lstBoundingBox->currentRow()){
            line = line + "\n";
            tempFile->write(line.toLocal8Bit());
            tempFile->flush();
        }
        linenumber++;
    }
    bbox_file->resize(0);
    tempStream->seek(0);
    while (!tempStream->atEnd()) {
        QString line = tempStream->readLine();
        line = line + "\n";
        bbox_file->write(line.toLocal8Bit());
        bbox_file->flush();
    }
    tempFile->resize(0);
    ui->lstBoundingBox->clear();

    stream->seek(0);
    imageLoader(imgPath);
    while (!stream->atEnd()) {
        // get line
        QString line = stream->readLine();
        coordFromFile = line.split(" ");
        denormalize_and_dra_rectangle(coordFromFile);
    }
}
