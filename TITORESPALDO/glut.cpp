#define GLUT_DISABLE_ATEXIT_HACK

#include <iostream>
#include <math.h>
#include <cmath>
#include<GL/glut.h>
#include "quadtree.h"
#define KEY_ESC 27
using namespace std;

vector<string> splitString(string str){
    vector<string>vect;
    string word;
    stringstream stream(str);
    while( getline(stream, word, ',') )
        vect.push_back(word);
    return vect;
}


bool ial = false;

Quadtree *qt;
vector<Punto> Ra;

double radio=0,calx,caly,centrox,centroy;

void adaptRawPoint(int &x,int &y)
{
	x = x-300;
	y = 300-y;
}

//dibuja un simple gizmos

void displayGizmo()
{
	glBegin(GL_LINES);
        glColor3d(0,255,0);
		for(unsigned i=0;i<lineas.size();i++)
		{
			glVertex2d(lineas[i].first.x,lineas[i].first.y);
        	glVertex2d(lineas[i].second.x,lineas[i].second.y);
		}
    glEnd();

	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3d(255,0,0);
	for(unsigned i=0;i<puntos.size();i++)
	{	
		glVertex2d(puntos[i].x,puntos[i].y );
	}
	glEnd();

	/////////////////////////////////////////////
	if(Ra.size()!=0 and Ra[0].x == centrox and  Ra[0].y == centroy)
	{
		glPointSize(2);
		glBegin(GL_POINTS);
		glColor3d(0,0,225);
		for(unsigned i=0;i<Ra.size();i++)
		{	
			glVertex2d(Ra[i].x,Ra[i].y);
		}
		glEnd();
	}
	//////////////////////////////////////////////
	if(Ra.size()==2)
	{	
		if(radio == 0)
		{
			radio = sqrt((Ra[1].y-Ra[0].y)*(Ra[1].y-Ra[0].y)+(Ra[1].x-Ra[0].x)*(Ra[1].x-Ra[0].x));		
			centrox = Ra[0].x;
			centroy = Ra[0].y;
		}
		
		glBegin(GL_POINTS);
		glColor3d(1.0,0.5,0.0);
		for(double i=0;i<15;i=i+0.01)
		{
			calx = centrox + radio * cos(i);
			caly = centroy + radio * sin(i);
			glVertex2d(calx,caly);
		}
		glEnd();
		
	}
	//qt->PertCirculo(qt->m_head,Ra[0].x,Ra[0].y,radio);
	/*EPuntos.clear();
	qt->drawCirculo(centrox,centroy,radio);
	//qt->areaCirculo(centrox,centroy,radio);

	//qt->DistRadio(qt->m_head,radio,centrox,centroy);
	*/
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3d(1.0,1.0,0.0);
	/*
	for(unsigned i=0;i<EPuntos.size();i++)
	{	
		glVertex2d(EPuntos[i].x,EPuntos[i].y);
	}*/
	glEnd();
	
}

void OnMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		adaptRawPoint(x,y);
		Punto pt(x,y);

		qt->insert(pt);
		//qt->draw();
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		adaptRawPoint(x,y);
		Punto pt2(x,y);
		if(Ra.size() == 2)
			Ra.clear();
		Ra.push_back(pt2);
	}
}

void OnMouseMotion(int x, int y)
{ 
	adaptRawPoint(x,y);
	centrox = x;
	centroy = y;
}

void idle()
{ 
	glutPostRedisplay();
}

//funcion llamada a cada imagen
void glPaint(void) {
	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); //CAMBIO
	glLoadIdentity();
	//glOrtho(xmin,xmax,ymin,ymax,-1.0f,1.0f);
	glOrtho(-300.0f,300.0f,-300.0f,300.0f,-1.0f,1.0f);

	qt->draw();
	displayGizmo();

	//dldraw();
	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
}

//
//inicializacion de OpenGL
//
void init_GL(void) 
{
	//Color del fondo de la escena
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro

	//modo projeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

//en el caso que la ventana cambie de tama�o
GLvoid window_redraw(GLsizei width, GLsizei height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-300.0f,300.0f,-300.0f,300.0f,-1.0f,1.0f);
	//glOrtho(xmin,xmax,ymin,ymax,-1.0f,1.0f);
}

GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {
	case KEY_ESC:
		exit(0);
		break;

	default:
		break;
	}

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600,600); //tama�o de la ventana
	glutInitWindowPosition(400, 80); //posicion de la ventana
	glutCreateWindow("QuadTree"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint);
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);
	glutMouseFunc(&OnMouseClick);
	glutMotionFunc(&OnMouseMotion);
	glutIdleFunc(&idle);

	qt = new Quadtree(Punto(-300,-300),Punto(300,300),4);
	ifstream file("crime50k.csv");
    string str;
    int cont=0;
    while (std::getline(file, str))
    {
        vector<string>temp;
        string strtemp=str;
        temp=splitString(strtemp);
        float xtemp = ::atof(temp[18].c_str());
        float ytemp = ::atof(temp[19].c_str());
        qt->insert(Punto(xtemp,ytemp));
        if(cont%1000==0){
            cout<<"Vamos "<<cont<<endl;        
        }
        cont++;
    }    
	glutMainLoop();
	return 0;
}