#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QGraphicsScene>

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

private:
    Ui::EditWindow *ui;
    QString selectedDir;
    QStringListModel *lstModel;
    QGraphicsScene *scene;
    int shape;
};

#endif // EDITWINDOW_H
