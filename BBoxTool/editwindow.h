#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QGraphicsPixmapItem>
#include <QRubberBand>
#include <QListWidgetItem>
#include <QStringList>
#include <QFile>
#include <QTextStream>

namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr, QString dir = "", QString cnFile = "");
    ~EditWindow();

private slots:
    bool eventFilter(QObject *target, QEvent *event);

    void on_btnReset_clicked();

    void on_btnNext_clicked();

    void on_lstFilesList_itemClicked(QListWidgetItem *item);
    void imageLoader(QString path);
    void drawrect(int x1, int y1, int x2, int y2);
    void create_and_read_annot_file(QString filePath);
    void on_btnPrev_clicked();
    void denormalize_and_dra_rectangle(QStringList coordLine);

    void on_btnDeleteBbox_clicked();

private:
    Ui::EditWindow *ui;
    QString selectedDir, classnameFile;
    QGraphicsScene *scene;
    QPoint s_origin;
    QPointF s_relativeOrigin;

    QPoint e_origin;
    QPointF e_relativeOrigin;
    cv::Mat image;
    cv::Rect imgRect;
    QGraphicsPixmapItem *disImage;
    QString imgPath, imgName, bbox_coordinate_string, bbox_rw_string;
    QStringList list, fileSplit, coordFromFile;
    QImage img;
    QListWidgetItem *bboxitem;
    QFile *bbox_file = nullptr, *classFile = nullptr, *tempFile = nullptr;
    QTextStream *stream = nullptr, *tempStream = nullptr;
};

#endif // EDITWINDOW_H
