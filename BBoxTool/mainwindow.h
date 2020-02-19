#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    EditWindow *editwindow;

private slots:
    void on_btnSelectDir_clicked();

    void on_btnStart_clicked();

    void on_btnSelectClassFile_clicked();

private:
    Ui::MainWindow *ui;
    QString dir, classnameFile;
};
#endif // MAINWINDOW_H
