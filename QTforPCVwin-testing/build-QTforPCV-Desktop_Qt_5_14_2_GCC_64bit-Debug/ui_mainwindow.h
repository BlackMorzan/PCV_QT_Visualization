/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *ChartChange;
    QtCharts::QChartView *Chartz;
    QtCharts::QChartView *Charty;
    QtCharts::QChartView *Chartx;
    QFrame *devider;
    QPushButton *ConnectpushButton;
    QTextBrowser *Log;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 332);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ChartChange = new QPushButton(centralwidget);
        ChartChange->setObjectName(QString::fromUtf8("ChartChange"));

        gridLayout->addWidget(ChartChange, 0, 6, 1, 1);

        Chartz = new QtCharts::QChartView(centralwidget);
        Chartz->setObjectName(QString::fromUtf8("Chartz"));

        gridLayout->addWidget(Chartz, 3, 6, 1, 1);

        Charty = new QtCharts::QChartView(centralwidget);
        Charty->setObjectName(QString::fromUtf8("Charty"));

        gridLayout->addWidget(Charty, 2, 6, 1, 1);

        Chartx = new QtCharts::QChartView(centralwidget);
        Chartx->setObjectName(QString::fromUtf8("Chartx"));

        gridLayout->addWidget(Chartx, 1, 6, 1, 1);

        devider = new QFrame(centralwidget);
        devider->setObjectName(QString::fromUtf8("devider"));
        devider->setFrameShape(QFrame::VLine);
        devider->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(devider, 0, 5, 4, 1);

        ConnectpushButton = new QPushButton(centralwidget);
        ConnectpushButton->setObjectName(QString::fromUtf8("ConnectpushButton"));
        ConnectpushButton->setAutoDefault(false);
        ConnectpushButton->setFlat(false);

        gridLayout->addWidget(ConnectpushButton, 3, 0, 1, 1);

        Log = new QTextBrowser(centralwidget);
        Log->setObjectName(QString::fromUtf8("Log"));

        gridLayout->addWidget(Log, 1, 1, 3, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        ConnectpushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ChartChange->setText(QCoreApplication::translate("MainWindow", "Zmiana wykres\303\263w", nullptr));
        ConnectpushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
