#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <math.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class StrokePixel
{
private:
	GLdouble x;
	GLdouble y;
	GLdouble z;
	GLdouble side;
	GLdouble w;
public:
	StrokePixel(GLdouble x, GLdouble y, GLdouble z, GLdouble side, GLdouble width, GLdouble color[4]);
};

