#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QString>
#include <QLineSeries>
#include <QVector3D>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAbstractAxis>

#include "CustomConn.h"
#include "Threading.h"
#include "Viewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    inline const char * BoolToString(bool b);

signals:

    void chose_Vector(int);



private slots:

    /////////////////////////////////////////////////
    void on_pushButtonConnect_pressed();

    void on_ChartChange_clicked();

    void addToLogs(QString message);

    QVector3D GetLatLog();

private:

    thr_Connection_Menager *Connection_Menager ;

    void Chart(char axis, QtCharts::QChartView *ChartWindow);

    QList<QVector3D> Pos;

    Ui::MainWindow *ui;

    bool connection = false;

    int ChartMode = 0;

    CustomConn ToPCV;

public slots:

    void recive_vector(QList<QVector3D> List);
};
#endif // MAINWINDOW_H
