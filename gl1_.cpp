#include "gl1_.h"
#include <math.h>
#include <QDebug>

GL1_::GL1_(QWidget * parent):QGLWidget(parent){
	initWidget();
	initializeGL();
}

void GL1_::initializeGL(){
	glShadeModel(GL_SMOOTH);
	glClearColor(0,0,0,0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	qDebug() << "initializeGL";
}

void GL1_::initWidget(){
//	setGeometry( 400, 200, 640, 480 );
	//setWindowTitle(tr("opengl demo"));
}

void GL1_::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef( -1.5,  0.0, -6.0 );

	glBegin( GL_QUADS );
	glVertex3f(  -1.0,  1.0,  0.0 );
	glVertex3f(  1.0,  1.0,  0.0 );
	glVertex3f(  1.0, -1.0,  0.0 );
	glVertex3f( -1.0, -1.0,  0.0 );
	glEnd();

	glTranslatef(  3.0,  0.0,  0.0 );

	glBegin( GL_TRIANGLES );
//	qDebug() << "this is a paintGL test!";
	glVertex3f(  0.0,  1.0,  0.0 );
	glVertex3f( -1.0, -1.0,  0.0 );
	glVertex3f(  1.0, -1.0,  0.0 );
	glEnd();
}

void GL1_::resizeGL(int width,int height){
	if(0 == height) {
		height = 1;
	}

	glViewport(0, 0, (GLint)width, (GLint)height);
	qDebug() << "width"  << width;
	qDebug() << "height" << height;


	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	  //  gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);

	GLdouble aspectRatio = (GLfloat)width/(GLfloat)height;
	GLdouble zNear = 0.1;
	GLdouble zFar = 100.0;

	GLdouble rFov = 45.0 * 3.14159265 / 180.0;
	glFrustum( -zNear * tan( rFov / 2.0 ) * aspectRatio,
			   zNear * tan( rFov / 2.0 ) * aspectRatio,
			   -zNear * tan( rFov / 2.0 ),
			   zNear * tan( rFov / 2.0 ),
			   zNear, zFar );

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}

