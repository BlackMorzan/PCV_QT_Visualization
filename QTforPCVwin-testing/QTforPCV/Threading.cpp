#include "Threading.h"

thr_Connection_Menager ::thr_Connection_Menager (QObject *parent, bool b) :
    QThread(parent), Stop(b)
{}

void thr_Connection_Menager ::run()
{

    while (true)
    {
        if (ToPCV.Init()==0)
            break;
        this->msleep(500);
    }

    while(true)
    {
        /// Write from CustomConn to VectorList
        if (NewLog()!=0)
            break;
        if (current_vetor == 0)
            emit emit_Vetors(PosMen);
        else if (current_vetor == 1)
            emit emit_Vetors(VeloMen);
        else if (current_vetor == 2)
            emit emit_Vetors(RotMen);
        else
            qDebug() << "Something went wrong - unknown Vector to send" << endl;

        Glob.SetRotation(RotMen.last());
        this->msleep(3);
    }
}

void thr_Connection_Menager::decide_vector(int tmp)
{
    current_vetor = tmp;
}


int thr_Connection_Menager::NewLog()
{
    if (ToPCV.ReciveFullMessage()<0)
    {
        qDebug() << "Message not Recived - ConnMenager" << endl;
        return -1;
    }

    PosMen << QVector3D(ToPCV.GetDouble(0),ToPCV.GetDouble(1),ToPCV.GetDouble(2));
    VeloMen << QVector3D(ToPCV.GetDouble(3),ToPCV.GetDouble(4),ToPCV.GetDouble(5));
    RotMen << QVector3D(ToPCV.GetDouble(6),ToPCV.GetDouble(7),ToPCV.GetDouble(8));
    return 0;
}
