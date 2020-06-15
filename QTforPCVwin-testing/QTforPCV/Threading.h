#include <QThread>
#include <qmath.h>
#include <QDebug>
#include <QVector3D>

#include "globals.h"
#include "CustomConn.h"


/*!
 * \brief Ta klasa ma za zadanie utrzymywac połączenie z aplikacją na innym wątku
 *
 * Aby nie blokować aplikacji komunikacja jest obsługiwana w całości na innym wątku, a lista
 * wartości potrzebynych do wyświetlenia jest przesyłana do \link MainWindow::recive_vector \endlink
 */

class thr_Connection_Menager : public QThread
{
    Q_OBJECT

public:
    /*!
     * \brief konstruktor dla nowego wątku
     */
    explicit thr_Connection_Menager(QObject *parent = 0, bool b = false);

    /*!
     * \brief Tu jest inicjowane połączenie, a później w pętli pobierane nowe wiadomości
     */
    void run();


    /*!
     * \brief Wartość do zatrzymania wątku
     */
    bool Stop;

    /*!
     * \brief Tworzenie klasy zarządzającej połączeniem
     */
    CustomConn ToPCV;

    /*!
     * \brief Wybiera jakie wartości (pozycja, prędkość, rotacja) są aktualnie przesyłane do wyświetlania
     */
    int current_vetor = 0;


    /*!
     * \brief Lista z wektorami 3D opisująca pozycję efektora
     */
    QList<QVector3D> PosMen;
    /*!
     * \brief Lista z wektorami 3D opisująca prędkość efektora
     */
    QList<QVector3D> VeloMen;
    /*!
     * \brief Lista z wektorami 3D opisująca rotację efektora
     */
    QList<QVector3D> RotMen;

signals:

    /*!
     * \brief wysyła wybraną listę wektorów do rysowania
     */
    void emit_Vetors(QList<QVector3D>);

public slots:

    /*!
     * \brief zmienia jaka lista wektorów 3D jest aktualnie przesyłana do wyświetlania
     */
    void decide_vector(int);

private:

    /*!
     * \brief Metoda dodaje nowe wartości do 3 list wektorów 3D
     *
     * \return zwraca 0 jeśli wiadomość została odebrana poprawnie, -1 kiedy pojawił się błąd
     */
    int NewLog();


};
