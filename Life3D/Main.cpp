#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <ctime>
#include <math.h>
#include <iostream>
#include <vector>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <conio.h>
#endif

#include "StrokePixel.h"
#include "Pixel.h"
#include "Life.h"
#include "Field.h"


// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();
void mouseKeys();


// ----------------------------------------------------------
// Options | UI
// ----------------------------------------------------------
int fieldWidth = 15;
int LifesForRandom = 900;
int randomLifeCubeWidth = 10;
std::vector<double> color{ 1, 1, 1 };
double windowWidth = 700;
double windowHeight = 700;
int GenerationTime = 1000;




// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y = 45;
double rotate_x = -30;
double zoom = 1;
std::vector<GLint> direction{0, -1, 0};
GLdouble fieldColor[4]{ 1, 1, 1, 0.1 };
GLdouble snakeColor[3]{ 0, 1, 0 };

Field D4C(-0.5, -0.5, -0.5, fieldWidth, 2, 1 / double(fieldWidth), fieldColor);
//Life Aerosmith(D4C, 10, 10, 10, std::vector<GLdouble>{color[0], color[1], color[2]}); // глайдер
Life Aerosmith(D4C, LifesForRandom, randomLifeCubeWidth, std::vector<GLdouble>{color[0], color[1], color[2]});
//Life Aerosmith(D4C, LifesForRandom, std::vector<GLdouble>{color[0], color[1], color[2]});
//Life Aerosmith(D4C, 1, 1, 1, randomLifeCubeWidth, std::vector<GLdouble>{color[0], color[1], color[2]});


// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------

void display() {

    // Clear screen and Z-buffer
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    // Reset transformations
    glLoadIdentity();

    // Other Transformations
    // glTranslatef( 0.0, 0.0, 0.0 );      // Not included
    // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

    // Rotate when user changes rotate_x and rotate_y
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glScalef(zoom, zoom, zoom);
    

    
    //D4C.Init();
    Aerosmith.LifeInit();
    Aerosmith.displayGeneration(windowWidth, windowHeight);

    glFlush();
    glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {
    
    if (key == GLUT_KEY_RIGHT) 
    {
        rotate_y += 5;
    }

    else if (key == GLUT_KEY_LEFT) 
    {
        rotate_y -= 5;
    }

    else if (key == GLUT_KEY_UP) 
    {
        rotate_x += 5;
    }
        
    else if (key == GLUT_KEY_DOWN) 
    {
        rotate_x -= 5;
    }
    glutPostRedisplay();

}

void mouseKeys(int key, int state, int x, int y)
{
    if (key == GLUT_LEFT_BUTTON)
    {
        zoom += 0.1;
    }

    else if (key == GLUT_RIGHT_BUTTON)
    {
        zoom -= 0.1;
    }
}



void timer(int time)
{
    //snake.move(direction);
    //Aerosmith.console();
    
    Aerosmith.NextGeneration();
    glutPostRedisplay();
    glutTimerFunc(GenerationTime, timer, 0);
}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]) {
#pragma omp parallel
    {

        std::srand(std::time(nullptr));
        //  Initialize GLUT and process user parameters
        glutInit(&argc, argv);

        //  Request double buffered true color window with Z-buffer
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH * 2);

        // Create window
        glutInitWindowSize(windowWidth, windowHeight);
        glutCreateWindow("Snake");

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //  glDepthMask(GL_FALSE);
        //  Enable Z-buffer depth test
        glEnable(GL_DEPTH_TEST);

        // Callback functions
        glutDisplayFunc(display);

        glutSpecialFunc(specialKeys);
        glutMouseFunc(mouseKeys);
        glutTimerFunc(GenerationTime, timer, 0);

        //  Pass control to GLUT for events
        glutMainLoop();

        //  Return to OS
    }
    return 0;

}