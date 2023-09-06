#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <math.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <execution>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Field.h"

class Life
{
public:
	Field field;
	std::vector<std::vector<GLint>> Cells;
	std::vector<std::vector<GLdouble>> Colors;
	std::vector<GLdouble> color;
	GLint quantity;
	GLint Generation;
public:
	Life(Field field, int quantity, std::vector<GLdouble> color);
	Life(Field field, int quantity, int AppearingCubeWidth, std::vector<GLdouble> color);
	Life(Field field, int x, int y, int z, int width, std::vector<GLdouble> color);
	Life(Field field, int x, int y, int z, std::vector<GLdouble> color);
	

	void LifeInit();
	void NextGeneration();
	void glaider(int x, int y, int z);
	void displayGeneration(double WIDTH, double HEIGHT); 
	void console();
	int quantityNeighbour(GLint x, GLint y, GLint z, std::vector<std::vector<GLint>> OldCells);
	bool isContain(GLint x, GLint y, GLint z, std::vector<std::vector<GLint>> OldCells);

};
