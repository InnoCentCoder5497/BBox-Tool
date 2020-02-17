/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *lblDirectoryName;
    QLabel *label_2;
    QLabel *lblSelectedImageSize;
    QLabel *label_4;
    QListView *listAllFiles;
    QLabel *label_3;
    QLabel *lblCurrentSelection;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *gvMainImageView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrev;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnReset;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName(QString::fromUtf8("EditWindow"));
        EditWindow->resize(1074, 644);
        centralwidget = new QWidget(EditWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lblDirectoryName = new QLabel(centralwidget);
        lblDirectoryName->setObjectName(QString::fromUtf8("lblDirectoryName"));

        verticalLayout->addWidget(lblDirectoryName);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        lblSelectedImageSize = new QLabel(centralwidget);
        lblSelectedImageSize->setObjectName(QString::fromUtf8("lblSelectedImageSize"));

        verticalLayout->addWidget(lblSelectedImageSize);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        listAllFiles = new QListView(centralwidget);
        listAllFiles->setObjectName(QString::fromUtf8("listAllFiles"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listAllFiles->sizePolicy().hasHeightForWidth());
        listAllFiles->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(listAllFiles);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        lblCurrentSelection = new QLabel(centralwidget);
        lblCurrentSelection->setObjectName(QString::fromUtf8("lblCurrentSelection"));

        verticalLayout->addWidget(lblCurrentSelection);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gvMainImageView = new QGraphicsView(centralwidget);
        gvMainImageView->setObjectName(QString::fromUtf8("gvMainImageView"));
        gvMainImageView->setAutoFillBackground(false);
        gvMainImageView->setLineWidth(5);

        verticalLayout_2->addWidget(gvMainImageView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrev = new QPushButton(centralwidget);
        btnPrev->setObjectName(QString::fromUtf8("btnPrev"));

        horizontalLayout->addWidget(btnPrev);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        horizontalLayout->addWidget(btnReset);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));

        horizontalLayout->addWidget(btnNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        EditWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(EditWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EditWindow->setStatusBar(statusbar);

        retranslateUi(EditWindow);

        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("EditWindow", "Directory:", nullptr));
        lblDirectoryName->setText(QCoreApplication::translate("EditWindow", "Directory Name", nullptr));
        label_2->setText(QCoreApplication::translate("EditWindow", "Image Size", nullptr));
        lblSelectedImageSize->setText(QCoreApplication::translate("EditWindow", "Selected Image Size", nullptr));
        label_4->setText(QCoreApplication::translate("EditWindow", "File List", nullptr));
        label_3->setText(QCoreApplication::translate("EditWindow", "Current Selected File", nullptr));
        lblCurrentSelection->setText(QCoreApplication::translate("EditWindow", "Select File", nullptr));
        btnPrev->setText(QCoreApplication::translate("EditWindow", "<< Previous", nullptr));
        btnReset->setText(QCoreApplication::translate("EditWindow", "Reset Image", nullptr));
        btnNext->setText(QCoreApplication::translate("EditWindow", "Next >>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
