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
    connect( ui->ConnectpushButton, SIGNAL(clicked()), this, SLOT(on_pushButtonConnect_pressed()));


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

MainWindow::~MainWindow()
{
    delete ui;
}

const char *MainWindow::BoolToString(bool b)
{
      return b ? "true" : "false";
}


void MainWindow::on_ChartChange_clicked()
{
    ChartMode = (ChartMode+1)%3;
    emit chose_Vector(ChartMode);
    //Glob.SetRotation(QVector3D(ChartMode*45, 0, 0));
}

void MainWindow::on_pushButtonConnect_pressed()
{

    QString message = QString(BoolToString(connection));

    if (connection == true)
        connection = false;
    else
        connection = true;
}


// co za potwór... UGH!!!
void MainWindow::addToLogs(QString message)
{
    QString x = message;
    /*
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    QString CurrentDouble = "x";
    QString CurrentMessage = "x";

    QString x = message;

    ///// Inside Threading
    if (ToPCV.ReciveFullMessage()<0)
    {
        this->close();
        return;
    }

    for (int i=0;i<ToPCV.lenght;i++)
    {
        CurrentDouble = QString::number(ToPCV.GetDouble(i));
        CurrentMessage = QString::number(ToPCV.messageCnt);

        ui->Log->append(currentDateTime + "\t" + CurrentDouble + "\t" + CurrentMessage);
    }

    //bierz pierwsze 3 liczby z danego połączenia, wpisz do wektora i zapamiętaj w Pos (część Klasy mainwindow)
    Pos << QVector3D(ToPCV.GetDouble(0),ToPCV.GetDouble(1),ToPCV.GetDouble(2));

    Chart('X', ui->Chartx);
    Chart('Y', ui->Charty);
    Chart('Z', ui->Chartz);
*/}

QVector3D MainWindow::GetLatLog()
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

