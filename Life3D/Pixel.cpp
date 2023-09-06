#include "Pixel.h"

Pixel::Pixel(GLdouble x, GLdouble y, GLdouble z, GLdouble side, std::vector<GLdouble> color)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->side = side;
	//this->color = color;

	//cube
	// side
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(x, y, z);
	glVertex3f(x + side, y, z);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x, y + side, z);
	glEnd();
	// side


	// side
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(x, y + side, z);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x + side, y + side, z + side);
	glVertex3f(x, y + side, z + side);
	glEnd();
	// side


	// side
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x + side, y, z);
	glVertex3f(x + side, y, z + side);
	glVertex3f(x + side, y + side, z + side);
	glEnd();
	// side


	// side
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(x, y, z);
	glVertex3f(x + side, y, z);
	glVertex3f(x + side, y, z + side);
	glVertex3f(x, y, z + side);
	glEnd();
	// side


	// side
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(x, y, z + side);
	glVertex3f(x + side, y, z + side);
	glVertex3f(x + side, y + side, z + side);
	glVertex3f(x, y + side, z + side);
	glEnd();
	// side


	// side
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + side);
	glVertex3f(x, y + side, z + side);
	glVertex3f(x, y + side, z);
	glEnd();
	// side





	glLineWidth(0.5);
	// side
	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x, y, z);
	glVertex3f(x + side, y, z);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x, y, z);
	glVertex3f(x, y + side, z);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x, y + side, z);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x + side, y, z);
	glEnd();
	// side


	// side
	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x + side, y, z);
	glVertex3f(x + side, y, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x + side, y, z + side);
	glVertex3f(x, y, z + side);
	glEnd();
	// side


	// side
	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x, y + side, z);
	glVertex3f(x, y + side, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x + side, y + side, z);
	glVertex3f(x + side, y + side, z + side);
	glEnd();
	// side

	// side
	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x, y + side, z + side);
	glVertex3f(x + side, y + side, z + side);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x, y + side, z + side);
	glVertex3f(x, y, z + side);
	glEnd();
	// side

	// side
	glBegin(GL_LINES);
	glColor4f(0, 0, 0, 1);
	glVertex3f(x + side, y + side, z + side);
	glVertex3f(x + side, y, z + side);
	glEnd();
	// side

	//glutPostRedisplay();
}