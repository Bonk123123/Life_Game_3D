#include "StrokePixel.h"


StrokePixel::StrokePixel(GLdouble x, GLdouble y, GLdouble z, GLdouble side, GLdouble width, GLdouble color[4])
{
	this->side = side;

	this->x = x;
	this->y = y;
	this->z = z;

	this->w = width;

	glLineWidth(this->w);
	// side
	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x, y, z);
	glVertex3f(x + side, y, z);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x, y, z);
	glVertex3f(x, y + side, z);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x, y + side, z);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x + side, y, z);
	glEnd();
	// side


	// side
	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x + side, y, z);
	glVertex3f(x + side, y, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x + side, y, z + side);
	glVertex3f(x, y, z + side);
	glEnd();
	// side


	// side
	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x, y + side, z);
	glVertex3f(x, y + side, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x + side, y + side, z + side);
	glEnd();
	// side

	// side
	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x, y + side, z + side);
	glVertex3f(x + side, y + side, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x, y + side, z + side);
	glVertex3f(x, y, z + side);
	glEnd();
	// side

	// side
	glBegin(GL_LINES);
	glColor4f(color[0], color[1], color[2], color[3]);
	glVertex3f(x + side, y + side, z + side);
	glVertex3f(x + side, y, z + side);
	glEnd();
	// side


	//glutPostRedisplay();
}