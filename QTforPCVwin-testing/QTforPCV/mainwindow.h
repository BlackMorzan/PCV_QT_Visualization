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


/*!
 * \brief Jest to główna klasa obsługująca komunikację między UI, a resztą programu
 *
 * Klasa zawiera metody związane z UI, jak obsługa przycisków, przesyłanie watrości do wyświetlania na wykresach
 * i rozpoczyna nowy wątek
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Główna metaoda programu
     *
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:

    /*!
     * \brief Wsakźnik na nowy wątek
     *
     */
    thr_Connection_Menager *Connection_Menager;

    /*!
     * \brief Aktualnie przechowywana lista Wektorów 3D do wyświetlenia na wykresach
     */
    QList<QVector3D> Pos;

    /*!
     * \brief UI aplikacji
     */
    Ui::MainWindow *ui;

    /*!
     * \brief informacjia, czy istenieje połączenie z aplikacją
     */
    bool connection = false;

    /*!
     * \brief aktualnie wybrany tryb wyświetlania wykresów
     */
    int ChartMode = 0;

    void Chart(char axis, QtCharts::QChartView *ChartWindow);


signals:
    /*!
     * \brief Sygnał. Wysyłana zmienna inforuje jaka lista wektorów 3D poinna być wysyłana
     */
    void chose_Vector(int);


private slots:

    /*!
     * \brief Slot. Zmienia serię wykresów
     *
     * Po wciśnięciu przycisku UI "zmiana wykresów" wysłany zostaje sygnał \link chose_Vector \endlink na wątek kontrolowany
     * przez \link thr_Connection_Menager \endlink, który zmieni jaka lista wektorów 3D
     * zostanie wysłana (pozycja, przędkość, rotacja)
     */

    void on_ChartChange_clicked();

    /*!
     * \brief Slot. Pobierany jest ostatni wektor 3D, który pojawił sie na liście.
     *
     * \return Zwraca Wektor 3D, który został ostani załadowany na listę.
     */
    QVector3D GetLastLog();

    /*!
     * \brief Slot. Wywołuje funke wyświetlające wykresy
     *
     * Lista zostaje przypisana jako paramter klasy i wywoływane zostają fukcje rysujące wykres.
     *
     * \param List jest to lista Wektorów 3D z których stworzone zostaną wykresy.
     */
    void recive_vector(QList<QVector3D> List);
};



#endif // MAINWINDOW_H
