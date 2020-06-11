#include <QThread>
#include <qmath.h>
#include <QDebug>
#include <QVector3D>

#include "globals.h"
#include "CustomConn.h"

class thr_Connection_Menager : public QThread
{
    Q_OBJECT

public:
    explicit thr_Connection_Menager(QObject *parent = 0, bool b = false);
    void run();

    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
    bool Stop;

    CustomConn ToPCV;

    QList<QVector3D> PosMen;
    QList<QVector3D> VeloMen;
    QList<QVector3D> AccMen;

    int current_vetor = 0;

signals:
    // To communicate with Gui Thread
    // we need to emit a signal
    void have_calculatedVal(float, float);
    void emit_Vetors(QList<QVector3D>);

public slots:
    void decide_vector(int);

private:

    void NewLog();


};
