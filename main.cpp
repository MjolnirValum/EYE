//
//  main.cpp
//  Projection-Matrix---Lab 2.1
//
//  Created by Clayton C Johnsen on 2/21/20.
//  Copyright © 2020 Clayton C Johnsen. All rights reserved.
//

#include <iostream>
#define GL_SILENCE_DEPRECATION
#include<GLUT/GLUT.h>

void display1(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    
    glBegin(GL_LINES);
        glVertex2f(-0.5, 0.0);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.0, -0.5);
        glVertex2f(0.0, 0.5);
    glEnd();
    
    glFlush();
}



int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("All Too Much Lab");
    glutDisplayFunc(display1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}
