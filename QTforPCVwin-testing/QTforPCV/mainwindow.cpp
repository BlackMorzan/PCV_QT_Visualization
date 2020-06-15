#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "globals.h"

QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<QList<QVector3D>>("QList<QVector3D>");

    //initialize the thread
    Connection_Menager  = new thr_Connection_Menager (this);

    connect( Connection_Menager , SIGNAL(emit_Vetors(QList<QVector3D>)),   this, SLOT(recive_vector(QList<QVector3D>)));
    connect( this , SIGNAL(chose_Vector(int)),   Connection_Menager, SLOT(decide_vector(int)));


    Connection_Menager->start();
}

void MainWindow::Chart(char axis, QtCharts::QChartView *ChartWindow)
{


    QLineSeries *series = new QLineSeries();
    int axis0;
    if (axis == 'X')
        axis0 = 0;
    else if (axis == 'Y')
        axis0 = 1;
    else if (axis == 'Z')
        axis0 = 2;
    else
    {
        qDebug() << "Unknown axis" << endl;
        return;
    }

    for (int i = 0; i < Pos.size(); ++i)
    {
        if (axis0 == 0)
            series->append(i, Pos.at(i).x());
        else if (axis0 == 1)
            series->append(i, Pos.at(i).y());
        else if (axis0 == 2)
            series->append(i, Pos.at(i).z());
    }

    // Create chart, add data, hide legend, and add axis
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Customize the title font
    QFont font;
    font.setPixelSize(12);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    QString Title = "Position ";
    chart->setTitle(Title + axis);

    // Change the line color and weight
    QPen pen(QRgb(0xff0000 >> (axis0*8)));
    pen.setWidth(2);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::NoAnimation);

    ChartWindow->setChart(chart);
}

/*!
 * \brief Dekonstrukor wywoływany przy wyjściu z programu
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete Connection_Menager;
}


void MainWindow::on_ChartChange_clicked()
{
    ChartMode = (ChartMode+1)%3;
    emit chose_Vector(ChartMode);
}

QVector3D MainWindow::GetLastLog()
{
    return Pos.last();
}

void MainWindow::recive_vector(QList<QVector3D> List)
{
    this->Pos = List;

    Chart('X', ui->Chartx);
    Chart('Y', ui->Charty);
    Chart('Z', ui->Chartz);
}

