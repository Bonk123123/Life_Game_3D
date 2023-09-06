#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "StrokePixel.h"

#include "Pixel.h"



class Field
{
public:
	GLdouble x;
	GLdouble y;
	GLdouble z;
	GLint width;
	GLdouble pixelLineWidth;
	GLdouble cellWidth;
	GLint cellsLength;
	std::vector<std::vector<GLdouble>> vertCells;
	GLdouble* color;

public:
	Field();
	Field(GLdouble x, GLdouble y, GLdouble z, GLint width, GLdouble pixelLineWidth, GLdouble cellWidth, GLdouble color[3]);

	void FillPixel(GLint x, GLint y, GLint z, GLdouble side, std::vector<GLdouble> color);
	bool HavePixel(GLint x, GLint y, GLint z);
	void Init();

	
};

