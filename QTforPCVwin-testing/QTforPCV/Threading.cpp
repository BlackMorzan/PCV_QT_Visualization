#include "Threading.h"

thr_Connection_Menager ::thr_Connection_Menager (QObject *parent, bool b) :
    QThread(parent), Stop(b)
{}

// run() will be called when this thread start
void thr_Connection_Menager ::run()
{
    //Glob.SetAngleX_deg(QVector3D());

    if (ToPCV.Init()<0)
    {
        //this->closes();
        // OPEN NEW WINDOW ????????/////////////////////////?????
        qDebug() << "Thread connectrion failed" << endl;
        return;
    }

    while(true)
    {
        /// Write from CustomConn to VectorList
        NewLog();
        if (current_vetor == 0)
            emit emit_Vetors(PosMen);
        else if (current_vetor == 1)
            emit emit_Vetors(VeloMen);
        else if (current_vetor == 2)
            emit emit_Vetors(AccMen);
        else
            qDebug() << "Something went wrong - unknown Vector to send" << endl;

        Glob.SetRotation(AccMen.last());
        //qDebug() << "Setting last: " << AccMen.last();
        //qDebug() << "Setting first: " << AccMen.first();
        this->msleep(3);
    }
}

void thr_Connection_Menager::decide_vector(int tmp)
{
    current_vetor = tmp;
    qDebug() << "Chage Charts Thead: " << current_vetor;

}


void thr_Connection_Menager::NewLog()
{
    if (ToPCV.ReciveFullMessage()<0)
    {
        qDebug() << "Message not Recived - ConnMenager" << endl;
        return;
    }

    //bierz pierwsze 3 liczby z danego połączenia, wpisz do wektora i zapamiętaj w Pos (część Klasy mainwindow)
    //Glob.SetRotation(QVector3D(ToPCV.GetDouble(0),ToPCV.GetDouble(1),ToPCV.GetDouble(2)));
    //Glob.SetRotation(QVector3D(ToPCV.GetDouble(6),ToPCV.GetDouble(7),ToPCV.GetDouble(8)));
    PosMen << QVector3D(ToPCV.GetDouble(0),ToPCV.GetDouble(1),ToPCV.GetDouble(2));
    VeloMen << QVector3D(ToPCV.GetDouble(3),ToPCV.GetDouble(4),ToPCV.GetDouble(5));
    AccMen << QVector3D(ToPCV.GetDouble(6),ToPCV.GetDouble(7),ToPCV.GetDouble(8));

}
