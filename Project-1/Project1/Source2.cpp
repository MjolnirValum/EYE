#include <iostream>
#include <L:\GRAPHICS\freeglut-2.8.1\include\GL\glut.h>
//#include <L:\GRAPHICS\freeglut-2.8.1\src\>
#define GL_SILENCE_DEPRECATION

void display() {
    glutWireTeapot(0.5); //use glut to draw wireframe teapot
    glFlush(); //force output
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); //initialize glut
    glutCreateWindow("Sad Fu Fighting App"); //makes window
    glutDisplayFunc(display); //registers the function "display" to draw window contents
    glutMainLoop(); //gives glut control over the program
    return 0;
}