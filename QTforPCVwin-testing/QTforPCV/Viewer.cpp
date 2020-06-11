#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <QVector3D>
#include <cmath>
#include <QDebug>

#include "Viewer.h"
#include "Threading.h"


using namespace std;

inline
double Deg2Rad(double Ang_deg)
  { return Ang_deg*M_PI/180; }




#define ANG_STEP_deg 10

/*!
 * Tworzy pas o zadanym rozmiarze
 */
void GLBelt( double Size)
{

    glScalef( Size, Size, Size*2 );

    float   x_new_z_new;
    float   y_new_z_new;

    float   radius_new;
    float   sn, cs;


    radius_new = 1;
    sn = 0;  cs = 1;

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.6,  0.6,  0.6);

    for (double Azim_deg = 0; Azim_deg <= 360; Azim_deg += ANG_STEP_deg)
    {
        sn = sin(Deg2Rad(Azim_deg));
        cs = cos(Deg2Rad(Azim_deg));
        x_new_z_new = radius_new*cs;
        y_new_z_new = radius_new*sn;

        glNormal3f( x_new_z_new, y_new_z_new,  0);  glVertex3f( x_new_z_new, y_new_z_new,  0 );
        glNormal3f(x_new_z_new, y_new_z_new,  0);   glVertex3f( x_new_z_new, y_new_z_new,  1 );
    }

    glEnd();
}

/*!
 * Tworzy koło o zadanym rozmiarze
 */
void GLCircle( double Size)
{
    //Translate

    glScalef( Size, Size, Size );

    int x=0, y=0;
    float twicePi = 2*3.142;

    float   radius_new;

    radius_new = 1.0075;
    glBegin(GL_TRIANGLE_FAN);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3f(0.6,  0.6,  0.6);

    glVertex2f(0, 0); // center of circle
    for (int i = 0; i <= 20; i++)
        glVertex2f ((x + (radius_new * cos(i * twicePi / 20))), (y + (radius_new * sin(i * twicePi / 20))));

    glEnd();
}

void GLPlane( double Size )
{

    glScalef( Size, Size, Size );

    int x=0, y=0;
    float twicePi = 2*3.142;

    float   radius_new;

    radius_new = 5;
    glTranslatef(0, 0, -0.2);

    glBegin(GL_TRIANGLE_FAN);
    //blending?
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(0.1,  0.1,  0.1);

    glVertex2f(0, 0); // center of circle
    for (int i = 0; i <= 20; i++)
        glVertex2f ((x + (radius_new * cos(i * twicePi / 20))), (y + (radius_new * sin(i * twicePi / 20))));

    glEnd();
}




#define SLIDER2RAD(x) static_cast<float>(sin(M_PI*2*ScnParams.Get##x##_Light_deg()/180))


void Viewer::draw()
{
    double x=0, y=0, z=0;
    QVector3D cos(x, y, z);
        ///////////////////////////////////
     GLfloat Light1_Position[] = { 3, 3, 3, 0.0 };

        ///////////////////////////////////
     glLightfv(GL_LIGHT0, GL_POSITION, Light1_Position);

     glScalef( 0.5, 0.5, 0.5 );
        ///////////////////////////////////
     GLPlane(1);

     glTranslatef(0, 0, 4);

     QVector3D tmp = Glob.GetRotation();
     //qDebug() << "Rotacja" << tmp << endl;


     glRotatef(tmp.z(), 1, 0, 0);
     //qDebug() << Glob.GetRotation().x() << " fajne" << endl;
     glRotatef(-tmp.y(), 0, 1, 0);
     glRotatef(tmp.x(), 0, 0, 1);

     GLBelt(1);
     GLCircle(1);

     update();


}

void Viewer::init()
{
  restoreStateFromFile();

  GLfloat Light1_Position[] = { 1.0, 1.0, 1.0, 0.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, Light1_Position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  //help();
}
