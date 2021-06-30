#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>
#include <time.h>

void init(void)
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.8, 0.8, 0.8, 1.0);
   glShadeModel (GL_SMOOTH);
     glEnable(GL_COLOR_MATERIAL);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   float x,y,z;
   float array[3]={-4.5,0.0,3.5};
   srand(time(NULL));
   for(int i=0; i<25; i++){
   x=array[rand()%3];
   y=array[rand()%3];
   z=array[rand()%3];
   if(x!=y && y!=z && x!=z)
    break;
   }
   glPushMatrix();
  glTranslatef(x,-0.5f,-6.0f);
  glRotatef(-75,1.0,0.0,0.0);

  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.75f,0.75f,2.0f,32,32);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(y,0.0f,-6.0f);
  glRotatef(20,1.0,0.0,0.0);
  glRotatef(20,0.0,1.0,0.0);

  glutSolidCube(2.0);
  glPopMatrix();
   glPushMatrix();
  glTranslatef(z,0.0f,-6.0f);
  glRotatef(30,1.0,0.0,0.0);
  glRotatef(10,0.0,1.0,0.0);
  glRotatef(-10,0.0,0.0,1.0);

  glutSolidCone(1.8,1.8,3,3);
  glPopMatrix();
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-3.5, 3.5, -3.5*(GLfloat)h/(GLfloat)w,
         3.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-3.5*(GLfloat)w/(GLfloat)h,
         3.5*(GLfloat)w/(GLfloat)h, -3.5, 3.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1920,1080);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
