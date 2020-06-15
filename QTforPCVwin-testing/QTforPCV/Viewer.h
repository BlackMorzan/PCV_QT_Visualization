#ifndef VIEWER_HH
#define VIEWER_HH

#include <QGLViewer/qglviewer.h>
#include "globals.h"
/*!
 * \brief Ta klasa obsługuje OpenGL w UI
 *
 */

class Viewer : public QGLViewer
{
 public:
    /*!
     * \brief Konstruktor klasy
     */
  Viewer(QWidget *pParent = nullptr): QGLViewer(pParent) {}
 protected :

  /*!
   * \brief Ostatni wektor dotyczący rotacji, który został odaebrany
   */
  QVector3D *LastVector;
  /*!
   * \brief Tu są inicjalizowane wszystkie wartości potrzebne do pracy OpenGL
   *
   */

  virtual void init();

  /*!
   * \brief Tu są wykonywane funkce, które rysują obiekty w OpenGL
   *
   */
  virtual void draw();


public slots:
};

#endif
