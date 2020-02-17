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
    bool eventFilter(QObject *target, QEvent *event);

    void on_btnReset_clicked();

    void on_btnNext_clicked();

    void on_lstFilesList_itemClicked(QListWidgetItem *item);
    void imageLoader(QString path);

    void on_btnPrev_clicked();

private:
    Ui::EditWindow *ui;
    QString selectedDir;
    QGraphicsScene *scene;
    int shape;
    QPoint s_origin;
    QPointF s_relativeOrigin;

    QPoint e_origin;
    QPointF e_relativeOrigin;
    cv::Mat image;
    cv::Rect imgRect;
    QGraphicsPixmapItem *disImage;
    QString imgPath;
    QStringList list;
};

#endif // EDITWINDOW_H
