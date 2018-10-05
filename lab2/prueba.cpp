//g++ prueba.cpp -lX11 -lGL -lGLU -lglut -g -Wall -O2 -o prueba
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>


void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,200.0,0.0,150.0);
}

void lineSegment()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINES);
  glVertex2i(50,50);
  glVertex2i(100,100);
  glEnd();
  glFlush();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Preuba");
  init();
  glutDisplayFunc(lineSegment);
  
  glutMainLoop();
  return 0;
}
