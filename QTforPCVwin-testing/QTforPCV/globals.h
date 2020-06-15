#ifndef GLOBALS_H
#define GLOBALS_H

#include <QVector3D>
#include <QDebug>
/*!
 * \brief ta klasa przechowuje wartości globalne
 *
 * Wartości globalne są wykorzystywane do komunikacji z klasami OpenGL w UI
 */

class Globals
{
    /*!
       * \brief Wartość przechowuje kąt , o który ma się obrócić renderowany obiekt
       */
      QVector3D LastRotation;

public:
      /*!
         * \brief Inicjalizacja kąta (0,0,0)
         */
    Globals() { LastRotation = QVector3D(); };

    public:

    /*!
       * \brief Setter dla kąta
       */
    void SetRotation(QVector3D tmp ) { LastRotation = tmp; qDebug() << "Set: " << LastRotation << endl;}
    /*!
       * \brief getter dla kąta
       */
    QVector3D GetRotation() const { return LastRotation; qDebug() << "Get: " << LastRotation << endl;}
};


extern Globals Glob;



#endif // GLOBALS_H
