/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *lblDirectory;
    QPushButton *btnSelectDir;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *cbImageSizeSelector;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(794, 412);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        lblDirectory = new QLabel(centralwidget);
        lblDirectory->setObjectName(QString::fromUtf8("lblDirectory"));

        verticalLayout->addWidget(lblDirectory);


        horizontalLayout->addLayout(verticalLayout);

        btnSelectDir = new QPushButton(centralwidget);
        btnSelectDir->setObjectName(QString::fromUtf8("btnSelectDir"));

        horizontalLayout->addWidget(btnSelectDir);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        cbImageSizeSelector = new QComboBox(centralwidget);
        cbImageSizeSelector->setObjectName(QString::fromUtf8("cbImageSizeSelector"));

        horizontalLayout_2->addWidget(cbImageSizeSelector);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout_3->addWidget(btnStart);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "BBox Tool for YOLO", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Selected Directory", nullptr));
        lblDirectory->setText(QCoreApplication::translate("MainWindow", "Directory", nullptr));
        btnSelectDir->setText(QCoreApplication::translate("MainWindow", "Select Directory", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Image Shape :", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
