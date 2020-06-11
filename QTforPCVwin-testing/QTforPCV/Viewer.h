#ifndef VIEWER_HH
#define VIEWER_HH

#include <QGLViewer/qglviewer.h>
#include "globals.h"


class Viewer : public QGLViewer
{
 public:
  Viewer(QWidget *pParent = nullptr): QGLViewer(pParent) {}
 protected :
  QVector3D *LastVector;

  virtual void draw();
  virtual void init();


public slots:
};

#endif
