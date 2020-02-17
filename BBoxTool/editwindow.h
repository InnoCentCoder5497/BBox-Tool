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

namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr, QString dir = "", QString shape = "256 x 256");
    ~EditWindow();

private slots:
    void on_listAllFiles_clicked(const QModelIndex &index);
    bool eventFilter(QObject *target, QEvent *event);

    void on_btnReset_clicked();

    void on_btnNext_clicked();

private:
    Ui::EditWindow *ui;
    QString selectedDir;
    QStringListModel *lstModel;
    QGraphicsScene *scene;
    int shape;
    QPoint s_origin;
    QPointF s_relativeOrigin;

    QPoint e_origin;
    QPointF e_relativeOrigin;
    cv::Mat image;
    cv::Rect imgRect;
    QGraphicsPixmapItem *disImage;
    QRubberBand *rubberBand = nullptr;
};

#endif // EDITWINDOW_H
