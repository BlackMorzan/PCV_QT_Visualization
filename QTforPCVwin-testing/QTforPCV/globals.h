#ifndef GLOBALS_H
#define GLOBALS_H

#include <QVector3D>
#include <QDebug>

class Globals
{
      QVector3D LastRotation;

public:
    Globals() { LastRotation = QVector3D(); };

    public:

    void SetRotation(QVector3D tmp ) { LastRotation = tmp; qDebug() << "Set: " << LastRotation << endl;}
    QVector3D GetRotation() const { return LastRotation; qDebug() << "Get: " << LastRotation << endl;}
};


extern Globals Glob;



#endif // GLOBALS_H
