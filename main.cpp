/*
Tugas grafkom (revisi)
kelompok 5 : Yulius angga E.P (10108429)
             Imam ashadi (10108436)
             Ghea ratimanjari (10108449)
             R. Idham Aziz Marlin (10108465)

- tekan bawah untuk mundur
- tekan atas untuk maju
- tekan x untuk memutar objek kebawah (arah x)
- tekan z untuk memutar objek kesamping (arah z)
- tekan y untuk memutar objek kesamping (arah y)
*/

#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

using namespace std;

int w=900, h=600, z=0;
int x1=0, y1=0, sudut=0, z1=0, skalaX=0, skalaY=0;

void Init()
{
     glClearColor(0,0,0,1);
     glEnable(GL_DEPTH_TEST);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0,(GLdouble) w/(GLdouble) h, 1.0,300.0);
     glMatrixMode(GL_MODELVIEW);
}

void objek3d(void)
{
     glClearColor(0,0,0,1);
     glLoadIdentity();
     glTranslatef(0,0,z);
     glRotatef(sudut,x1,y1,z1);

     glPushMatrix();
     glScaled(0.8,0.04,0.8);
     glTranslatef(0.0,-30.2,0.0);
     glutSolidCube(7.0);
     glPopMatrix();

     glTranslatef(0.0,-.6,0.0);
     glutSolidCube(2.0);

     glPushMatrix();
     glScaled(0.8,1.0,0.8);
     glTranslatef(0.0,1.5,0.0);
     glutSolidSphere(0.8,80,120);
     glPopMatrix();
 
     glTranslatef(0.0,1.0,0.0);
     glScaled(1.2,0.25,1.2);
     glutSolidCube(0.9);
 
     glPushMatrix();
     glScaled(0.03,0.5,0.03);
     glTranslatef(0.0,10.8,0.0);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(2,-1.9,2);
     glScaled(.2,10.5,.2);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(2,0.8,2);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-2,-1.9,2);
     glScaled(.2,10.5,.2);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-2,0.8,2);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-2,-1.9,-2);
     glScaled(.2,10.5,.2);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-2,0.8,-2);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(2,-1.9,-2);
     glScaled(.2,10.5,.2);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();
  
     glPushMatrix();
     glTranslated(2,0.8,-2);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();
 
     glPushMatrix();
     glTranslated(0.6,-0.5,0.6);
     glScaled(.2,11.5,.2);
     glutSolidSphere(0.2,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(0.6,0.5,0.6);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(0.6,-0.5,-0.6);
     glScaled(.2,11.5,.2);
     glutSolidSphere(0.2,80,120);
     glPopMatrix();

     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glPopMatrix();

     glPushMatrix();
     glTranslated(-0.6,-0.5,-0.6);
     glScaled(.2,11.5,.2);
     glutSolidSphere(0.2,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-0.6,0.5,-0.6);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-0.6,-0.5,0.6);
     glScaled(.2,11.5,.2);
     glutSolidSphere(0.2,80,120);
     glPopMatrix();

     glPushMatrix();
     glTranslated(-0.6,0.5,0.6);
     glScaled(0.3,1.5,0.3);
     glutSolidSphere(0.4,80,120);
     glPopMatrix();
     glutSwapBuffers();
}

void resize(int w1,int h1)
{
     glViewport(0,0,w1,h1);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
}

void fungsiKeyboard(unsigned char key, int x, int y)
{
     if (key =='s') z+=5;
        else if (key == 'x') 
        {
             x1=1;
             y1=0;
             z1=0;
             sudut+=10;
        }
        else if (key == 'y') 
        {
             y1=1;
             x1=0;
             z1=0;
             sudut+=-10;
        }
        else if (key == 'z') 
        {
             y1=0;
             x1=0;
             z1=1;
             sudut+=-10;
        }
}

void fungsiSpecialKeyboard(int key, int x, int y)
{
     switch(key)
     {
         case GLUT_KEY_UP:
         z+=5;
         break;
         case GLUT_KEY_DOWN:
         z-=5;
         break;
     }
}

void setMaterial()
{
    GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f};
    GLfloat mat_diffuse[] = {0.6f,0.6f,0.6f,1.0f};
    GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[] = {50.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
}


void setLighting()
{
    GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};
    GLfloat light_position[] = {2.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50,timer,0);
}

void displayObjek()
{
     setMaterial();
     setLighting();
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     objek3d();
     glFlush();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Objek 3d");
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
    glutDisplayFunc(displayObjek);
    glutReshapeFunc(resize);
    glutKeyboardFunc(fungsiKeyboard);
    glutSpecialFunc(fungsiSpecialKeyboard);
    glutTimerFunc(1,timer,0);
    Init();  
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glViewport(0,0,640,480);
    glutMainLoop();
}

