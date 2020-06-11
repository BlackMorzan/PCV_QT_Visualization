/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *devider;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *Charty;
    QGraphicsView *Chartz;
    QPushButton *ConnectpushButton;
    QPushButton *ChartChange;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(741, 332);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        devider = new QFrame(centralwidget);
        devider->setObjectName(QString::fromUtf8("devider"));
        devider->setFrameShape(QFrame::VLine);
        devider->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(devider, 0, 3, 4, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        Charty = new QGraphicsView(centralwidget);
        Charty->setObjectName(QString::fromUtf8("Charty"));

        gridLayout->addWidget(Charty, 1, 4, 1, 1);

        Chartz = new QGraphicsView(centralwidget);
        Chartz->setObjectName(QString::fromUtf8("Chartz"));

        gridLayout->addWidget(Chartz, 3, 4, 1, 1);

        ConnectpushButton = new QPushButton(centralwidget);
        ConnectpushButton->setObjectName(QString::fromUtf8("ConnectpushButton"));
        ConnectpushButton->setAutoDefault(false);
        ConnectpushButton->setFlat(false);

        gridLayout->addWidget(ConnectpushButton, 3, 1, 1, 1);

        ChartChange = new QPushButton(centralwidget);
        ChartChange->setObjectName(QString::fromUtf8("ChartChange"));

        gridLayout->addWidget(ChartChange, 0, 4, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 2, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        ConnectpushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ConnectpushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        ChartChange->setText(QCoreApplication::translate("MainWindow", "Zmiana wykres\303\263w", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
